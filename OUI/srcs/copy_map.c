/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:38:05 by lulm              #+#    #+#             */
/*   Updated: 2024/06/18 19:24:18 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	copy_read_map(int fd, t_game_init *init_game, char **tab)
{
	int		i;
	char	*line;

	init_game->map_data_temp.matrice
		= ft_calloc(init_game->map_data_temp.first_mat + 1, sizeof(char *));
	if (!init_game->map_data_temp.matrice)
	{
		free_map(init_game);
		return (0);
	}
	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		init_game->map_data_temp.matrice[i] = line;
		i++;
	}
	if (!read_checker(init_game))
		return (0);
	return (1);
}
