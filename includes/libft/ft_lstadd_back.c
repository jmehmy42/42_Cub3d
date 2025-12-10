/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:21:31 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/25 14:12:25 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}
/*int main (void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	node1->content = "Hello";
	node1->next = node2;
	node2->content = "Coding";
	node2->next = NULL;
	node3->content = "World";
	ft_lstadd_back(&node1, node3);

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
