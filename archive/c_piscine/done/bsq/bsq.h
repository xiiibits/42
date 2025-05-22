/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:25:37 by afahs             #+#    #+#             */
/*   Updated: 2025/04/30 22:25:44 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>  
# include <stdlib.h>

typedef struct s_mapinfo
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
}	t_mapinfo;

typedef struct s_sqres
{
	int		size;
	int		row;
	int		col;
}	t_sqres;

int		parse_header(const char *line, t_mapinfo *info);
char	*read_line(int fd);
char	**read_map(int fd, t_mapinfo *info);

int		validate_map(char **map, t_mapinfo info);

int		**alloc_dp(t_mapinfo info);
void	compute_dp(char **map, int **dp, t_mapinfo info, t_sqres *res);

void	fill_square(char **map, t_sqres res, t_mapinfo info);

void	print_map(char **map, t_mapinfo info);
void	print_error(void);

void	free_map(char **map);
void	free_dp(int **dp, t_mapinfo info);

void	process_input(const char *filename);
int		main(int argc, char **argv);

void	cleanup_error(const char *filename, int fd);
int		open_input(const char *filename, int *fd);

#endif