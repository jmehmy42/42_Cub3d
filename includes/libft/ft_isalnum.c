/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:25:32 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/16 10:35:07 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
		char c1 = 'J';
		char c2 = 'a';
		
		if(ft_isalnum(c1))
			printf("%c is an alphanumeric character \n", c1);
		else
			printf("%c is not an alphanumeric character \n", c1);

		if(ft_isalnum(c2))
			printf("%c is an aalphanumeric character \n", c2);
		else
			printf("%c is not an alphanumeric character \n", c2);
}*/