/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:26:50 by afahs             #+#    #+#             */
/*   Updated: 2025/04/30 22:26:55 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>

/* Parses first line "<rows><empty><obstacle><full>\n" into info */
int	parse_header(const char *line, t_mapinfo *info)
{
	int	i;
	int	rows;
	int	j;

	i = 0;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	rows = 0;
	j = 0;
	while (j < i)
		rows = rows * 10 + (line[j++] - '0');
	if (rows <= 0 || !line[i] || !line[i + 1]
		|| !line[i + 2] || line[i + 3] != '\n')
		return (0);
	info->rows = rows;
	info->empty = line[i];
	info->obstacle = line[i + 1];
	info->full = line[i + 2];
	if (info->empty == info->obstacle
		|| info->empty == info->full
		|| info->obstacle == info->full)
		return (0);
	return (1);
}

/* Resize buffer when full; static helper for read_line */
static char	*resize_line(char *old, int len, int *cap)
{
	char	*new;
	int		i;

	new = malloc((*cap) * 2);
	if (!new)
	{
		free(old);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new[i] = old[i];
		i++;
	}
	*cap *= 2;
	return (new);
}

static int	fill_buffer(int fd, char **line, int *len, int *cap)
{
	char	buf;
	int		r;

	r = read(fd, &buf, 1);
	while (r == 1)
	{
		if (*len + 1 >= *cap)
		{
			*line = resize_line(*line, *len, cap);
			if (!*line)
				return (-1);
		}
		(*line)[(*len)++] = buf;
		if (buf == '\n')
			break ;
		r = read(fd, &buf, 1);
	}
	return (r);
}

/* Reads one line (including '\n') from fd, returns malloc'd string */
char	*read_line(int fd)
{
	char	*line;
	int		r;
	int		len;
	int		cap;

	len = 0;
	cap = 128;
	line = malloc(cap);
	if (!line)
		return (NULL);
	r = fill_buffer(fd, &line, &len, &cap);
	if (r < 0 || len == 0)
	{
		free(line);
		return (NULL);
	}
	line[len] = '\0';
	return (line);
}
