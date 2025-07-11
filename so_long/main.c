/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afahs <afahs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:41:56 by afahs             #+#    #+#             */
/*   Updated: 2025/07/04 19:30:19 by afahs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Usage: ./so_long <map.ber>\n");
		return (1);
	}
	if (init_game(&game, argv[1]) == -1)
	{
		printf("Error: Failed to initialize game\n");
		cleanup_game(&game);
		return (1);
	}
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_key_hook(game.window, keypress, &game);
	mlx_hook(game.window, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
