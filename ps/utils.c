/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:07:51 by afahs             #+#    #+#             */
/*   Updated: 2025/06/16 17:19:27 by afahs            ###   ########.fr       */
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

int	is_valid(char *s)
{
	int		i;
	long	n;

	i = 1;
	if (!s)
		return (0);
	if (!(s[0] == '-' || s[0] == '+') && !(s[0] >= '0' && s[0] <= '9'))
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

int	check_dups(char **s, int size)
{
	long	*n;
	int		i;
	int		j;

	n = malloc(size * sizeof(long));
	i = 0;
	while (s[i])
	{
		n[i] = ft_atol(s[i]);
		i++;
	}
	i = 0;
	while (n[i])
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

t_stack	*parse_args(int c, char **v)
{
	int		i;
	t_stack	*s;
	long	*n;

	i = 0;
	while (v[i])
	{
		if (!is_valid(v[i]))
			return (NULL);
		i++;
	}
	if (!check_dups(v, c))
		return (NULL);
	i = 0;
	s = malloc(c * sizeof(t_stack));
	if (!n)
		return (NULL);
	while (v[i])
	{
		s
	}
	
	
}
