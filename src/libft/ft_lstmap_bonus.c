/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:34:17 by vsanz-ar          #+#    #+#             */
/*   Updated: 2022/12/28 12:42:37 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*node_aux;
	t_list	*heap_node;

	node = lst;
	if (node == NULL)
		return (NULL);
	heap_node = ft_lstnew(f(node->content));
	if (heap_node == NULL)
		return (NULL);
	node = node->next;
	while (node != NULL)
	{
		node_aux = ft_lstnew(f(node->content));
		if (node_aux == NULL)
		{
			ft_lstclear(&heap_node, del);
			return (NULL);
		}
		ft_lstadd_back(&heap_node, node_aux);
		node = node->next;
	}
	return (heap_node);
}
