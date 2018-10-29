/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:15:36 by vlee              #+#    #+#             */
/*   Updated: 2018/09/12 20:21:13 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"

int	main(void)
{
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 400, "window test");
	mlx_pixel_put(mlx_ptr, win_ptr, 400, 200, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 401, 200, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 402, 200, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 403, 200, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 404, 200, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 399, 200, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 398, 200, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 397, 200, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 396, 200, 0xffffff);
	mlx_pixel_put(mlx_ptr, win_ptr, 395, 200, 0xffffff);
	mlx_loop(mlx_ptr);
}
