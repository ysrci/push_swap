/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_stack_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:18:10 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 10:25:03 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static t_node	*ft_node_new(char *str)
{
	t_node	*node;

	node = ft_new_node(ft_atoi(str));
	if (!node)
		return (NULL);
	return (node);
}

static void	ft_add_token(t_node **stack, char *str)
{
	t_node	*node;

	node = ft_node_new(str);
	if (!node)
	{
		ft_free_stack(stack);
		ft_exit_error();
	}
	ft_add_back(stack, node);
}

static void	ft_add_arg(t_node **stack, char *arg)
{
	char	**split;
	int		j;

	split = ft_split(arg);
	if (!split)
	{
		ft_free_stack(stack);
		ft_exit_error();
	}
	if (!split[0])
	{
		free(split);
		return ;
	}
	j = 0;
	while (split[j])
	{
		ft_add_token(stack, split[j]);
		j++;
	}
	ft_free_split(split);
}

t_node	*ft_build_stack_a(int argc, char **argv)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		ft_add_arg(&stack, argv[i]);
		i++;
	}
	return (stack);
}
