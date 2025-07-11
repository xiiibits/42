/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 03:21:40 by afahs             #+#    #+#             */
/*   Updated: 2025/07/03 08:45:32 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// check the line if all 1s 
int	all_ones(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// count number of specific char in a 2d array
int	count_char(char **m, char c)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == c)
				found++;
			j++;
		}
		i++;
	}
	return (found);
}

// check if a 2d array has other than the required chars 
int	contain_other(char **m)
{
	int	i;
	int	j;

	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] != 'P' && m[i][j] != 'E' && m[i][j] != 'C'
				&& m[i][j] != '1' && m[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// check if the first and last elements of a line are 1s
int	corner_ones(char *line)
{
	int	i;

	i = 0;
	if (line[i] != '1')
		return (0);
	while (line[i])
		i++;
	if (line[i - 1] != '1')
		return (0);
	return (1);
}

// check all line are eqaul in 2d array
int	check_length(char **map)
{
	int		i;
	size_t	size;

	i = 1;
	size = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != size)
			return (0);
		i++;
	}
	return (1);
}
