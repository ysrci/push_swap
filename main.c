/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:34:09 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/11 11:57:42 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*tmp;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	ft_fill_stack_a(&stack_a, argc, argv);
	ft_is_duplicate(stack_a, &stack_a);
	if (ft_is_sorted(stack_a))
	{
		ft_free_stack(&stack_a);
		return (0);
	}
	ft_sort_index(stack_a);
	tmp = stack_a;
	while (tmp)
	{
		printf("|index| : [%d]  ->  |value|: [%d]\n", tmp->index, tmp->value);
		tmp = tmp->next;
	}
	if (ft_stack_size(stack_a) == 2)
		ft_sort_two(&stack_a);
	else if (ft_stack_size(stack_a) == 3)
		ft_sort_three(&stack_a);
	else
		ft_sort_large(&stack_a, &stack_b);
	tmp = stack_a;
	while (tmp)
	{
		printf("|index| : [%d]  ->  |value|: [%d]\n", tmp->index, tmp->value);
		tmp = tmp->next;
	}
	ft_free_stack(&stack_a);
	return (0);
}
