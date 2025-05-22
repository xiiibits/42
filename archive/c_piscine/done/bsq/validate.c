/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:29:07 by afahs             #+#    #+#             */
/*   Updated: 2025/04/30 22:29:09 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	is_valid_char(char c, t_mapinfo info)
{
	return (c == info.empty || c == info.obstacle);
}

int	validate_map(char **map, t_mapinfo info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.rows)
	{
		j = 0;
		while (j < info.cols)
		{
			if (!is_valid_char(map[i][j], info))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
