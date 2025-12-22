/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:28:43 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 15:49:58 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_no(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || ! *stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	*stack = first->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_node **stack)
{
	r_no(stack);
	write(1, "ra\n", 3);
}

void	rb(t_node **stack)
{
	r_no(stack);
	write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	r_no(stack_a);
	r_no(stack_b);
	write(1, "rr\n", 3);
}

void	rr_no(t_node **stack_a, t_node **stack_b)
{
	r_no(stack_a);
	r_no(stack_b);
}