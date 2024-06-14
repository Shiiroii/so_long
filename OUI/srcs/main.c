/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:04:28 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/14 18:04:59 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_struct(t_game_init *game)
{
	t_game_obj	*game_obj;

	*game = (t_game_init){0};
	game->mlxptr = NULL;
	game->winptr = NULL;
	game->map_data.matrice = NULL;
	game->map_data_temp.matrice = NULL;
	game->init_res.name_map = NULL;
	game->init_res.name_window = NULL;
	game_obj = malloc(sizeof(t_game_obj));
	if (game_obj == NULL)
		error_map(1);
	game->init_obj = *game_obj;
	free (game_obj);
	return ;
}

int	main(int argc, char **argv)
{
	t_game_init	game;

	initialize_struct(&game);
	if (argc != 2)
		error_map(2);
	game.argc_temp = argc;
	game.argv_temp = argv;
	if (!copy_map(&game))
		error_map(1);
	if (open_map(argv[1], &game))
	{
		initialize_game(&game);
		start_game(&game);
		mlx_loop(game.mlxptr);
	}
	else
		error_map(3);
	exit_program(&game);
	return (0);
}

//===========finished===========//
