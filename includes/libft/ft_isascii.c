/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:22:52 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/16 10:37:43 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
		char c1 = 'J';
		char c2 = ';';
		
		if(ft_isascii(c1))
			printf("%c is an ASCII character \n", c1);
		else
			printf("%c is not an ASCII character \n", c1);

		if(ft_isascii(c2))
			printf("%c is a ASCII character \n", c2);
		else
			printf("%c is not an ASCII character \n", c2);

}*/