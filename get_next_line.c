/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:11:41 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/21 13:31:06 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_next_buffer(char **save, int fd)
{
	char	*buffer;
	int		is_reading;

	while (!*save || !ft_strlen_char(*save, '\n'))
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		is_reading = read(fd, buffer, BUFFER_SIZE);
		if (is_reading <= 0)
		{
			free(buffer);
			return (0);
		}
		buffer[is_reading] = '\0';
		*save = ft_joinfree(*save, buffer);
		free(buffer);
	}
	return (ft_strlen_char(*save, '\n'));
}

void	stream_content(char **save, char **line, int eol_position)
{
	char	*new_save;
	int		i;

	i = -1;
	while (++i < eol_position)
	{
		(*line)[i] = (*save)[i];
	}
	(*line)[i] = '\0';
	if (!ft_strlen_char(*save, '\n'))
	{
		free(*save);
		*save = NULL;
	}
	else
	{
		new_save = ft_strdup(&(*save)[eol_position]);
		free(*save);
		*save = new_save;
	}
}

char	*get_next_line(int fd)
{
	static char	*save[12288];
	char		*line;
	int			i;

	if (fd < 0 || fd > 12288)
		return (NULL);
	i = read_next_buffer(&save[fd], fd);
	if (!i)
		i = ft_strlen_char(save[fd], '\0');
	if (!i)
	{
		free(save[fd]);
		return (NULL);
	}
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	stream_content(&save[fd], &line, i);
	return (line);
}
