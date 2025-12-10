/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:39:23 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/25 14:53:30 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	number;

	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2147483648", 10);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		number = n + '0';
		write(fd, &number, 1);
	}
}
/*
int main()
{
    ft_putnbr_fd(12345, 1);

    int fd = open("output.txt", O_WRONLY | O_CREAT , 0644);
    ft_putnbr_fd(12345, fd);

    close(fd);

    return 0;
}
*/