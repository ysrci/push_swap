/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_larg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:20:56 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 10:20:58 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	ft_move_cheapest(t_node **a, t_node **b)
{
	int	cost_a;
	int	cost_b;

	ft_find_cheapest(*a, *b, &cost_a, &cost_b);
	ft_do_rotations(a, b, &cost_a, &cost_b);
	pa(a, b);
}

static void	ft_push_to_b_smart(t_node **a, t_node **b, int size)
{
	int	pushed;
	int	range;

	pushed = 0;
	range = size / 5;
	if (range < 3)
		range = 3;
	while (ft_stack_size(*a) > 3)
	{
		if ((*a)->index <= pushed + range)
		{
			pb(a, b);
			if (ft_stack_size(*b) > 1 && (*b)->index < pushed + range / 2)
				rb(b);
			pushed++;
		}
		else
			ra(a);
	}
}

static void	ft_final_rotate(t_node **a)
{
	int	min_pos;
	int	size;

	min_pos = ft_get_position(*a, ft_get_min_index(*a));
	size = ft_stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			rra(a);
	}
}

void	ft_sort_larg(t_node **a, t_node **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (size <= 100)
	{
		while (size-- > 3)
			pb(a, b);
	}
	else
		ft_push_to_b_smart(a, b, size);
	ft_sort_three(a);
	while (*b)
		ft_move_cheapest(a, b);
	ft_final_rotate(a);
}
