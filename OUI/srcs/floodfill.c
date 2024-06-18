/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:30:08 by lulm              #+#    #+#             */
/*   Updated: 2024/06/18 19:20:33 by lulm             ###   ########.fr       */
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
	while (init_game->map_data.matrice[i])
	{
		j = 0;
		while (init_game->map_data.matrice[i][j])
		{
			if (init_game->map_data.matrice[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	floodfill(t_game_init *init_game, int x, int y)
{
	int	count;

	count = 0;
	player_position(init_game);
	if (init_game->map_data_temp.matrice[x][y] == 'E'
		|| init_game->map_data_temp.matrice[x][y] == 'C')
		count++;
	if (init_game->map_data_temp.matrice[x + 1][y] != '1')
		count += floodfill(init_game, x + 1, y);
	if (init_game->map_data_temp.matrice[x - 1][y] != '1')
		count += floodfill(init_game, x - 1, y);
	if (init_game->map_data_temp.matrice[x][y + 1] != '1')
		count += floodfill(init_game, x, y + 1);
	if (init_game->map_data_temp.matrice[x][y - 1] != '1')
		count += floodfill(init_game, x, y - 1);
	return (count);
}
