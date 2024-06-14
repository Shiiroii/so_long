/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:30:08 by lulm              #+#    #+#             */
/*   Updated: 2024/06/14 16:00:04 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//stops when theres a wall, checks if a move is possible and
//if it finds an exit/collectible
static int	is_valid(t_game_init *init_game, int x, int y)
{
	if (x < 0 || y < 0 || x >= init_game->init_pos.row
		|| y >= init_game->init_pos.col
		|| init_game->map_data.matrice[x][y] == '1'
		|| init_game->map_data.matrice[x][y] == 'N')
		return (0);
	return (1);
}

void	floodfill(t_game_init *init_game, int x, int y)
{
	if (!is_valid(init_game, x, y))
		return ;
	if (init_game->map_data.matrice[x][y] == 'E')
		init_game->map_data.matrice[x][y] = 'X';
	else if (init_game->map_data.matrice[x][y] != 'X')
		init_game->map_data.matrice[x][y] = 'N';
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
	floodfill(init_game, init_game->init_pos.col, init_game->init_pos.row);
	while (init_game->map_data.matrice[i])
	{
		j = 0;
		while (init_game->map_data.matrice[i][j])
		{
			if (init_game->map_data.matrice[i][j] == 'E')
				return ;
			j++;
		}
		i++;
	}
	ft_putstr_fd("Error: No valid path to the exit.\n", 1);
	exit(1);
}
