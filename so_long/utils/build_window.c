/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 06:26:56 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 20:01:46 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	build_map(t_game *game, char *file)
{
	int	i;

	game->map = read_file(file);
	if (!game->map || !check_map(game->map))
	{
		if (game->map)
		{
			i = 0;
			while (game->map[i])
			{
				free(game->map[i]);
				i++;
			}
			free(game->map);
		}
		display_error();
	}
	game->map_height = get_height(game->map);
	game->map_width = ft_strlen(game->map[0]);
}

static void	find_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	init_game(t_game *game, char *file)
{
	int	w;
	int	h;

	build_map(game, file);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->window = mlx_new_window(game->mlx, ft_strlen(game->map[0]) * 64,
			get_height(game->map) * 64, "so_long");
	if (!game->window)
		return (-1);
	game->img_w = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm", &w, &h);
	game->img_f = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm", &w, &h);
	game->img_p = mlx_xpm_file_to_image(game->mlx, "./img/play1.xpm", &w, &h);
	game->img_p2 = mlx_xpm_file_to_image(game->mlx, "./img/play2.xpm", &w, &h);
	game->img_c = mlx_xpm_file_to_image(game->mlx, "./img/zombie.xpm", &w, &h);
	game->img_e = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &w, &h);
	game->curnt_img = game->img_p;
	game->frame_count = 0;
	game->animation_speed = 500;
	find_position(game);
	game->nb_collectables = count_char(game->map, 'C');
	game->collected = 0;
	game->moves = 0;
	return (0);
}

static void	destroy_imgs(t_game *game)
{
	if (game->img_w)
		mlx_destroy_image(game->mlx, game->img_w);
	if (game->img_f)
		mlx_destroy_image(game->mlx, game->img_f);
	if (game->img_p)
		mlx_destroy_image(game->mlx, game->img_p);
	if (game->img_p2)
		mlx_destroy_image(game->mlx, game->img_p2);
	if (game->img_c)
		mlx_destroy_image(game->mlx, game->img_c);
	if (game->img_e)
		mlx_destroy_image(game->mlx, game->img_e);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
}

void	cleanup_game(t_game *game)
{
	int	i;

	destroy_imgs(game);
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
