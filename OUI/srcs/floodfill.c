/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:30:08 by lulm              #+#    #+#             */
/*   Updated: 2024/06/14 18:14:16 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <fcntl.h>
#include <unistd.h>

static int	is_valid(t_game_init *init_game, int x, int y)
{
	if (x < 0 || y < 0 || x >= init_game->map_data.row_mat
		|| y >= init_game->map_data.col_mat
		|| init_game->map_data_temp.matrice[x][y] == '1'
		|| init_game->map_data_temp.matrice[x][y] == 'N')
		return (0);
	return (1);
}

void	floodfill(t_game_init *init_game, int x, int y)
{
	ft_printf("is valide %d\n", is_valid(init_game, x, y));
	if (!is_valid(init_game, x, y))
		return ;
	if (init_game->map_data_temp.matrice[x][y] == 'E')
		init_game->map_data_temp.matrice[x][y] = 'X';
	else if (init_game->map_data_temp.matrice[x][y] != 'X')
		init_game->map_data_temp.matrice[x][y] = 'N';
	floodfill(init_game, x + 1, y);
	floodfill(init_game, x - 1, y);
	floodfill(init_game, x, y + 1);
	floodfill(init_game, x, y - 1);
}

void	valid_path(t_game_init *init_game)
{
	int	i;
	int	j;

	i = 0;
	player_position(init_game);
	floodfill(init_game, init_game->init_pos.row, init_game->init_pos.col);
	while (init_game->map_data_temp.matrice[i])
	{
		j = 0;
		while (init_game->map_data_temp.matrice[i][j])
		{
			if (init_game->map_data_temp.matrice[i][j] == 'X')
				return ;
			j++;
		}
		i++;
	}
	ft_putstr_fd("Error: No valid path to the exit.\n", 1);
	exit(1);
}
