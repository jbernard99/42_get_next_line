/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:12:00 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/20 10:53:14 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/* utils */
int		ft_strlen_char(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_joinfree(char *s1, char *s2);

/* get_next_line */
int		read_next_buffer(char **save, int fd);
void	stream_content(char **save, char **line, int eol_position);
char	*get_next_line(int fd);

#endif
