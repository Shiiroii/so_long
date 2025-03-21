/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 08:22:33 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/04 15:34:55 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	row_count(t_game_init *init_game)
{
	int	i;
	int	len;

	i = 0;
	while (init_game->map_data.mat[i])
	{
		len = ft_strlen(init_game->map_data.mat[i])
			- (init_game->map_data.mat[i]
			[ft_strlen(init_game->map_data.mat[i]) - 1] == '\n');
		if (len != init_game->map_data.col_mat)
		{
			init_game->map_data.row_mat = 0;
			return (0);
		}
		init_game->map_data.row_mat++;
		i++;
	}
	init_game->map_data.size_mat = init_game->map_data.row_mat
		* init_game->map_data.col_mat;
	init_game->map_data.res.width = init_game->map_data.col_mat;
	init_game->map_data.res.height = init_game->map_data.row_mat;
	return (1);
}

int	col_count(t_map_data *init_map)
{
	char	*row;
	int		i;

	row = init_map->mat[0];
	i = 0;
	while (*row && *row != '\n')
	{
		i++;
		row++;
	}
	return (i);
}

int	map_dimension(t_game_init *init_game)
{
	init_game->map_data.col_mat = col_count(&init_game->map_data);
	if (init_game->map_data.col_mat == 0)
		return (0);
	return (row_count(init_game));
}

int	map_extension(char *map)
{
	static int	i;
	char		*extension;
	char		*extension_file;

	i = 0;
	extension = ".ber";
	extension_file = ft_strrchr(map, '.');
	if (map[ft_strlen(map) - 1] == '/')
	{
		error_map(1);
		return (0);
	}
	else if (!extension_file || !ft_strcmp(extension_file, ""))
		return (0);
	else if (extension_file && !ft_strcmp(extension_file, extension))
	{
		if (i >= FILES)
			return (0);
		i++;
	}
	else
		return (0);
	return (1);
}

//===========finished===========//
