/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:36:30 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/24 10:32:04 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../utils/libft/libft.h"
# include "../utils/ft_printf/ft_printf.h"
# include "../utils/MLX/mlx.h"
# include <string.h>
# include <fcntl.h>
# include <stdio.h>

// ============================= ASSETS ============================

# define PLAYER 'P'
# define FLOOR '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'

// ============================== KEYS =============================

# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

// ============================== UTILS ============================

# define FILES 1
# define IMG_SIZE 20 // textures are 20x20 pixels

// =================================================================

typedef struct s_game_obj
{
	void		*player;
	void		*player_up;
	void		*player_down;
	void		*player_left;
	void		*player_right;
	void		*wall;
	void		*floor;
	void		*collectible;
	void		*exit_open;
	void		*exit_close;
	int			img_width;
	int			img_height;
}	t_game_obj;

typedef struct s_game_pos
{
	int			row;
	int			col;
	int			end_row;
	int			end_col;
}	t_game_pos;

typedef struct s_game_res
{
	int			width;
	int			height;
	char		*name_window;
	char		*name_map;
}	t_game_res;

typedef struct s_game_data
{
	int			player_count;
	int			collectible_count;
	int			exit_count;
	int			move_count;
	int			wall_count;
	int			floor_count;
	int			finish;
}	t_game_data;

typedef struct s_map_data
{
	int			first_mat;
	int			col_mat;
	int			row_mat;
	int			size_mat;
	char		**mat;
	t_game_res	res;
	t_game_pos	pos;
}	t_map_data;

typedef struct s_game_init
{
	void		*mlxptr;
	void		*winptr;
	int			argc_temp;
	char		**argv_temp;
	t_map_data	map_data;
	t_map_data	map_data_t;
	t_game_data	game_data;
	t_game_pos	init_pos;
	t_game_res	init_res;
	t_game_obj	init_obj;
}	t_game_init;

typedef struct s_floodfill_data
{
	int			collectibles;
	int			found_exit;
}	t_floodfill_data;

// ================================ GAME ================================

void	start_game(t_game_init *init_game);
int		exit_program(t_game_init *init_game);
void	restart(t_game_init *init_game);
int		ft_moving(t_game_init *init_game, int col, int row);
void	you_win(t_game_init *init_game);

// ================================ MAP =================================

int		open_map(char *map, t_game_init *init_game);
int		draw_map(t_game_init *init_game);
int		map_dimension(t_game_init *init_game);
int		map_extension(char *map);
int		is_map_valid(t_game_init *init_game);
void	floodfill(t_game_init *init_game, int x, int y,	t_floodfill_data *data);
void	player_position(t_game_init *init_game);
void	valid_path(t_game_init *init_game);
int		count_collectible(t_game_init *init_game);

// ============================ INITIALIZE ==============================

void	initialize_game(t_game_init	*init_game);
int		read_checker(t_game_init *init_game);
int		copy_map(t_game_init *init_game);

// =============================== UTILS ===============================

void	error_map(int nb);
int		ft_moves(int key, t_game_init *init_game);
void	free_image(t_game_init *init_game);
void	free_map(t_game_init *init_game);
void	free_copy_map(t_game_init *init_game);

// ======================================================================

#endif
