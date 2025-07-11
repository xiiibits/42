/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:52:19 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 19:54:37 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// get number of lines in 2d array
int	get_height(char **map)
{
	int	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

// used to copy the string to the 2d array without the \n char 
char	*ft_strdup_noline(const char *s)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static int	nb_lines(char *file)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		display_error();
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		i++;
	}
	free(line);
	return (i);
}

//read the file and return it as a 2d array 
char	**read_file(char *file)
{
	int		fd;
	char	**map;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		display_error();
	}
	map = malloc((nb_lines(file) + 1) * sizeof(char *));
	close(fd);
	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		map[i] = ft_strdup_noline(line);
		free(line);
		if (map[i] == NULL)
			break ;
		i++;
	}
	return (map);
}

int	check_map(char **map)
{
	int	i;

	if (!contain_other(map) || !check_length(map)
		|| !all_ones(map[0]) || !all_ones(map[get_height(map) - 1])
		|| (count_char(map, 'P') != 1) || (count_char(map, 'E') != 1)
		|| (count_char(map, 'C') < 1))
		return (0);
	i = 0;
	while (map[i])
	{
		if (!corner_ones(map[i]))
			return (0);
		i++;
	}
	if (!ispath(map, ft_strlen(map[0])))
		return (0);
	return (1);
}
