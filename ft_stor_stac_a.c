/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stor_stac_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 20:26:01 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/07 11:33:00 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*stack = NULL;
}

void	ft_free_array(char	**array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_exit_error(t_node **stack, char **array)
{
	ft_free_stack(stack);
	ft_free_array(array);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_split(char	**split)
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

void	ft_fill_stack_a(t_node **stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;
	t_node	*new;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i]);
		if (!split)
			ft_exit_error(stack, NULL);
		j = 0;
		while (split[j])
		{
			new = ft_new_node((ft_atoi(split[j])));
			if (!new)
				ft_exit_error(stack, split);
			ft_add_back(stack, new);
			j++;
		}
		ft_free_split(split);
		i++;
	}
}
