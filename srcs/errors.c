/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:49:49 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/08 10:19:17 by lionelulm        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_map(int nb)
{
	if (nb == 1)
		ft_printf("%sError: This is not a valid file. \n");
	if (nb == 2)
		ft_printf("%sError: Usage: ./so_long <filename.ber>. \n");
	if (nb == 3)
		ft_printf("%sError: Invalid map. \n");
	exit (nb);
}

void	error_init(int nb)
{
	if (nb == 1)
		ft_printf("%sError: Incompatible library. \n");
	if (nb == 2)
		ft_printf("%sError: Permission denied. \n");
	if (nb == 3)
		ft_printf("%sError: File not found. \n");
	exit (nb);
}

//===========BWAH===========//
