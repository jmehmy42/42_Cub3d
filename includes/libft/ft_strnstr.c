/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:01:03 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/21 17:43:50 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (to_find[0] == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && (i + j) < len)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)(str + i));
		}
		i++;
	}
	return (NULL);
}
/*
int main (void)
{
	char str[] = "this is the way";
	char str1[] = "the";
	printf ("%s\n", ft_strnstr(str, str1, 16));
}*/
