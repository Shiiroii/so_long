/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 11:16:20 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/24 10:36:17 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_every_obj_valid(t_game_init *init_game)
{
	if (!(init_game->game_data.player_count == 1
			&& init_game->game_data.exit_count == 1
			&& init_game->game_data.collectible_count > 0))
		return (0);
	return (1);
}

int	(valid_map_objs(t_game_init *init_game))
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
				init_game->game_data.wall_count++;
			else if (init_game->map_data.mat[row][col] == FLOOR)
				init_game->game_data.floor_count++;
			else if (init_game->map_data.mat[row][col] == PLAYER)
				init_game->game_data.player_count++;
			else if (init_game->map_data.mat[row][col] == COLLECTIBLE)
				init_game->game_data.collectible_count++;
			else if (init_game->map_data.mat[row][col] == EXIT)
				init_game->game_data.exit_count++;
			else if (init_game->map_data.mat[row][col] != '\n')
				return (0);
			col++;
		}
	}
	return (is_every_obj_valid(init_game));
}

int	valid_map_walls(t_game_init *init_game)
{
	int	i;
	int	j;

	i = 0;
	while (i < init_game->map_data.row_mat)
	{
		j = 0;
		while (j < init_game->map_data.col_mat)
		{
			if (i == 0 || i == init_game->map_data.row_mat - 1
				|| j == 0 || j == init_game->map_data.col_mat - 1)
			{
				if (init_game->map_data.mat[i][j] != WALL)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_map_borders(t_game_init *init_game)
{
	if (init_game->map_data.col_mat <= 0
		|| init_game->map_data.row_mat <= 0)
		return (0);
	if (init_game->map_data.size_mat == 0)
		return (0);
	if (init_game->map_data.size_mat % init_game->map_data.row_mat == 0
		&& init_game->map_data.size_mat / init_game->map_data.row_mat
		== init_game->map_data.col_mat)
		return (1);
	return (0);
}

int	is_map_valid(t_game_init *init_game)
{
	t_floodfill_data	data;

	data.collectibles = 0;
	data.found_exit = 0;
	if (!(copy_map(init_game)))
		return (0);
	if (!(valid_map_objs(init_game)))
		return (0);
	if (!(valid_map_borders(init_game)))
		return (0);
	if (!(valid_map_walls(init_game)))
		return (0);
	player_position(init_game);
	floodfill(init_game, init_game->init_pos.row,
		init_game->init_pos.col, &data);
	if (data.collectibles != count_collectible(init_game))
		return (0);
	if (data.found_exit == 0)
		return (0);
	free_copy_map(init_game);
	return (1);
}
