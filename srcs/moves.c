/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:21:06 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/08 10:26:03 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_esc_and_restart(int key, t_game_init *init_game)
{
	if (key == ESC)
		exit_program(init_game);
	else if (key == RESTART)
		restart(init_game);
	return (0);
}

int	ft_moves(int key, t_game_init *init_game)
{
	ft_esc_and_restart(key, init_game);
	if (key == UP || key == W)
		ft_moving(init_game, 0, -1);
	if (key == DOWN || key == S)
		ft_moving(init_game, 0, +1);
	if (key == LEFT || key == A)
		ft_moving(init_game, -1, 0);
	if (key == RIGHT || key == D)
		ft_moving(init_game, +1, 0);
	return (0);
}
