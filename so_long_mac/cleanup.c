/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:32:15 by luevange          #+#    #+#             */
/*   Updated: 2025/05/25 21:54:23 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_grid(t_game *game)
{
	int	i;

	if (!game || !game->map.grid)
		return ;
	i = 0;
	while (i < game->map.height)
	{
		if (game->map.grid[i])
			free(game->map.grid[i]);
		i++;
	}
	free(game->map.grid);
	game->map.grid = NULL;
}

static void	destroy_player_wall_collectible(t_game *game)
{
	if (game->player_img.img)
	{
		mlx_destroy_image(game->mlx, game->player_img.img);
		game->player_img.img = NULL;
	}
	if (game->wall_img.img)
	{
		mlx_destroy_image(game->mlx, game->wall_img.img);
		game->wall_img.img = NULL;
	}
	if (game->collectible_img.img)
	{
		mlx_destroy_image(game->mlx, game->collectible_img.img);
		game->collectible_img.img = NULL;
	}
}

static void	destroy_exit_floor(t_game *game)
{
	if (game->exit_img.img)
	{
		mlx_destroy_image(game->mlx, game->exit_img.img);
		game->exit_img.img = NULL;
	}
	if (game->floor_img.img)
	{
		mlx_destroy_image(game->mlx, game->floor_img.img);
		game->floor_img.img = NULL;
	}
}

void	destroy_images(t_game *game)
{
	if (game->mlx)
	{
		destroy_player_wall_collectible(game);
		destroy_exit_floor(game);
	}
}

void	clean_game(t_game *game)
{
	if (game)
	{
		if (game->map.grid)
			free_map_grid(game);
		if (game->mlx)
		{
			destroy_images(game);
			if (game->win)
			{
				mlx_destroy_window(game->mlx, game->win);
				game->win = NULL;
			}
			free(game->mlx);
			game->mlx = NULL;
		}
	}
}
