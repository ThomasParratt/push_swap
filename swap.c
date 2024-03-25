/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:16:14 by tparratt          #+#    #+#             */
/*   Updated: 2024/03/18 10:54:36 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **lst)
{
	t_list	*curr;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*lst) < 2)
		return (-1);
	curr = *lst;
	next = curr->next;
	tmp_val = curr->value;
	//tmp_index = curr->index;
	curr->value = next->value;
	curr->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **lst_a)
{
	if (swap(lst_a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **lst_b)
{
	if (swap(lst_b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_list **lst_a, t_list **lst_b)
{
	if ((ft_lstsize(*lst_a) < 2) || (ft_lstsize(*lst_b) < 2))
		return (-1);
	swap(lst_a);
	swap(lst_b);
	ft_putendl_fd("ss", 1);
	return (0);
}
