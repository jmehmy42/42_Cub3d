/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:50:21 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/25 12:10:07 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
		char c1 = 'J';
		char c2 = '4';

		if(ft_isalpha(c1))
			printf("%c\n", c1);
		else
			printf("%c\n", c1);

		if(ft_isalpha(c2))
			printf("%c\n", c2);
		else
			printf("%c\n", c2);
}*/