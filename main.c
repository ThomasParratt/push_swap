/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:10:21 by tparratt          #+#    #+#             */
/*   Updated: 2024/02/13 13:10:21 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_lst(t_list **lst, int argc, char **argv)
{
	char	**args;
	int		i;
	t_list	*new;

	args = argv;
	i = 1;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (args == NULL)
			exit(0);
		i = 0;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		if (new == NULL)
			exit(0);
		ft_lstadd_back(lst, new);
		i++;
	}
	index_lst(lst);
	if (argc == 2)
		free_split(args);
}

static void	sort_lst(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) <= 5)
		simple_sort(lst_a, lst_b);
	else
		radix_sort(lst_a, lst_b);
}

int	main(int argc, char **argv)
{
	t_list	**lst_a;
	t_list	**lst_b;

	if (argc < 2)
		return (-1);
	check_args(argc, argv);
	lst_a = (t_list **)malloc(sizeof(t_list));
	if (lst_a == NULL)
		exit(0);
	lst_b = (t_list **)malloc(sizeof(t_list));
	if (lst_b == NULL)
		exit(0);
	*lst_a = NULL;
	*lst_b = NULL;
	init_lst(lst_a, argc, argv);
	if (is_sorted(lst_a))
	{
		free_lst(lst_a);
		free_lst(lst_b);
		return (0);
	}
	sort_lst(lst_a, lst_b);
	free_lst(lst_a);
	free_lst(lst_b);
	return (0);
}
