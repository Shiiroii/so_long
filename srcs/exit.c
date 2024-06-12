/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:50:05 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/12 17:02:38 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	clean_all(t_game_init *init_game)
{
	if (init_game->init_res.name_window != NULL)
	{
		free(init_game->init_res.name_window);
		init_game->init_res.name_window = NULL;
	}
	if (init_game->init_res.name_map != NULL)
	{
		free(init_game->init_res.name_map);
		init_game->init_res.name_map = NULL;
	}
}

int	exit_program(t_game_init *init_game)
{
	free_image(init_game);
	free_map(init_game);
	clean_all(init_game);
	mlx_destroy_window(init_game->mlxptr, init_game->winptr);
	mlx_destroy_display(init_game->mlxptr);
	free(init_game->mlxptr);
	exit(0);
	return (0);
}

//===========BWAH===========//
