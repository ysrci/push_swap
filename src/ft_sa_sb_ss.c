/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:29:43 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 15:56:06 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_no(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || ! (*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack)
{
	s_no(stack);
	write(1, "sa\n", 3);
}

void	sb(t_node **stack)
{
	s_no(stack);
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	s_no(stack_a);
	s_no(stack_b);
	write(1, "ss\n", 3);
}

void	ss_no(t_node **stack_a, t_node **stack_b)
{
	s_no(stack_a);
	s_no(stack_b);
}