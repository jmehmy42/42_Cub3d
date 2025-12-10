/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:24:15 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/25 14:07:13 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}
/*
int main (void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	node1->content = "coding";
	node1->next = node2;
	node2->content = "world";
	node2->next = NULL;
	node3->content = "Hello";
	ft_lstadd_front(&node1, node3);

	while (node1 != NULL)
	{
		printf ("%s\n", node1->content);
		node1=node1->next;
	}
	free(node1);
    free(node2);
    free(node3);
	return(0);
}
*/
