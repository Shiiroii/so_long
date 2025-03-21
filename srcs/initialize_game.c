/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_game.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 09:14:13 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/19 15:44:40 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	image_checker(t_game_init *init_game, void **image, char *path)
{
	int	height;
	int	width;

	*image = mlx_xpm_file_to_image(init_game->mlxptr, path, &width, &height);
	if (*image == NULL)
	{
		error_map(5);
		exit_program(init_game);
	}
}

void	image_init(t_game_init *init_game)
{
	image_checker(init_game, &init_game->init_obj.player,
		"./textures/player.xpm");
	image_checker(init_game, &init_game->init_obj.wall,
		"./textures/wall.xpm");
	image_checker(init_game, &init_game->init_obj.floor,
		"./textures/floor.xpm");
	image_checker(init_game, &init_game->init_obj.collectible,
		"./textures/collectible.xpm");
	image_checker(init_game, &init_game->init_obj.exit_close,
		"./textures/exit_close.xpm");
	image_checker(init_game, &init_game->init_obj.exit_open,
		"./textures/exit_open.xpm");
}

void	initialize_game(t_game_init	*init_game)
{
	init_game->mlxptr = mlx_init();
	if (!init_game->mlxptr)
		error_map(4);
	init_game->game_data.move_count = 0;
	image_init(init_game);
	init_game->winptr = mlx_new_window(init_game->mlxptr,
			init_game->map_data.res.width * IMG_SIZE,
			init_game->map_data.res.height * IMG_SIZE, "so_long");
	if (!init_game->winptr)
		error_map(4);
}
