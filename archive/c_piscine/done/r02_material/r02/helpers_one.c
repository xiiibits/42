/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 21:25:34 by afahs             #+#    #+#             */
/*   Updated: 2025/04/27 21:45:30 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	ft_putstr(char *str)
{
	char	c;

	while (*str != '\0')
	{
		c = *str;
		write(1, &c, 1);
		str++;
	}
	write(1, " ", 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_arrlen(char **num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		i++;
	}
	return (i);
}

//get the number of segmants if char
int	get_num_of_segmants_from_char(char *c)
{
	int	i;

	i = 0;
	while (i < ft_strlen(c))
	{
		i++;
	}
	if (i % 3 == 0)
		return (i / 3);
	return ((i / 3) + 1);
}

//return a string reversed
void	reverse_string(char *str)
{
	int		start;	
	int		end;
	int		temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (end > start)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
