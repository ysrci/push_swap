/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:14:52 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/07 11:22:09 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	int		sign;
	int		i;
	long	result;

	result = 0;
	sign = 1;
	i = ft_check_sign(s[0], &sign);
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}
