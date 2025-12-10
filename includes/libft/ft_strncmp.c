/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:44:37 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/21 17:51:26 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] != '\0' && s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
/*int main ()
{
	char source[]="HelloWorld";
	char destination[]="Hello";
	int result = ft_strncmp(destination,source, 10);
	if (result == 0)
	{
		printf ("both are same %d\n", result);
	}
	if(result <0)
	{
		printf ("when s1 is less than s2 : %d\n", result);
	}
	if(result>0)
	{
		printf ("when s1 is greater than s2 : %d\n", result);
	}
	return (0);
}*/