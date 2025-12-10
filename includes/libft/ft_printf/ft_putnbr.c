/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin < marvin@42.fr >                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:22:32 by marvin            #+#    #+#             */
/*   Updated: 2024/12/11 12:49:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int put_space)
{
	char	c;
	int		count;

	count = 0;
	if (nb >= 0 && put_space)
		count += write(1, " ", 1);
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (nb < 0 && nb != -2147483648)
	{
		count += write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		count += ft_putnbr(nb / 10, 0);
	c = nb % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}
