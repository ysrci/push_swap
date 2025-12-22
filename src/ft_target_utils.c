/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_target_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:23:03 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 10:46:15 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_index(t_node *stack)
{
	int	min;

	min = stack->index;
	while (stack)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	ft_get_position(t_node *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

int	ft_get_target_pos(t_node *a, int b_index)
{
	int		pos;
	int		target_pos;
	int		closest;
	t_node	*tmp;

	target_pos = 0;
	closest = INT_MAX;
	pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < closest)
		{
			closest = tmp->index;
			target_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (closest == INT_MAX)
		target_pos = ft_get_position(a, ft_get_min_index(a));
	return (target_pos);
}
