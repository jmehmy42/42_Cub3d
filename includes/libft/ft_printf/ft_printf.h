/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin < marvin@42.fr >                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:49:10 by marvin            #+#    #+#             */
/*   Updated: 2024/12/11 15:26:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_putnbr(int nb, int put_space);
int	ft_unsigned(unsigned int n);
int	ft_hexadacimal(unsigned int num, char format);
int	ft_hex_conversion(uintptr_t num, char format);
int	ft_pointer(void *ptr, char format);

#endif
