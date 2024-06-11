/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:49:49 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/11 16:43:08 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_map(int nb)
{
	if (nb == 1)
		ft_printf("Error: This is not a valid file. \n");
	if (nb == 2)
		ft_printf("Error: Usage: ./so_long <filename.ber>. \n");
	if (nb == 3)
		ft_printf("Error: Invalid map. \n");
	exit (nb);
}

void	error_init(int nb)
{
	if (nb == 1)
		ft_printf("Error: Incompatible library. \n");
	if (nb == 2)
		ft_printf("Error: Permission denied. \n");
	if (nb == 3)
		ft_printf("Error: File not found. \n");
	exit (nb);
}

//===========BWAH===========//
