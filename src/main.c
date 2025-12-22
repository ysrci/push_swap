/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:17:43 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 10:17:45 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_check_args(argc, argv);
	stack_a = ft_build_stack_a(argc, argv);
	if (!stack_a)
		return (0);
	ft_has_duplicat(&stack_a);
	ft_is_sort(&stack_a);
	ft_sort_index(stack_a);
	if (ft_stack_size(stack_a) == 2)
		ft_sort_two(&stack_a);
	else if (ft_stack_size(stack_a) == 3)
		ft_sort_three(&stack_a);
	else if (ft_stack_size(stack_a) <= 5)
		ft_sort_five(&stack_a, &stack_b);
	else
		ft_sort_larg(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	return (0);
}
