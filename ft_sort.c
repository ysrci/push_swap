/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:44:13 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/10 17:40:57 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	ft_sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > z && y < z)
		ra(a);
	else if (x < y && x > z)
		rra(a);
	else if (x < y && y > z)
	{
		sa(a);
		ra(a);
	}
}
