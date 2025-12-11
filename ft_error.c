/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:39:47 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/10 17:27:48 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_is_valid_num(char *s, int len)
{
	long	num;
	int		sign;
	int		i;

	if (len == 0)
		return (0);
	i = 0;
	num = 0;
	sign = 1;
	i = ft_check_sign(s[i], &sign);
	if (i >= len)
		return (0);
	while (i < len)
	{
		if (!ft_isdigit(s[i]))
			return (0);
		num = num * 10 + (s[i] - '0');
		if (!ft_check_digit_range(num, sign))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	int		len;
	char	*s;

	i = 1;
	while (i < argc)
	{
		s = argv[i];
		while (*s)
		{
			ft_skip_spaces(&s);
			if (!*s)
				break ;
			len = ft_get_num_len(s);
			if (!ft_is_valid_num(s, len))
				ft_error_exit();
			s += len;
		}
		i++;
	}
}

int	ft_is_duplicate(t_node *stack, t_node **stack_a)
{
	t_node	*node1;
	t_node	*node2;

	node1 = stack;
	while (node1->next)
	{
		node2 = node1->next;
		while (node2)
		{
			if (node1->value == node2->value)
			{
				ft_free_stack(stack_a);
				ft_error_exit();
			}
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (0);
}
