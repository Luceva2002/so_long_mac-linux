/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:44:01 by luevange          #+#    #+#             */
/*   Updated: 2025/05/26 16:17:38 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

static int	check_args(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		printf("Error: Invalid number of arguments.\n");
		printf("Usage: %s <map_file.ber>\n", argv[0]);
		return (0);
	}
	len = strlen(argv[1]);
	if (len < 4 || strcmp(argv[1] + len - 4, ".ber") != 0)
	{
		printf("Error: Map file must have .ber extension.\n");
		return (0);
	}
	return (1);
}

int	init_game_structures(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map.grid = NULL;
	game->player_img.img = NULL;
	game->wall_img.img = NULL;
	game->collectible_img.img = NULL;
	game->exit_img.img = NULL;
	game->floor_img.img = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->player.collectibles = 0;
	game->moves = 0;
	return (1);
}

int	setup_window_and_resources(t_game *game, char *map_path)
{
	if (!parse_map(game, map_path))
	{
		printf("Error: Failed to parse map.\n");
		clean_game(game);
		return (0);
	}
	if (!check_map(game))
	{
		printf("Error: Invalid map.\n");
		clean_game(game);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, game->map.width * TILE_SIZE,
			game->map.height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		clean_game(game);
		return (0);
	}
	if (!load_images(game))
	{
		clean_game(game);
		return (0);
	}
	return (1);
}

int	init_game(t_game *game, char *map_path)
{
	if (!init_game_structures(game))
		return (0);
	if (!setup_window_and_resources(game, map_path))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!check_args(argc, argv))
		return (1);
	if (!init_game(&game, argv[1]))
	{
		clean_game(&game);
		return (1);
	}
	render_map(&game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, clean_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
