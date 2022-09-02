/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: algaspar <algaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:31:07 by algaspar          #+#    #+#             */
/*   Updated: 2022/09/02 17:31:28 by algaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_node	*last_node(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	lst_add_back(t_node **node, t_node *new)
{
	t_node	*last;

	if (node && new)
	{
		if (!*node)
		{
			*node = new;
		}
		else
		{
			last = last_node(*node);
			last->next = new;
		}
		new->next = NULL;
	}
}