/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:34:32 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 19:35:03 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img_helper(t_game *g, void *im, int j, int i)
{
	void	*m;
	void	*w;

	m = g->mlx;
	w = g->window;
	mlx_put_image_to_window(m, w, im, j, i);
}

void	render_game(t_game *game)
{
	int	i;
	int	j;

	update_player_animation(game);
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
				put_img_helper(game, game->img_w, j * 64, i * 64);
			else if (game->map[i][j] == '0')
				put_img_helper(game, game->img_f, j * 64, i * 64);
			else if (game->map[i][j] == 'P')
				put_img_helper(game, game->curnt_img, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				put_img_helper(game, game->img_c, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				put_img_helper(game, game->img_e, j * 64, i * 64);
			j++;
		}
		i++;
	}
	display_moves(game);
}
