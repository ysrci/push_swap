/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bakk <yel-bakk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 10:14:42 by yel-bakk          #+#    #+#             */
/*   Updated: 2025/12/22 10:15:00 by yel-bakk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_word_count(char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != ' ' && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == ' ')
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_get_word(char *s)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (s[len] && s[len] != ' ')
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free_all(char **arr, int n)
{
	while (n > 0)
	{
		n--;
		free(arr[n]);
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char *s)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	res = (char **)malloc((ft_word_count(s) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != ' ')
		{
			res[i] = ft_get_word(s);
			if (!res[i])
				return (ft_free_all(res, i));
			i++;
			while (*s && *s != ' ')
				s++;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
