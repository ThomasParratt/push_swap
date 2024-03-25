/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:16:08 by tparratt          #+#    #+#             */
/*   Updated: 2024/02/13 13:17:51 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_list **lst)
{
	t_list	*curr;
	t_list	*tail;

	if (ft_lstsize(*lst) < 2)
		return (-1);
	curr = *lst;
	tail = ft_lstlast(curr);
	*lst = curr->next;
	curr->next = NULL;
	tail->next = curr;
	return (0);
}

int	ra(t_list **lst_a)
{
	if (rotate(lst_a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_list **lst_b)
{
	if (rotate(lst_b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **lst_a, t_list **lst_b)
{
	if ((ft_lstsize(*lst_a) < 2) || (ft_lstsize(*lst_b) < 2))
		return (-1);
	rotate(lst_a);
	rotate(lst_b);
	ft_putendl_fd("rr", 1);
	return (0);
}
