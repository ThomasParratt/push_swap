/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:34:44 by tparratt          #+#    #+#             */
/*   Updated: 2024/02/13 13:34:44 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_list **lst)
{
	t_list	*curr;
	int		max;
	int		max_bits;

	curr = *lst;
	max = curr->index;
	max_bits = 0;
	while (curr)
	{
		if (curr->index > max)
			max = curr->index;
		curr = curr->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **lst_a, t_list **lst_b)
{
	t_list	*curr_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	curr_a = *lst_a;
	size = ft_lstsize(curr_a);
	max_bits = get_max_bits(lst_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			curr_a = *lst_a;
			if (((curr_a->index >> i) & 1) == 1)
				ra(lst_a);
			else
				pb(lst_a, lst_b);
		}
		while (ft_lstsize(*lst_b) != 0)
			pa(lst_a, lst_b);
		i++;
	}
}
