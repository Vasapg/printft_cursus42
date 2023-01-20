/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-ar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:55:36 by vsanz-ar          #+#    #+#             */
/*   Updated: 2022/12/28 14:49:15 by vsanz-ar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*node_aux;

	if (lst == NULL || *lst == NULL || *del == NULL)
		return ;
	if (lst != NULL)
	{
		node = *lst;
		while (node != NULL)
		{
			node_aux = node->next;
			del(node->content);
			free(node);
			node = node_aux;
		}
		*lst = NULL;
	}
}
