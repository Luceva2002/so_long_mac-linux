/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:30:10 by luevange          #+#    #+#             */
/*   Updated: 2025/05/13 01:30:31 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int	count_elements(t_game *game, int *player_count, int *exit_count)
{
	int	i;
	int	j;

	*player_count = 0;
	*exit_count = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] == 'P')
				(*player_count)++;
			else if (game->map.grid[i][j] == 'E')
				(*exit_count)++;
			if (!is_valid_char(game->map.grid[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	int	i;
	int	player_count;
	int	exit_count;

	i = 0;
	while (i < game->map.height)
	{
		if ((int)strlen(game->map.grid[i]) != game->map.width)
			return (0);
		i++;
	}
	if (!check_walls(game))
		return (0);
	if (!count_elements(game, &player_count, &exit_count))
		return (0);
	if (player_count != 1 || exit_count != 1 || game->map.collectibles < 1)
		return (0);
	return (1);
}
