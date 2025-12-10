/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:01:29 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/25 13:03:50 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest > src)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		ft_memcpy(d, s, n);
	}
	return (dest);
}
/*int main()
{
	char src[]= "HELLO_world";
	char dest[]= "hello_WORLD";
	ft_memmove (dest, src, 5);
	printf ("%s\n", dest);
	return (0);
}
*/
