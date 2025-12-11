/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:46:50 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/10 15:43:26 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_node	*stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_index(t_node *stack)
{
	t_node	*tmp1;
	t_node	*tmp2;
	int		idx;

	tmp1 = stack;
	while (tmp1)
	{
		idx = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp1->value > tmp2->value)
				idx++;
			tmp2 = tmp2->next;
		}
		tmp1->index = idx;
		tmp1 = tmp1->next;
	}
}
