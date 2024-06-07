/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:36:30 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/07 15:09:15 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../utils/libft/libft.h"
#include "../minilibx-linux/mlx.h"

# include <string.h>
# include <fcntl.h>
# include <struct.h>

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

typedef struct
{

}	

#endif
