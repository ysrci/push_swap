/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:22:37 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 16:50:24 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_calc_total_cost(int cost_a, int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	if (cost_a <= 0 && cost_b <= 0)
	{
		if (cost_a < cost_b)
			return (ft_abs(cost_a));
		return (ft_abs(cost_b));
	}
	return (ft_abs(cost_a) + ft_abs(cost_b));
}

static void	ft_get_costs(t_node *a, int b_idx, int pos_b, int *costs)
{
	int	size_a;
	int	size_b;
	int	target;

	size_a = ft_stack_size(a);
	size_b = costs[2];
	target = ft_get_target_pos(a, b_idx);
	if (pos_b <= size_b / 2)
		costs[1] = pos_b;
	else
		costs[1] = pos_b - size_b;
	if (target <= size_a / 2)
		costs[0] = target;
	else
		costs[0] = target - size_a;
}

void	ft_find_cheapest(t_node *a, t_node *b, int *cost_a, int *cost_b)
{
	int	pos_b;
	int	cheapest;
	int	total;
	int	costs[3];

	cheapest = INT_MAX;
	pos_b = 0;
	costs[2] = ft_stack_size(b);
	while (b)
	{
		ft_get_costs(a, b->index, pos_b, costs);
		total = ft_calc_total_cost(costs[0], costs[1]);
		if (total < cheapest)
		{
			cheapest = total;
			*cost_a = costs[0];
			*cost_b = costs[1];
		}
		b = b->next;
		pos_b++;
	}
}
