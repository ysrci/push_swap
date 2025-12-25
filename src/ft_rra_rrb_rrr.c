/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:29:19 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 16:48:52 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrrev_no(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || ! (*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **stack)
{
	rrrev_no(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack)
{
	rrrev_no(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrrev_no(stack_a);
	rrrev_no(stack_b);
	write(1, "rrr\n", 4);
}

void	rrrrev_no(t_node **stack_a, t_node **stack_b)
{
	rrrev_no(stack_a);
	rrrev_no(stack_b);
}
