/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:29:05 by luevange          #+#    #+#             */
/*   Updated: 2025/05/13 02:08:59 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

static void	process_line_char(t_game *game, char c, int *i, int *j)
{
	if (c == '\n')
	{
		game->map.grid[*i][*j] = '\0';
		(*i)++;
		*j = 0;
	}
	else
	{
		process_char(game, c, *i, *j);
		(*j)++;
	}
}

int	read_map_file(t_game *game, char *map_path)
{
	int		fd;
	int		i;
	int		j;
	char	buffer[1];

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	j = 0;
	game->map.collectibles = 0;
	while (read(fd, buffer, 1) > 0)
	{
		process_line_char(game, buffer[0], &i, &j);
	}
	close(fd);
	return (1);
}

int	parse_map(t_game *game, char *map_path)
{
	game->map.height = count_lines(map_path);
	game->map.width = get_line_length(map_path);
	if (game->map.height == 0 || game->map.width == 0)
		return (0);
	if (!allocate_grid(game))
		return (0);
	if (!read_map_file(game, map_path))
		return (0);
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (i == 0 || i == game->map.height - 1 || j == 0
				|| j == game->map.width - 1)
			{
				if (game->map.grid[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	allocate_grid(t_game *game)
{
	int	i;

	game->map.grid = (char **)malloc(sizeof(char *) * game->map.height);
	if (!game->map.grid)
		return (0);
	i = 0;
	while (i < game->map.height)
	{
		game->map.grid[i] = calloc(1,sizeof(char) * (game->map.width + 1));
		if (!game->map.grid[i])
		{
			while (--i >= 0)
				free(game->map.grid[i]);
			free(game->map.grid);
			game->map.grid = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}
