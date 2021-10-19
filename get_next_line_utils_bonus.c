/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernard <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:11:51 by jbernard          #+#    #+#             */
/*   Updated: 2021/10/19 10:11:53 by jbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_char(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!c)
		return (i);
	if (str[i] != c)
		return (0);
	else
		return (i + 1);
}

char	*ft_joinfree(char *to_free, char *to_add)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen_char(to_free, 0) + ft_strlen_char(to_add, 0) + 1;
	ret = malloc(sizeof(char) * len);
	if (!ret)
		return (0);
	i = 0;
	while (to_free && to_free[i])
	{
		ret[i] = to_free[i];
		i++;
	}
	free(to_free);
	while (*to_add)
		ret[i++] = *to_add++;
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	int		i;

	i = ft_strlen_char(str, 0);
	ret = malloc(sizeof(char) * i + 1);
	if (!ret)
		return (0);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}
