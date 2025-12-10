/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:34:23 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/16 17:20:47 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*str;

	if (!lst)
		return (NULL);
	str = lst;
	while (str->next)
		str = str->next;
	return (str);
}
