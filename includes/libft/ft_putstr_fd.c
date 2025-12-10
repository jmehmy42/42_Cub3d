/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:23:23 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/25 14:53:55 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

/*int	main(void)
{
	char	*str;
	int		fd;

	//str = "Hello\n world\n";
	//ft_putstr_fd(str, 1);
	fd = open("output.txt", O_CREAT | O_WRONLY , 0644);
	ft_putstr_fd("Hello\nworld\n", fd);

	close(fd);
	return (0);
}

int	main(void)
{
	int fd = open("output.txt", O_CREAT | O_WRONLY , 0644);
	ft_putstr_fd("hello world\n lisboba\n 42\n", fd);
	if (fd == -1)
	{
		write(2, "error", 5);
		return (1);
	}
	close(fd);

	return (0);
}
*/
