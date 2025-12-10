/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:27:04 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/18 20:10:35 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dest;

	dest = (char *)malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(void)
{
	const char	*str = "Hello, World!";
	char		*duplicate;

	duplicate = ft_strdup(str);
	printf("%s OG string\n", str);
	printf("%s Duplicate string\n", duplicate);
	free(duplicate);
	return (0);
}*/
