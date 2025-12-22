/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:27:54 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 15:40:32 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_no(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (!stack_b || ! *stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}
void	pa(t_node **stack_a, t_node **stack_b)
{
		p_no(stack_a, stack_b);
		write(1,"pa\n",3);
}
void	pb(t_node **stack_a, t_node **stack_b)
{
		p_no(stack_b, stack_a);
		write(1,"pb\n",3);
}
