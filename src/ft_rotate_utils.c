/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:24:17 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 10:24:19 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

static void	ft_rotate_both(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	int	n;

	if (*cost_a > 0 && *cost_b > 0)
	{
		n = min(*cost_a, *cost_b);
		while (n-- > 0)
		{
			rr(a, b);
			(*cost_a)--;
			(*cost_b)--;
		}
	}
	else if (*cost_a < 0 && *cost_b < 0)
	{
		n = min(-(*cost_a), -(*cost_b));
		while (n-- > 0)
		{
			rrr(a, b);
			(*cost_a)++;
			(*cost_b)++;
		}
	}
}

static void	ft_rotate_a_only(t_node **a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

static void	ft_rotate_b_only(t_node **b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

void	ft_do_rotations(t_node **a, t_node **b, int *cost_a, int *cost_b)
{
	ft_rotate_both(a, b, cost_a, cost_b);
	ft_rotate_a_only(a, cost_a);
	ft_rotate_b_only(b, cost_b);
}