/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:28:49 by afahs             #+#    #+#             */
/*   Updated: 2025/04/30 22:28:51 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <fcntl.h>

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_dp(int **dp, t_mapinfo info)
{
	int	i;

	i = 0;
	while (i < info.rows)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}

int	open_input(const char *filename, int *fd)
{
	if (filename)
	{
		*fd = open(filename, O_RDONLY);
		if (*fd < 0)
		{
			print_error();
			return (0);
		}
	}
	else
		*fd = 0;
	return (1);
}

void	cleanup_error(const char *filename, int fd)
{
	print_error();
	if (filename)
		close(fd);
}
