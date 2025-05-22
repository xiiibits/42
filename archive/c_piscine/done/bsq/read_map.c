/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:27:56 by afahs             #+#    #+#             */
/*   Updated: 2025/04/30 22:28:01 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>

static	char	**alloc_map(int rows)
{
	char	**map;

	map = malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	return (map);
}

static	int	get_stripped_len(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len] != '\n')
		return (-1);
	line[len] = '\0';
	return (len);
}

static	void	cleanup(char **map, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static	int	store_line(char **map, int fd, t_mapinfo *info, int idx)
{
	char	*line;
	int		len;

	line = read_line(fd);
	if (!line)
		return (0);
	len = get_stripped_len(line);
	if (len < 0 || (idx > 0 && len != info->cols))
	{
		free(line);
		return (0);
	}
	if (idx == 0)
		info->cols = len;
	map[idx] = line;
	return (1);
}

char	**read_map(int fd, t_mapinfo *info)
{
	char	**map;
	int		i;

	map = alloc_map(info->rows);
	if (!map)
		return (NULL);
	i = 0;
	while (i < info->rows)
	{
		if (!store_line(map, fd, info, i))
			break ;
		i++;
	}
	if (i != info->rows)
	{
		cleanup(map, i);
		return (NULL);
	}
	map[i] = NULL;
	return (map);
}
