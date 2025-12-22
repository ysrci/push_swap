/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:50:34 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 15:57:06 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}
static void	ft_move_stack(t_node **stack_a, t_node **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n"))
		s_no(stack_a);
	else if (ft_strcmp(line, "sb\n"))
		s_no(stack_b);
	else if (ft_strcmp(line, "ss\n"))
		ss_no(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n"))
		rrrev_no(stack_a);
	else if (ft_strcmp(line, "rrb\n"))
		rrrev_no(stack_b);
	else if (ft_strcmp(line, "rrr\n"))
		rrrrev_no(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n"))
		r_no(stack_a);
	else if (ft_strcmp(line, "rb\n"))
		r_no(stack_b);
	else if (ft_strcmp(line, "rr\n"))
		rr_no(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n"))
		p_no(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n"))
		p_no(stack_b, stack_a);
	else
	{
		free(line);
		ft_free_stack(stack_b);
		ft_free_stack(stack_a);
		ft_exit_error();
	}
}

void	ft_sort_bonus(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_move_stack(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	ft_is_sorted_bonus(t_node *stack)
{
	t_node	*tmp;

	if (!stack || !stack->next)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
