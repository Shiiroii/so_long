/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:30:08 by lulm              #+#    #+#             */
/*   Updated: 2025/02/24 10:33:58 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <fcntl.h>
#include <unistd.h>

int	count_collectible(t_game_init *init_game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (init_game->map_data.mat[i])
	{
		j = 0;
		while (init_game->map_data.mat[i][j])
		{
			if (init_game->map_data.mat[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	floodfill(t_game_init *init_game, int x, int y,	t_floodfill_data *data)
{
	if (init_game->map_data_t.mat[x][y] == '1')
		return ;
	if (init_game->map_data_t.mat[x][y] == 'E')
	{
		data->found_exit = 1;
		return ;
	}
	if (init_game->map_data_t.mat[x][y] == 'C')
		data->collectibles++;
	init_game->map_data_t.mat[x][y] = '1';
	floodfill(init_game, x + 1, y, data);
	floodfill(init_game, x - 1, y, data);
	floodfill(init_game, x, y + 1, data);
	floodfill(init_game, x, y - 1, data);
}
