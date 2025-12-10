/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin < marvin@42.fr >                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:46:13 by marvin            #+#    #+#             */
/*   Updated: 2024/12/11 15:26:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	just_print(const char *format)
{
	write(1, format, 1);
	return (1);
}

int	ft_printf_checker(const char **format, va_list arg)
{
	int	len;
	int	put_space;

	len = 0;
	put_space = (*(*format - 1) == ' ');
	if (**format == '\0')
		return (len);
	else if (**format == '%')
		len += ft_print_char('%');
	else if (**format == 'c')
		len += ft_print_char(va_arg(arg, int));
	else if (**format == 's')
		len += ft_print_string(va_arg(arg, char *));
	else if (**format == 'd' || **format == 'i')
		len += ft_putnbr(va_arg(arg, int), put_space);
	else if (**format == 'u')
		len += ft_unsigned(va_arg(arg, unsigned int));
	else if (**format == 'x' || **format == 'X')
		len += ft_hexadacimal(va_arg(arg, unsigned int), **format);
	else if (**format == 'p')
		len += ft_pointer(va_arg(arg, void *), **format);
	else
		len += just_print(*format);
	return (len);
}

void	skip_space(const char **format)
{
	while (**format == ' ' || **format == '+' || **format == '-')
		(*format)++;
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	arg;

	len = 0;
	if (format == NULL)
		return (-1);
	va_start(arg, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			len++;
		}
		else
		{
			format++;
			skip_space(&format);
			len += ft_printf_checker(&format, arg);
		}
		format++;
	}
	va_end(arg);
	return (len);
}
/*#include <stdio.h>
int	main(void)
{
	char e = 'A';
	char *s = "Hello, World!";
	void *p = (void *)0xDEADBEEF;
	unsigned int u = 4294967295 ;  // Max value for a 32-bit unsigned int
	int d = -2147483648;

	ft_printf("Character:%c\n", e);
		printf("Character:%c\n", e);
	ft_printf("String:%s\n", s);
		printf("String:%s\n", s);
	ft_printf("Pointer:%p\n", p);
		printf("Pointer:%p\n", p);
	ft_printf("Unsigned int:%u\n", u);
		printf("Unsigned int:%u\n", u);
	ft_printf("Hexadecimal (lowercase): %x\n", u);
		printf("Hexadecimal (lowercase): %x\n", u);
	ft_printf("Hexadecimal (uppercase): %X\n", u);
		printf("Hexadecimal (uppercase): %X\n", u);
	ft_printf("Signed int:%  d\n", d);
		printf("Signed int:%  d\n", d);
	ft_printf("Signed int (as %i): %i\n", d, d);
		printf("Signed int (as %i): %i\n", d, d);
	ft_printf("Percentage:%%\n");
		printf("Percentage:%%\n");

	ft_printf("Integer: %d\n", 12345);
		printf("Integer: %d\n", 12345);
	ft_printf("Negative integer: %d\n", -6789);
		printf("Negative integer: %d\n", -6789);
	ft_printf("%d\n", 42);
		printf("%d\n", 42);
	ft_printf("Large integer: %d\n", 2147483647);
		printf("Large integer: %d\n", 2147483647);
	ft_printf("Small integer: %d\n", -2147483648);
		printf("Small integer: %ld\n", -2147483648);

	ft_printf("Signed int:  %  d\n", d);
			printf("Signed int:  %  d\n", d);
	ft_printf("%d\n", ft_printf(NULL));
		printf("%d\n", printf(NULL));

	char *ptr= NULL;
	ft_printf("%s\n", ptr);
		printf("%s\n", ptr);
	void *p1 = 0;
		ft_printf("Pointer:%p\n", p1);
		printf("Pointer:%p\n", p1);
	return (0);
}*/