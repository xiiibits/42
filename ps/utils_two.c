/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:57:25 by afahs             #+#    #+#             */
/*   Updated: 2025/06/19 11:57:33 by afahs            ###   ########.fr       */
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
	i = 1;
	while (i < size)
	{
		n[i] = ft_atol(s[i]);
		i++;
	}
	return (n);
}

int	is_valid(char *s)
{
	int		i;
	long	n;

	i = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	n = ft_atol(s);
	if (n > 2147483647 || n < -2147483648)
		return (0);
	return (1);
}

int	check_dups(long *n, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (n[i] == n[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
