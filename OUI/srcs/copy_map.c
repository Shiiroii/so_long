/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:38:05 by lulm              #+#    #+#             */
/*   Updated: 2024/06/18 21:28:31 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_copy_map(t_game_init *init_game)
{
	int	i;

	if (init_game->map_data_temp.matrice == NULL)
		return ;
	i = 0;
	while (init_game->map_data_temp.matrice[i])
	{
		free(init_game->map_data_temp.matrice[i]);
		i++;
	}
	free(init_game->map_data_temp.matrice);
	init_game->map_data_temp.matrice = NULL;
	return ;
}

int	copy_map(t_game_init *init_game)
{
	int	i;

	i = 0;
	while (init_game->map_data.matrice[i])
		i++;
	init_game->map_data_temp.matrice
		= ft_calloc(init_game->map_data_temp.first_mat
			+ (i + 1), sizeof(char *));
	if (init_game->map_data_temp.matrice == NULL)
	{
		error_map(1);
		return (0);
	}
	i = 0;
	while (init_game->map_data.matrice[i])
	{
		init_game->map_data_temp.matrice[i]
			= ft_strdup(init_game->map_data.matrice[i]);
		if (init_game->map_data_temp.matrice[i] == NULL)
		{
			free_copy_map(init_game);
			error_map(1);
			return(0);
		}
		i++;
	}
	init_game->map_data_temp.row_mat = init_game->map_data.row_mat;
	init_game->map_data_temp.col_mat = init_game->map_data.col_mat;
	if (init_game->init_obj.collectible == NULL)
	{
		free_copy_map(init_game);
		error_map(1);
		return (0);
	}
	return (1);
}
