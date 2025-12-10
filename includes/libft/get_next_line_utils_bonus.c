/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:06:23 by jmehmy            #+#    #+#             */
/*   Updated: 2024/12/26 16:33:00 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	gnl_strlen(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

char	*gnl_strchr(char *str, int c)
{
	char	ch;

	ch = (char)c;
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (NULL);
}

char	*gnl_strjoin(char *line, char *buf)
{
	int		i;
	int		len1;
	int		len2;
	char	*result;

	len1 = gnl_strlen(line);
	len2 = gnl_strlen(buf);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (free(line), NULL);
	result[len1 + len2] = '\0';
	i = -1;
	while (++i < len1)
		result[i] = line[i];
	free(line);
	i = -1;
	while (++i < len2)
		result[len1 + i] = buf[i];
	i = -1;
	while (buf[len2 + ++i])
		buf[i] = buf[len2 + i];
	buf[i] = '\0';
	return (result);
}
