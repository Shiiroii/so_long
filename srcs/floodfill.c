/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:30:08 by lulm              #+#    #+#             */
/*   Updated: 2024/06/13 10:57:52 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	floodfill(t_game_init *init_game, int x, int y)
{
	if (x < 0 || y < 0 || x >= init_game->map_data.row_mat
		|| y >= init_game->map_data.col_mat
		|| init_game->map_data.matrice[y][x] == '1'
		|| init_game->map_data.matrice[y][x] == 'X')
		return ;
	init_game->map_data.matrice[y][x] = 'X';
	floodfill(init_game, x + 1, y);
	floodfill(init_game, x - 1, y);
	floodfill(init_game, x, y + 1);
	floodfill(init_game, x, y - 1);
}

void	verify_win(t_game_init *init_game)
{
	int	i;
	int	j;

	i = 0;
	player_position(init_game);
	floodfill(init_game, init_game->init_pos.col, init_game->init_pos.row);
	while (i < init_game->map_data.row_mat)
	{
		j = 0;
		while (j < init_game->map_data.col_mat)
		{
			if (init_game->map_data.matrice[i][j] == 'E'
				|| init_game->map_data.matrice[i][j] == 'C')
				error_map(3);
			j++;
		}
		i++;
	}
}
