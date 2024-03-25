/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:16:25 by tparratt          #+#    #+#             */
/*   Updated: 2024/02/13 16:45:28 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **lst_to, t_list **lst_from)
{
	t_list	*tmp;
	t_list	*curr_to;
	t_list	*curr_from;

	if (ft_lstsize(*lst_from) == 0)
		return (-1);
	curr_to = *lst_to;
	curr_from = *lst_from;
	tmp = curr_from;
	curr_from = curr_from->next;
	*lst_from = curr_from;
	if (!curr_to)
	{
		curr_to = tmp;
		curr_to->next = NULL;
		*lst_to = curr_to;
	}
	else
	{
		tmp->next = curr_to;
		*lst_to = tmp;
	}
	return (0);
}

int	pa(t_list **lst_a, t_list **lst_b)
{
	if (push(lst_a, lst_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **lst_a, t_list **lst_b)
{
	if (push(lst_b, lst_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
