/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 08:19:58 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/04 15:34:55 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_place(t_game_init *init_game, void *img, int x, int y)
{
	mlx_put_image_to_window(init_game->mlxptr, init_game->winptr,
		img, x * IMG_SIZE, y * IMG_SIZE);
}

void	ft_finish_exits(t_game_init *init_game, int col, int row)
{
	if (init_game->map_data.mat[row][col] == EXIT
		&& init_game->game_data.collectible_count == 0)
		ft_place(init_game, init_game->init_obj.exit_open, col, row);
	if (init_game->map_data.mat[row][col] == EXIT
		&& init_game->game_data.collectible_count != 0)
		ft_place(init_game, init_game->init_obj.exit_close, col, row);
	return ;
}

int	draw_map(t_game_init *init_game)
{
	int	row;
	int	col;

	row = -1;
	while (init_game->map_data.mat[++row])
	{
		col = 0;
		while (init_game->map_data.mat[row][col])
		{
			if (init_game->map_data.mat[row][col] == WALL)
				ft_place(init_game, init_game->init_obj.wall, col, row);
			if (init_game->map_data.mat[row][col] == PLAYER)
				ft_place(init_game, init_game->init_obj.player, col, row);
			if (init_game->map_data.mat[row][col] == FLOOR)
				ft_place(init_game, init_game->init_obj.floor, col, row);
			ft_finish_exits(init_game, col, row);
			if (init_game->map_data.mat[row][col] == COLLECTIBLE)
				ft_place(init_game, init_game->init_obj.collectible, col, row);
			col++;
		}
	}
	return (0);
}

//===========finished===========//
