/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sort_larg_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:48:23 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/11 14:43:50 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_find_smallest_index_pos(t_node *a)
{
    t_node *tmp = a;
    int pos = 0;
    int target_pos = 0;
    int min = 2147483647;

    while (tmp)
    {
        if (tmp->index < min)
        {
            min = tmp->index;
            target_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return target_pos;
}

int ft_find_target_pos(t_node *a, int b_index)
{
    t_node *tmp = a;
    int pos = 0;
    int target_pos = 0;
    int min_above = 2147483647;

    while (tmp)
    {
        if (tmp->index > b_index && tmp->index < min_above)
        {
            min_above = tmp->index;
            target_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    if (min_above != 2147483647)
        return target_pos;

    return ft_find_smallest_index_pos(a);
}

void ft_move_to_top(t_node **a, t_node **b, t_node *node)
{
    while (*b != node)
        rb(b);
    while ((*a)->pos != node->target_pos)
        ra(a);
}

int ft_find_min_val_pos(t_node *a)
{
    t_node *tmp = a;
    int min = tmp->index;
    int pos = 0, min_pos = 0;

    while (tmp)
    {
        if (tmp->index < min)
        {
            min = tmp->index;
            min_pos = pos;
        }
        tmp = tmp->next;
        pos++;
    }
    return min_pos;
}
