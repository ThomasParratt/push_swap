/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:07:19 by tparratt          #+#    #+#             */
/*   Updated: 2024/02/13 14:07:19 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *curr);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *curr);

void	check_args(int argc, char **argv);
int		is_sorted(t_list **lst);
int		get_distance(t_list **lst, int index);
void	make_top(t_list **lst, int distance);
void	free_lst(t_list **lst);
void	free_split(char **str);
long	ft_atol(const char *str);
void	ft_error(char *msg);

void	radix_sort(t_list **lst_a, t_list **lst_b);
void	simple_sort(t_list **lst_a, t_list **lst_b);
void	index_lst(t_list **lst);
void	sort_5(t_list **lst_a, t_list **lst_b);

int		swap(t_list **lst);
int		push(t_list **lst_to, t_list **lst_from);
int		rotate(t_list **lst);
int		reverse_rotate(t_list **lst);
int		sa(t_list **lst_a);
int		sb(t_list **lst_b);
int		ss(t_list **lst_a, t_list **lst_b);
int		pa(t_list **lst_a, t_list **lst_b);
int		pb(t_list **lst_b, t_list **lst_a);
int		ra(t_list **lst_a);
int		rb(t_list **lst_b);
int		rr(t_list **lst_a, t_list **lst_b);
int		rra(t_list **lst_a);
int		rrb(t_list **lst_b);
int		rrr(t_list **lst_a, t_list **lst_b);

#endif