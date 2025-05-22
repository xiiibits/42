/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:27:34 by afahs             #+#    #+#             */
/*   Updated: 2025/04/30 22:27:37 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

void	print_map(char **map, t_mapinfo info)
{
	int	i;
	int	len;

	i = 0;
	while (i < info.rows)
	{
		len = 0;
		while (map[i][len])
			len++;
		write(1, map[i], len);
		write(1, "\n", 1);
		i++;
	}
}

void	print_error(void)
{
	write(2, "map error\n", 10);
}
