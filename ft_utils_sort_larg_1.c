/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sort_larg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:29:25 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/11 11:44:57 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_index(t_node *stack)
{
	t_node	*ptr;
	t_node	*tmp;

	ptr = stack;
	while (ptr)
	{
		ptr->index = 0;
		ptr = ptr->next;
	}
	ptr = stack;
	while (ptr)
	{
		tmp = stack;
		while (tmp)
		{
			if (ptr->value > tmp->value)
				ptr->index++;
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}

void	ft_update_positions(t_node *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos++;
		stack = stack->next;
	}
}

void	ft_calculate_cost(t_node *a, t_node *b)
{
	t_node *tmp_b;
	int size_a;
	int size_b;

	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
	tmp_b = b;
	while (tmp_b)
	{
		tmp_b->target_pos = ft_find_target_pos(a, tmp_b->index);
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->cost_a > size_a / 2)
			tmp_b->cost_a -= size_a;
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->cost_b > size_b / 2)
			tmp_b->cost_b -= size_b;
		tmp_b = tmp_b->next;
	}
}

void	ft_execute_cheapest_move(t_node **a, t_node **b)
{
	t_node *tmp;
	t_node *cheapest;
	int min_cost;

	tmp = *b;
	cheapest = tmp;
	min_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
	while (tmp)
	{
		if ((abs(tmp->cost_a) + abs(tmp->cost_b)) < min_cost)
		{
			min_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	ft_move_to_top(a, b, cheapest);
	pa(a, b);
}

void	ft_final_rotation(t_node **a)
{
	int min_pos;

	min_pos = ft_find_min_val_pos(*a);
	if (min_pos > ft_stack_size(*a) / 2)
		min_pos -= ft_stack_size(*a);
	while (min_pos > 0)
	{
		ra(a);
		min_pos--;
	}
	while (min_pos < 0)
	{
		rra(a);
		min_pos++;
	}
}
