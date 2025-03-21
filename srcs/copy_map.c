/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:38:05 by lulm              #+#    #+#             */
/*   Updated: 2025/02/04 15:35:22 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_copy_map(t_game_init *init_game)
{
	int	i;

	if (init_game->map_data_t.mat == NULL)
		return ;
	i = 0;
	while (init_game->map_data_t.mat[i])
	{
		free(init_game->map_data_t.mat[i]);
		i++;
	}
	free(init_game->map_data_t.mat);
	init_game->map_data_t.mat = NULL;
	return ;
}

int	utils_copy_map(t_game_init *init_game)
{
	int	i;

	i = 0;
	while (init_game->map_data.mat[i])
	{
		init_game->map_data_t.mat[i]
			= ft_strdup(init_game->map_data.mat[i]);
		if (init_game->map_data_t.mat[i] == NULL)
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
	while (init_game->map_data.mat[i])
		i++;
	init_game->map_data_t.mat
		= ft_calloc(init_game->map_data.first_mat + 1, sizeof(char *));
	if (init_game->map_data_t.mat == NULL)
	{
		error_map(1);
		return (0);
	}
	utils_copy_map(init_game);
	init_game->map_data_t.mat[i] = NULL;
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
