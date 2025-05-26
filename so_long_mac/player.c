/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:31:40 by luevange          #+#    #+#             */
/*   Updated: 2025/05/13 01:31:05 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_exit(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == 'E')
	{
		if (game->player.collectibles == game->map.collectibles)
		{
			printf("Congratulations! You completed the game in %d moves.\n",
				game->moves + 1);
			exit(0);
		}
		return (1);
	}
	return (0);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->player.collectibles++;
		game->map.grid[new_y][new_x] = '0';
	}
	game->map.grid[game->player.y][game->player.x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->player.x = new_x;
	game->player.y = new_y;
	game->moves++;
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == '1')
		return ;
	if (check_exit(game, new_x, new_y))
		return ;
	update_player_position(game, new_x, new_y);
	render_map(game);
	printf("Moves: %d, Collectibles: %d/%d\n", game->moves,
		game->player.collectibles, game->map.collectibles);
}

int	handle_key(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	if (keycode == 13 || keycode == 126)
		new_y--;
	else if (keycode == 0 || keycode == 123)
		new_x--;
	else if (keycode == 1 || keycode == 125)
		new_y++;
	else if (keycode == 2 || keycode == 124)
		new_x++;
	else if (keycode == 53)
		exit(0);
	else
		return (0);
	move_player(game, new_x, new_y);
	return (1);
}
