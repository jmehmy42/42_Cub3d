/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:17:28 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/20 18:51:44 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
void to_upper (unsigned int i, char *c)
{
		if( *c>= 'a' && *c <= 'z' )
			*c= *c-32;
}
int	main(void)
{
	char	str[] = "hello, world!";

	ft_striteri(str, to_upper);
	printf("%s\n", str);
	return (0);
}
*/