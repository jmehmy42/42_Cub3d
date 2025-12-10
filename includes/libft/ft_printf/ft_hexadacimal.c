/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadacimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin < marvin@42.fr >                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:13:57 by marvin            #+#    #+#             */
/*   Updated: 2024/12/11 15:27:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadacimal(unsigned int num, char format)
{
	int	count;

	count = 0;
	if (num == 0)
		count += write(1, "0", 1);
	else
		count += ft_hex_conversion(num, format);
	return (count);
}
