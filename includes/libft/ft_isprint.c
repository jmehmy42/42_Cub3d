/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:29:31 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/16 17:20:10 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	int c1 = 65;
	int c2 = 31;

	if (ft_isprint(c1))
		printf("%d is a printable character.\n", c1);
	else
		printf("%d is not a printable character.\n", c1);

	if (ft_isprint(c2))
		printf("%d is a printable character.\n", c2);
	else
		printf("%d is not a printable character.\n", c2);

	return (0);
}*/