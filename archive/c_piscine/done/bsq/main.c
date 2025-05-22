/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:27:16 by afahs             #+#    #+#             */
/*   Updated: 2025/04/30 22:27:22 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	handle_header(int fd, t_mapinfo *info)
{
	char	*header;

	header = read_line(fd);
	if (header == NULL || parse_header(header, info) == 0)
	{
		free(header);
		return (0);
	}
	free(header);
	return (1);
}

static char	**handle_map(int fd, t_mapinfo *info)
{
	char	**map;

	map = read_map(fd, info);
	if (map == NULL || validate_map(map, *info) == 0)
		return (NULL);
	return (map);
}

static int	handle_solve(char **map, t_mapinfo info)
{
	int		**dp;
	t_sqres	res;

	dp = alloc_dp(info);
	if (dp == NULL)
	{
		free_map(map);
		return (0);
	}
	compute_dp(map, dp, info, &res);
	fill_square(map, res, info);
	print_map(map, info);
	free_map(map);
	free_dp(dp, info);
	return (1);
}

void	process_input(const char *filename)
{
	int			fd;
	char		**map;
	t_mapinfo	info;

	if (!open_input(filename, &fd))
		return ;
	if (!handle_header(fd, &info))
	{
		cleanup_error(filename, fd);
		return ;
	}
	map = handle_map(fd, &info);
	if (!map)
	{
		cleanup_error(filename, fd);
		return ;
	}
	if (!handle_solve(map, info))
	{
		cleanup_error(filename, fd);
		return ;
	}
	if (filename)
		close(fd);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		process_input(NULL);
	else
	{
		i = 1;
		while (i < argc)
		{
			process_input(argv[i]);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
