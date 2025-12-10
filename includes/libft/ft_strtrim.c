/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:23:50 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/21 17:22:42 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char(const char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && is_char(set, s1[start]))
		start++;
	while (end > start && is_char(set, s1[end - 1]))
		end--;
	str = (char *)malloc(end - start + 1);
	if (str == NULL)
		return (NULL);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*int main()
{
	char    *s1 = "abcToday is Sundayabc";
	char    *set= "abc";
	char *trim;
	trim = ft_strtrim(s1,set);
	printf("%s", trim);
	free(trim);
}*/