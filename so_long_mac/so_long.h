/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:43:41 by luevange          #+#    #+#             */
/*   Updated: 2025/05/26 16:18:39 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// so_long.h
#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define TILE_SIZE 64

typedef struct s_player
{
	int			x;
	int			y;
	int			collectibles;
}				t_player;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			collectibles;
	int			exit_x;
	int			exit_y;
}				t_map;

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_img		player_img;
	t_img		wall_img;
	t_img		collectible_img;
	t_img		exit_img;
	t_img		floor_img;
	int			moves;
}				t_game;

int				init_game(t_game *game, char *map_path);
int				parse_map(t_game *game, char *map_path);
int				check_map(t_game *game);
void			render_map(t_game *game);
int				handle_key(int keycode, t_game *game);
void			move_player(t_game *game, int new_x, int new_y);
void			clean_game(t_game *game);
int				load_images(t_game *game);
int				load_player_image(t_game *game);
int				load_wall_image(t_game *game);
int				load_collectible_image(t_game *game);
int				load_exit_floor_images(t_game *game);
int				check_walls(t_game *game);
int				count_elements(t_game *game, int *player, int *exit);
int				count_lines(char *file_path);
int				get_line_length(char *file_path);
int				allocate_grid(t_game *game);
int				read_map_file(t_game *game, char *map_path);
void			render_tile(t_game *game, int i, int j);
int				check_exit(t_game *game, int new_x, int new_y);
void			update_player_position(t_game *game, int new_x, int new_y);
void			free_map_grid(t_game *game);
void			destroy_images(t_game *game);
void			process_char(t_game *game, char c, int i, int j);

#endif