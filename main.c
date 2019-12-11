/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasalm <malasalm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:35:43 by malasalm          #+#    #+#             */
/*   Updated: 2019/12/05 16:03:35 by malasalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	int i;

	i = 1;
	while (i < argc + 1)
	{
		fd = open(argv[i], O_RDONLY);
		i++;
	}
	fd = 3;
	while (fd < argc + 2)
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_putstr(line);
			ft_putchar('\n');
			free(line);
		}
		fd++;
	}
	close(fd);
	while(1);
	return (0);
}
