/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 03:14:45 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 20:02:44 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	*img_w;
	void	*img_f;
	void	*img_p;
	void	*img_p2;
	void	*img_c;
	void	*img_e;
	void	*curnt_img;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		nb_collectables;
	int		collected;
	int		moves;
	int		frame_count;
	int		animation_speed;
	char	**map;

}	t_game;

// read_utils.c
int		get_height(char **map);
char	**read_file(char *file);
int		check_map(char **map);

// small_utils.c
void	display_error(void);
int		exit_game(t_game *game);
void	update_player_animation(t_game *game);
int		game_loop(t_game *game);

// check_utils_one.c
int		all_ones(char *line);
int		count_char(char **m, char c);
int		contain_other(char **m);
int		corner_ones(char *line);
int		check_length(char **map);

// check_path.c
int		ispath(char **map, int width);

// build_window.c
int		init_game(t_game *game, char *file);
void	render_game(t_game *game);

// player_utils.c
void	move_player(t_game *game, int x, int y);
int		keypress(int keycode, t_game *game);

void	display_moves(t_game *game);
char	*ft_itoa(int n);
void	cleanup_game(t_game *game);

#endif