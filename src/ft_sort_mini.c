/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:20:18 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 10:20:21 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_node **a)
{
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

static int	ft_find_min_index_pos(t_node *stack)
{
	int		min_index;
	int		min_pos;
	int		pos;
	t_node	*tmp;

	min_index = stack->index;
	min_pos = 0;
	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

static void	ft_rotatr_to_top(t_node **stack, int pos)
{
	int	size;

	size = ft_stack_size(*stack);
	if (pos <= size / 2)
	{
		while (pos--)
			ra(stack);
	}
	else
	{
		while (pos++ < size)
			rra(stack);
	}
}

void	ft_sort_five(t_node **stack_a, t_node **stack_b)
{
	int	size;
	int	to_push;
	int	min_pos;

	size = ft_stack_size(*stack_a);
	to_push = size - 3;
	while (to_push--)
	{
		min_pos = ft_find_min_index_pos(*stack_a);
		ft_rotatr_to_top(stack_a, min_pos);
		pb(stack_a, stack_b);
	}
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b);
	}
}
