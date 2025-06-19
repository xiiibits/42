/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:57:25 by afahs             #+#    #+#             */
/*   Updated: 2025/06/19 11:05:37 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	long	s;
	long	n;

	i = 0;
	s = 1;
	n = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * s);
}

long	*built_array(char **s, int size)
{
	long	*n;
	int		i;
	int		j;

	n = malloc(size * sizeof(long));
	if (!n)
		return (NULL);
	i = 0;
	while (s[i])
	{
		n[i] = ft_atol(s[i]);
		i++;
	}
	return (n);
}
