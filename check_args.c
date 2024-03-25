/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args(.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: tparratt <tparratt@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:07:42 by tparratt          #+#    #+#             */
/*   Updated: 2024/02/13 13:07:42 by tparratt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' && !num[1])
		return (0);
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	error_check(char **args, int i)
{
	long	tmp;

	tmp = ft_atol(args[i]);
	if (ft_strlen(args[i]) > 1 && args[i][0] == '0')
		ft_error("Error");
	if (ft_strlen(args[i]) == 0)
		ft_error("Error");
	if (!ft_isnum(args[i]))
		ft_error("Error");
	if (ft_duplicate(tmp, args, i))
		ft_error("Error");
	if (tmp == 0 && (ft_strncmp(args[i], "0", 1) != 0))
		ft_error("Error");
	if (tmp == -1 && (ft_strncmp(args[i], "-1", 2) != 0))
		ft_error("Error");
	if (tmp < -2147483648 || tmp > 2147483647)
		ft_error("Error");
}

void	check_args(int argc, char **argv)
{
	int		i;
	char	**args;	

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (args == NULL)
			exit(0);
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		error_check(args, i);
		i++;
	}
	if (argc == 2)
		free_split(args);
}
