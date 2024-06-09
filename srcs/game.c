/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:50:02 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/09 09:54:17 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_position(t_game_init *init_game)
{
	int	col;
	int	row;

	row = 0;
	while (init_game->map_data.matrice[row])
	{
		col = 0;
		while (init_game->map_data.matrice[row][col])
		{
			if (init_game->map_data.matrice[row][col] == PLAYER)
			{
				init_game->init_pos.col = col;
				init_game->init_pos.row = row;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	you_win(t_game_init *init_game)
{
	init_game->map_data.matrice[init_game->init_pos.row]
		[init_game->init_pos.col] = FLOOR;
	init_game->game_data.move_count++;
	ft_printf("You won, congrats!\n");
	exit_program(init_game);
}

int	print_count_moves(t_game_init *init_game)
{
	static int	starting_count = -1;
	int			player_count;

	player_count = init_game->game_data.move_count;
	if (player_count != starting_count)
	{
		ft_printf("You moved %d times!\n", player_count);
		starting_count = player_count;
	}
	return (1);
}

int	ft_moving(t_game_init *init_game, int col, int row)
{
	int	next_col;
	int	next_row;
	int	player_pos;

	player_position(init_game);
	next_col = init_game->init_pos.col + col;
	next_row = init_game->init_pos.row + row;
	player_pos = init_game->map_data.matrice[next_row][next_col];
	if (player_pos == FLOOR || player_pos == COLLECTIBLE)
	{
		init_game->map_data.matrice[next_row][next_col] = PLAYER;
		init_game->map_data.matrice[init_game->init_pos.row]
			[init_game->init_pos.col] = FLOOR;
		init_game->init_pos.col = next_col;
		init_game->init_pos.row = next_row;
		if (player_pos == COLLECTIBLE)
			init_game->game_data.collectible_count--;
		init_game->game_data.move_count++;
	}
	else if (player_pos == EXIT && init_game->game_data.collectible_count == 0)
	{
		you_win(init_game);
		exit_program(init_game);
	}
	return (print_count_moves(init_game));
}

void	start_game(t_game_init *init_game)
{
	mlx_hook(init_game->mlxptr, 17, 0, exit_program, init_game);
	mlx_hook(init_game->winptr, 2, 1L << 0, ft_moves, init_game);
	mlx_loop_hook(init_game->mlxptr, &draw_map, init_game);
}
