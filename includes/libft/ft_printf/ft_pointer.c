/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin < marvin@42.fr >                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:17:48 by marvin            #+#    #+#             */
/*   Updated: 2024/12/11 15:27:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *ptr, char format)
{
	uintptr_t	num;
	int			count;

	count = 0;
	num = (uintptr_t)ptr;
	if (num == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_hex_conversion(num, format);
	}
	return (count);
}
