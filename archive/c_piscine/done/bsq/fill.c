/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:26:26 by afahs             #+#    #+#             */
/*   Updated: 2025/04/30 22:26:29 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_square(char **map, t_sqres res, t_mapinfo info)
{
	int	i;
	int	j;
	int	start_row;
	int	start_col;

	start_row = res.row - res.size + 1;
	start_col = res.col - res.size + 1;
	i = start_row;
	while (i <= res.row)
	{
		j = start_col;
		while (j <= res.col)
		{
			map[i][j] = info.full;
			j++;
		}
		i++;
	}
}
