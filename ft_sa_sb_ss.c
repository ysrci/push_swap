/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:00:15 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/11 14:58:32 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_only(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack)
{
	rotate_only(stack);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	rotate_only(stack);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	rotate_only(stack_a);
	rotate_only(stack_b);
	write(1, "ss\n", 3);
}
