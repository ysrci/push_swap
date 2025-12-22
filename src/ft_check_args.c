/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:34:08 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 15:27:23 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_in_num(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (!str[i][j])
			return (0);
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_larg_num(char **str)
{
	int		i;
	long	num;

	i = 0;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

static void	ft_free_split(char	**split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_check_args(int argc, char **argv)
{
	char	**str;
	int		i;

	if (argc < 2)
		return ;
	i = 1;
	if (argv[1][0] == '\0' && !argv[2])
		ft_exit_error();
	while (i < argc)
	{
		str = ft_split(argv[i]);
		if (!str || !ft_in_num(str) || !ft_larg_num(str))
		{
			ft_free_split(str);
			ft_exit_error();
		}
		ft_free_split(str);
		i++;
	}
}
