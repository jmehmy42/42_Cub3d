/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy < jmehmy@student.42lisboa.com >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:35:57 by jmehmy            #+#    #+#             */
/*   Updated: 2024/11/25 13:59:14 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
int main (void)
{
	t_list	*node1, node2, node3;

	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));

	node->content = "Hello";
	node->next = node2;
	node2->content = "Coding";
	node->next = node3;
	node3->content = "World"
	node3->next = NULL;

	while (node1 != NULL)
	{
		printf ("%s\n", node1->content);
		node1=node1->next;
	}
	free(node1);
    free(node2);
    free(node3);
	return (0);
}
*/