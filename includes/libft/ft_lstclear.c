/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:28:31 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/18 19:13:31 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*str;

	if (!lst)
		return ;
	while (*lst)
	{
		str = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = str;
	}
	*lst = NULL;
}
