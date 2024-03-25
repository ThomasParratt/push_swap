/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:08:24 by tparratt          #+#    #+#             */
/*   Updated: 2024/02/13 13:08:24 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **lst)
{
	t_list	*curr;
	t_list	*min;

	min = NULL;
	curr = *lst;
	if (curr)
	{
		while (curr)
		{
			if ((curr->index == -1) && (min == NULL
					|| curr->value < min->value))
				min = curr;
			curr = curr->next;
		}
	}
	return (min);
}

void	index_lst(t_list **lst)
{
	t_list	*curr;
	int		index;

	index = 0;
	curr = get_next_min(lst);
	while (curr)
	{
		curr->index = index++;
		curr = get_next_min(lst);
	}
}
