/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liulm <liulm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 08:38:36 by lionelulm         #+#    #+#             */
/*   Updated: 2025/02/19 15:44:29 by liulm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_line(int fd)
{
	int		i;
	int		count;
	char	buffer[BUFFER_SIZE];
	ssize_t	nb;

	count = 0;
	while (1)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb < 0)
			return (0);
		if (nb == 0)
			break ;
		i = 0;
		while (i < nb)
		{
			if (buffer[i] == '\n')
				count++;
			i++;
		}
	}
	count++;
	return (count);
}

int	count_read_map(char *map)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	i = count_line(fd);
	if (close(fd) == -1)
		return (0);
	return (i);
}

int	read_checker(t_game_init *init_game)
{
	if (init_game->map_data.mat[0] == NULL
		|| !map_dimension(init_game)
		|| !is_map_valid(init_game))
	{
		free_map(init_game);
		return (0);
	}
	return (1);
}

int	read_map(int fd, t_game_init *init_game)
{
	int		i;
	char	*line;

	init_game->map_data.mat
		= ft_calloc(init_game->map_data.first_mat + 1, sizeof(char *));
	if (!init_game->map_data.mat)
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
		init_game->map_data.mat[i] = line;
		i++;
	}
	if (!read_checker(init_game))
		return (0);
	return (1);
}

int	open_map(char *map, t_game_init *init_game)
{
	int		fd;

	if (!map_extension(map))
		return (0);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	init_game->map_data.first_mat = count_read_map(map);
	if (!init_game->map_data.first_mat || init_game->map_data.first_mat < 3
		|| init_game->map_data.first_mat > 101)
	{
		close(fd);
		free_map(init_game);
		return (0);
	}
	if (!read_map(fd, init_game))
	{
		close(fd);
		free_map(init_game);
		return (0);
	}
	close (fd);
	return (1);
}
