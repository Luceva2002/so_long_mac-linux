/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:31:10 by luevange          #+#    #+#             */
/*   Updated: 2025/05/13 01:50:20 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	render_tile(t_game *game, int i, int j)
{
	int	x_pos;
	int	y_pos;

	x_pos = j * TILE_SIZE;
	y_pos = i * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img.img, x_pos,
		y_pos);
	if (game->map.grid[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img.img, x_pos,
			y_pos);
	else if (game->map.grid[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible_img.img,
			x_pos, y_pos);
	else if (game->map.grid[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img.img, x_pos,
			y_pos);
	else if (game->map.grid[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img.img,
			x_pos, y_pos);
}

void	render_map(t_game *game)
{
	int		i;
	int		j;
	char	moves_str[50];

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			render_tile(game, i, j);
			j++;
		}
		i++;
	}
	sprintf(moves_str, "Moves: %d", game->moves);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, moves_str);
}
