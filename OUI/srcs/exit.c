/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:50:05 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/18 20:42:49 by lulm             ###   ########.fr       */
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

void	free_map(t_game_init *init_game)
{
	int	i;

	if (init_game->map_data.matrice == NULL)
		return ;
	i = 0;
	while (init_game->map_data.matrice[i])
	{
		free(init_game->map_data.matrice[i]);
		i++;
	}
	free(init_game->map_data.matrice);
	init_game->map_data.matrice = NULL;
	return ;
}

void	free_image(t_game_init *init_game)
{
	mlx_destroy_image(init_game->mlxptr, init_game->init_obj.player);
	mlx_destroy_image(init_game->mlxptr, init_game->init_obj.wall);
	mlx_destroy_image(init_game->mlxptr, init_game->init_obj.floor);
	mlx_destroy_image(init_game->mlxptr, init_game->init_obj.collectible);
	mlx_destroy_image(init_game->mlxptr, init_game->init_obj.exit_open);
	mlx_destroy_image(init_game->mlxptr, init_game->init_obj.exit_close);
	init_game->init_obj = (t_game_obj){0};
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

void	you_win(t_game_init *init_game)
{
	init_game->map_data.matrice[init_game->init_pos.row]
	[init_game->init_pos.col] = FLOOR;
	init_game->game_data.move_count++;
	ft_printf("You won, congrats!\n");
	exit_program(init_game);
}

//===========finished===========//
