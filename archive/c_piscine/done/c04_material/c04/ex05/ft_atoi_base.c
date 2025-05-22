/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:25:16 by afahs             #+#    #+#             */
/*   Updated: 2025/04/22 02:44:30 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// check if the base valid
int	is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if ((!base[0]) || (!base[1]))
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (i);
}

//return the number of characters that match the base
int	in_base(char *str, char *base)
{
	int	i;
	int	j;
	int	t;
	int	v;

	i = 0;
	t = 0;
	v = is_valid(base);
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == str[i])
			{
				t = (t * v) + j;
				break ;
			}
			j++;
		}
		if (!base[j])
			return (t);
		i++;
	}
	return (t);
}

//get the number from the string
char	*until_base(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
		i++;
	while (str[i])
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	s;
	int	n;

	i = 0;
	s = 1;
	n = 0;
	if (is_valid(base))
	{
		while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				s = s * -1;
			i++;
		}
		n = in_base(&str[i], base);
		return (n * s);
	}
	else
		return (0);
}
