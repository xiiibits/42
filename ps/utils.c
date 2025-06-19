/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:07:51 by afahs             #+#    #+#             */
/*   Updated: 2025/06/19 11:05:40 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*

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
	n = built_array(v, c);
	if (!check_dups(n, c))
	{
		free(n);
		return (NULL);
	}
	i = 0;
	s = malloc(c * sizeof(t_stack));
	if (!n)
		return (NULL);
	while (v[i])
	{
		
	}
}

void	free_stack(t_stack *s)
{
	t_stack	tmp;

	while (s)
	{
		tmp = s;
		s = s->next;
		free(temp);
	}
}
