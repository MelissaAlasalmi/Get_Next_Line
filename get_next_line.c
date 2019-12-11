/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasalm <malasalm@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:50:42 by malasalm          #+#    #+#             */
/*   Updated: 2019/12/09 10:38:15 by malasalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int	define_line(char **line, const int fd, char **fds)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (fds[fd][i] != '\n' && fds[fd][i] != '\0')
		i++;
	if (fds[fd][i] == '\n')
	{
		*line = ft_strsub(fds[fd], 0, i);
		temp = ft_strdup(fds[fd] + (i + 1));
		free(fds[fd]);
		fds[fd] = temp;
	}
	else if (fds[fd][i] == '\0')
	{
		*line = ft_strdup(fds[fd]);
		ft_strdel(&fds[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	*fds[MAX_FD];
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (fds[fd] != NULL)
		{
			temp = fds[fd];
			fds[fd] = ft_strjoin(fds[fd], buf);
			free(temp);
		}
		if (fds[fd] == NULL)
			fds[fd] = ft_strdup(buf);
		if (ft_strchr(fds[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	return (ret == 0 && (fds[fd] == NULL || fds[fd][0] == '\0')
			? 0 : define_line(line, fd, fds));
}
