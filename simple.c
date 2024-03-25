/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:35:20 by tparratt          #+#    #+#             */
/*   Updated: 2024/02/13 13:35:20 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_list **lst, int val)
{
	t_list	*curr;
	int		min;

	curr = *lst;
	min = curr->index;
	while (curr->next)
	{
		curr = curr->next;
		if ((curr->index < min) && curr->index != val)
			min = curr->index;
	}
	return (min);
}

static void	sort_3(t_list **lst)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*lst)->index;
	middle = (*lst)->next->index;
	bottom = (*lst)->next->next->index;
	if (top < middle && middle > bottom && bottom > top)
	{
		sa(lst);
		ra(lst);
	}
	if (top > middle && middle < bottom && bottom > top)
		sa(lst);
	if (top < middle && middle > bottom && bottom < top)
		rra(lst);
	if (top > middle && middle < bottom && bottom < top)
		ra(lst);
	if (top > middle && middle > bottom && bottom < top)
	{
		sa(lst);
		rra(lst);
	}
}

static void	sort_4(t_list **lst_a, t_list **lst_b)
{
	int	distance;

	if (is_sorted(lst_a))
		return ;
	distance = get_distance(lst_a, get_min(lst_a, -1));
	if (distance == 1)
		ra(lst_a);
	else if (distance == 2)
	{
		ra(lst_a);
		ra(lst_a);
	}
	else if (distance == 3)
		rra(lst_a);
	if (is_sorted(lst_a))
		return ;
	pb(lst_a, lst_b);
	sort_3(lst_a);
	pa(lst_a, lst_b);
}

void	sort_5(t_list **lst_a, t_list **lst_b)
{
	int	distance;

	distance = get_distance(lst_a, get_min(lst_a, -1));
	if (distance == 1)
		ra(lst_a);
	else if (distance == 2)
	{
		ra(lst_a);
		ra(lst_a);
	}
	else if (distance == 3)
	{
		rra(lst_a);
		rra(lst_a);
	}
	else if (distance == 4)
		rra(lst_a);
	if (is_sorted(lst_a))
		return ;
	pb(lst_a, lst_b);
	sort_4(lst_a, lst_b);
	pa(lst_a, lst_b);
}

void	simple_sort(t_list **lst_a, t_list **lst_b)
{
	int	size;

	if (is_sorted(lst_a) || ft_lstsize(*lst_a) == 0
		|| ft_lstsize(*lst_a) == 1)
		return ;
	size = ft_lstsize(*lst_a);
	if (size == 2)
		sa(lst_a);
	else if (size == 3)
		sort_3(lst_a);
	else if (size == 4)
		sort_4(lst_a, lst_b);
	else if (size == 5)
		sort_5(lst_a, lst_b);
}
