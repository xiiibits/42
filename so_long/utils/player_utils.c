/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 07:53:05 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 19:43:18 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map_width
		|| y < 0 || y >= game->map_height)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

static void	collect(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->collected++;
		if (game->collected == game->nb_collectables)
			write(1, "you killed all zombies\n", 24);
		else
			write(1, "you killed a zombie\n", 21);
	}
}

static void	is_done(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collected == game->nb_collectables)
		{
			exit_game(game);
		}
	}
}

void	move_player(t_game *game, int x, int y)
{
	if (!is_valid_move(game, x, y))
		return ;
	collect(game, x, y);
	is_done(game, x, y);
	if (game->map[y][x] != 'E')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[y][x] = 'P';
	}	
	else
		return ;
	game->player_x = x;
	game->player_y = y;
	game->moves++;
	render_game(game);
	if (game->curnt_img == game->img_p)
		game->curnt_img = game->img_p2;
	else
		game->curnt_img = game->img_p;
}

int	keypress(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (keycode == 65307)
		exit_game(game);
	if (keycode == 115 || keycode == 65364)
		y++;
	else if (keycode == 119 || keycode == 65362)
		y--;
	else if (keycode == 97 || keycode == 65361)
		x--;
	else if (keycode == 100 || keycode == 65363)
		x++;
	if (x != game->player_x || y != game->player_y)
		move_player(game, x, y);
	return (0);
}
