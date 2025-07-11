/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 03:07:05 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 20:01:05 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	g_c_found = 0;
int	g_e_found = 0;

static int	find_char(char **map, char target, int *row, int *col)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == target)
			{
				*row = i;
				*col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	find_path(char **map, int width, int row, int col)
{
	int		height;
	char	original;

	height = get_height(map);
	if (row < 0 || col < 0 || row >= height || col >= width)
		return (0);
	if (map[row][col] == '1' || map[row][col] == 'X')
		return (0);
	original = map[row][col];
	if (original == 'C')
		g_c_found++;
	if (original == 'E')
		g_e_found = 1;
	map[row][col] = 'X';
	find_path(map, width, row - 1, col);
	find_path(map, width, row + 1, col);
	find_path(map, width, row, col - 1);
	find_path(map, width, row, col + 1);
	return (1);
}

static void	free_temp_map(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

static char	**dup_map(char **map)
{
	char	**temp;
	int		i;

	temp = malloc((get_height(map) + 1) * sizeof(char *));
	if (!temp)
		return (0);
	i = 0;
	while (map[i])
	{
		temp[i] = ft_strdup(map[i]);
		i++;
	}
	temp[i] = 0;
	return (temp);
}

int	ispath(char **map, int width)
{
	int		start_row;
	int		start_col;
	char	**temp;
	int		total_c;

	g_c_found = 0;
	g_e_found = 0;
	temp = dup_map(map);
	if (!find_char(temp, 'P', &start_row, &start_col))
	{
		free_temp_map(temp);
		return (0);
	}
	total_c = count_char(temp, 'C');
	find_path(temp, width, start_row, start_col);
	free_temp_map(temp);
	return (g_e_found && g_c_found == total_c);
}
