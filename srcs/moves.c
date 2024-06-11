/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:21:06 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/11 11:55:58 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_esc(int key, t_game_init *init_game)
{
	if (key == ESC)
		exit_program(init_game);
	return (0);
}

int	ft_moves(int key, t_game_init *init_game)
{
	ft_esc(key, init_game);
	if (key == UP || key == W)
	{
		init_game->init_obj.player = init_game->init_obj.player_up;
		ft_moving(init_game, 0, -1);
	}
	if (key == DOWN || key == S)
	{
		init_game->init_obj.player = init_game->init_obj.player_down;
		ft_moving(init_game, 0, +1);
	}
	if (key == LEFT || key == A)
	{
		init_game->init_obj.player = init_game->init_obj.player_left;
		ft_moving(init_game, -1, 0);
	}
	if (key == RIGHT || key == D)
	{
		init_game->init_obj.player = init_game->init_obj.player_right;
		ft_moving(init_game, +1, 0);
	}
	return (0);
}
