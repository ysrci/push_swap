/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:50:02 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/10 10:53:43 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_skip_spaces(char **s)
{
	while (**s == ' ' || **s == '\t')
		(*s)++;
}

int	ft_get_num_len(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != ' ' && s[len] != '\t')
		len++;
	return (len);
}

int	ft_check_sign(char c, int *sign)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_check_digit_range(long num, int sign)
{
	if (num * sign > INT_MAX || num * sign < INT_MIN)
		return (0);
	return (1);
}
