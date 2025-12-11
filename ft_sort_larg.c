/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_larg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:16:01 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/11 11:41:16 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_array(t_node *stack, int *arr)
{
	int i = 0;
	while (stack)
	{
		arr[i++] = stack->index;
		stack = stack->next;
	}
}

static void	compute_lis(int *arr, int size, int *dp, int *prev)
{
	int i = 0, j;

	while (i < size)
	{
		dp[i] = 1;
		prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

static int	*build_lis(int *arr, int *dp, int *prev, int size, int *lis_len)
{
	int i = 0, max_len = dp[0], max_idx = 0;
	int *lis;

	while (++i < size)
		if (dp[i] > max_len)
		{
			max_len = dp[i];
			max_idx = i;
		}
	*lis_len = max_len;
	lis = malloc(sizeof(int) * max_len);
	i = max_len - 1;
	while (max_idx != -1)
	{
		lis[i--] = arr[max_idx];
		max_idx = prev[max_idx];
	}
	return lis;
}

int	*ft_find_lis(t_node *stack, int size, int *lis_len)
{
	int *arr = malloc(sizeof(int) * size);
	int *dp = malloc(sizeof(int) * size);
	int *prev = malloc(sizeof(int) * size);
	int *lis;

	fill_array(stack, arr);
	compute_lis(arr, size, dp, prev);
	lis = build_lis(arr, dp, prev, size, lis_len);
	free(arr);
	free(dp);
	free(prev);
	return lis;
}


void	ft_push_out_lis(t_node **a, t_node **b, int *lis, int lis_len)
{
	t_node *tmp;
	int i;

	while (ft_stack_size(*a) > lis_len)
	{
		tmp = *a;
		i = 0;
		while (i < lis_len && tmp->index != lis[i])
			i++;
		if (i < lis_len)
			ra(a);
		else
			pb(a, b);
	}
}


void	ft_sort_large(t_node **a, t_node **b)
{
	int	size;
	int	*lis;
	int	lis_len;

	ft_assign_index(*a);
	size = ft_stack_size(*a);
	lis = ft_find_lis(*a, size, &lis_len);
	ft_push_out_lis(a, b, lis, lis_len);
	ft_sort_three(a);

	while (*b)
	{
		ft_update_positions(*a);
		ft_update_positions(*b);
		ft_calculate_cost(*a, *b);
		ft_execute_cheapest_move(a, b);
	}
	ft_final_rotation(a);
	free(lis);
}
