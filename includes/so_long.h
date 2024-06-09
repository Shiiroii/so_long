/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:36:30 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/09 09:53:40 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../utils/libft/libft.h"
#include "../utils/ft_printf/ft_printf.h"
#include "../MLX/mlx.h"

# include <string.h>
# include <fcntl.h>

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
# define RESTART 114

// ============================== UTILS ============================

# define FILES 1

# define TRUE 1
# define FALSE 0

# define CELL_SIZE 32

// =================================================================

typedef struct s_game_obj
{
	void		*player;
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
	char		**matrice;
	t_game_res	res;
	t_game_pos	pos;
}	t_map_data;

typedef struct s_game_init
{
	void	*mlxptr;
	void	*winptr;
	int		argc_temp;
	char	**argv_temp;
	t_map_data	map_data;
	t_game_data	game_data;
	t_game_pos	init_pos;
	t_game_res	init_res;
	t_game_obj	init_obj;
}	t_game_init;

// ================================ GAME ================================

void	start_game(t_game_init *init_game);
int		exit_program(t_game_init *init_game);
void	restart(t_game_init *init_game);
int		ft_moving(t_game_init *init_game, int col, int row);

// ================================ MAP =================================

int		open_map(char *map, t_game_init *init_game);
int		draw_map(t_game_init *init_game);

// ============================ INITIALIZE ==============================

void	initialize_game(t_game_init	*init_game);

// =============================== UTILS ===============================

void	error_map(int nb);
void	error_init(int nb);
int		ft_moves(int key, t_game_init *init_game);
void	free_image(t_game_init *init_game);
void	free_map(t_game_init *init_game);

// ======================================================================



#endif
