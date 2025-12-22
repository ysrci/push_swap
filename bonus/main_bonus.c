/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:30:35 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 15:31:54 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	ft_sort_bonus(&stack_a, &stack_b);
	if (ft_is_sorted_bonus(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else if (!ft_is_sorted_bonus(stack_a) || stack_b != NULL)
		write(1, "KO\n", 3);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}