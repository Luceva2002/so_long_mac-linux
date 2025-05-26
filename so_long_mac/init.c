/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:28:20 by luevange          #+#    #+#             */
/*   Updated: 2025/05/19 13:48:04 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file_path)
{
	int		fd;
	int		count;
	char	buffer[1];

	count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')
			count++;
	}
	close(fd);
	return (count + 1);
}

int	get_line_length(char *file_path)
{
	int		fd;
	int		len;
	char	buffer[1];

	len = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, buffer, 1) > 0 && buffer[0] != '\n')
		len++;
	close(fd);
	return (len);
}

void	process_char(t_game *game, char c, int i, int j)
{
	game->map.grid[i][j] = c;
	if (c == 'P')
	{
		game->player.x = j;
		game->player.y = i;
	}
	else if (c == 'C')
		game->map.collectibles++;
	else if (c == 'E')
	{
		game->map.exit_x = j;
		game->map.exit_y = i;
	}
}
