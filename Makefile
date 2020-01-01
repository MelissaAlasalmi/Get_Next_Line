# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malasalm <malasalm@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 10:08:13 by malasalm          #+#    #+#              #
#    Updated: 2019/12/05 16:05:57 by malasalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

all: $(NAME)
	
$(NAME):
	gcc -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	gcc -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	gcc -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

clean:
	@rm -f *.o

fclean: clean
	@rm -rf test_gnl

re: fclean all

.PHONY: all clean fclean re
