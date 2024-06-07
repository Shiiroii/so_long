/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulm <lulm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:04:28 by lionelulm         #+#    #+#             */
/*   Updated: 2024/06/07 17:25:01 by lulm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t*	mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "42", true);
	if (!mlx)
		ft_error();
	// ajouter ce qui est necessaire

	mlx_image_t*	img;

	img = mlx_new_image(mlx, 256, 256); //changer a la taille du fichier
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	mlx_looh_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS)
}
