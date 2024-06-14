/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:38:05 by lulm              #+#    #+#             */
/*   Updated: 2024/06/14 17:54:19 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map_temp(t_game_init *init_game)
{
	int	i;

	i = -1;
	while (++i < init_game->map_data.first_mat)
		free(init_game->map_data_temp.matrice[i]);
	free(init_game->map_data_temp.matrice);
}

int	copy_map(t_game_init *init_game)
{
	int	i;
	int	j;

	init_game->map_data_temp.matrice
		= ft_calloc(init_game->map_data.first_mat + 1, sizeof(char *));
	if (!init_game->map_data_temp.matrice)
		return (0);
	i = -1;
	while (++i < init_game->map_data.first_mat)
	{
		init_game->map_data_temp.matrice[i]
			= ft_strdup(init_game->map_data.matrice[i]);
		if (!init_game->map_data_temp.matrice[i])
		{
			j = -1;
			while (++j < i)
				free(init_game->map_data_temp.matrice[j]);
			free(init_game->map_data_temp.matrice);
			return (0);
		}
	}
	return (1);
}
