/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:18:15 by tparratt          #+#    #+#             */
/*   Updated: 2024/02/13 13:21:07 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_list **lst)
{
	t_list	*curr;
	t_list	*tail;

	if (ft_lstsize(*lst) < 2)
		return (-1);
	curr = *lst;
	tail = ft_lstlast(curr);
	while (curr)
	{
		if (curr->next->next == NULL)
		{
			curr->next = NULL;
			break ;
		}
		curr = curr->next;
	}
	tail->next = *lst;
	*lst = tail;
	return (0);
}

int	rra(t_list **lst_a)
{
	if (reverse_rotate(lst_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_list **lst_b)
{
	if (reverse_rotate(lst_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_list **lst_a, t_list **lst_b)
{
	if ((ft_lstsize(*lst_a) < 2) || (ft_lstsize(*lst_b) < 2))
		return (-1);
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
