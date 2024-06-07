/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:49:49 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/07 14:52:28 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	doubles()
{
	if (EXIT == 2)
	{
		ft_putstr_fd("Error: Double exit\n", 2);
		exit(1);
	}
	if (PLAYER == 2)
	{
		ft_putstr_fd("Error: Double player\n", 2);
		exit(1);
	}
}
