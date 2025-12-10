/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:59:48 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/19 17:59:40 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char to_upper (unsigned int i, char c)
{
		if( i % 2 == 0 && c>= 'a' && c <= 'z' )
			c= c-32;
		return (c);
}
int main ()
{
	char str[]="abcdef";
	printf ( "%s", ft_strmapi(str, to_upper));
	return (0);
}*/