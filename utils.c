/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:57:41 by tparratt          #+#    #+#             */
/*   Updated: 2024/02/13 13:57:41 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	free(str);
}

int	is_sorted(t_list **lst)
{
	t_list	*curr;

	curr = *lst;
	while (curr && curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	get_distance(t_list **lst, int index)
{
	t_list	*curr;
	int		distance;

	distance = 0;
	curr = *lst;
	while (curr)
	{
		if (curr->index == index)
			break ;
		distance++;
		curr = curr->next;
	}
	return (distance);
}

void	make_top(t_list **lst, int distance)
{
	t_list	*curr;
	int		tmp;

	if (distance == 0)
		return ;
	curr = *lst;
	tmp = ft_lstsize(curr) - distance;
	if (distance <= (ft_lstsize(curr) / 2))
	{
		while (distance-- > 0)
			ra(lst);
	}
	else
	{
		while (tmp-- > 0)
			rra(lst);
	}
}

void	free_lst(t_list **lst)
{
	t_list	*curr;
	t_list	*tmp;

	curr = *lst;
	while (curr)
	{
		tmp = curr;
		curr = curr->next;
		free(tmp);
	}
	free(lst);
}
