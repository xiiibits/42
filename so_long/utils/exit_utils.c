/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 03:13:28 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 19:42:07 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_error(void)
{	
	write(2, "ERROR!\n", 7);
	exit(1);
}

void	update_player_animation(t_game *game)
{
	game->frame_count++;
	if (game->frame_count >= game->animation_speed)
	{
		if (game->curnt_img == game->img_p)
			game->curnt_img = game->img_p2;
		else
			game->curnt_img = game->img_p;
		game->frame_count = 0;
	}
}

int	game_loop(t_game *game)
{
	render_game(game);
	return (0);
}

int	exit_game(t_game *game)
{
	cleanup_game(game);
	exit(0);
}
