/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:38:05 by lulm              #+#    #+#             */
/*   Updated: 2024/06/21 16:09:48 by lulm             ###   ########.fr       */
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

int	utils_copy_map(t_game_init *init_game)
{
	int	i;

	i = 0;
	while (init_game->map_data.matrice[i])
	{
		init_game->map_data_temp.matrice[i]
			= ft_strdup(init_game->map_data.matrice[i]);
		if (init_game->map_data_temp.matrice[i] == NULL)
		{
			free_copy_map(init_game);
			error_map(1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	copy_map(t_game_init *init_game)
{
	int	i;

	i = 0;
	while (init_game->map_data.matrice[i])
		i++;
	init_game->map_data_temp.matrice
		= ft_calloc(init_game->map_data.first_mat + 1, sizeof(char *));
	if (init_game->map_data_temp.matrice == NULL)
	{
		error_map(1);
		return (0);
	}
	utils_copy_map(init_game);
	init_game->map_data_temp.matrice[i] = NULL;
	return (1);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}
