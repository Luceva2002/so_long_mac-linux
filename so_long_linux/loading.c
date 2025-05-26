/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:16:02 by luevange          #+#    #+#             */
/*   Updated: 2025/05/26 16:17:25 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_player_image(t_game *game)
{
	game->player_img.img = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &game->player_img.width,
			&game->player_img.height);
	if (!game->player_img.img)
	{
		printf("Error: Failed to load player image.\n");
		return (0);
	}
	return (1);
}

int	load_wall_image(t_game *game)
{
	game->wall_img.img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&game->wall_img.width, &game->wall_img.height);
	if (!game->wall_img.img)
	{
		printf("Error: Failed to load wall image.\n");
		return (0);
	}
	return (1);
}

int	load_collectible_image(t_game *game)
{
	game->collectible_img.img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &game->collectible_img.width,
			&game->collectible_img.height);
	if (!game->collectible_img.img)
	{
		printf("Error: Failed to load collectible image.\n");
		return (0);
	}
	return (1);
}

int	load_exit_floor_images(t_game *game)
{
	game->exit_img.img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&game->exit_img.width, &game->exit_img.height);
	if (!game->exit_img.img)
	{
		printf("Error: Failed to load exit image.\n");
		return (0);
	}
	game->floor_img.img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&game->floor_img.width, &game->floor_img.height);
	if (!game->floor_img.img)
	{
		printf("Error: Failed to load floor image.\n");
		mlx_destroy_image(game->mlx, game->exit_img.img);
		return (0);
	}
	return (1);
}

int	load_images(t_game *game)
{
	game->player_img.img = NULL;
	game->wall_img.img = NULL;
	game->collectible_img.img = NULL;
	game->exit_img.img = NULL;
	game->floor_img.img = NULL;
	if (!load_player_image(game))
		return (0);
	if (!load_wall_image(game))
	{
		destroy_images(game);
		return (0);
	}
	if (!load_collectible_image(game))
	{
		destroy_images(game);
		return (0);
	}
	if (!load_exit_floor_images(game))
	{
		destroy_images(game);
		return (0);
	}
	return (1);
}
