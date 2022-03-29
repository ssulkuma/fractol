/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:45:37 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/29 14:18:01 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = mlx->address + (y * mlx->line_len + \
			x * (mlx->bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

void	draw(t_mlx *mlx)
{
	mlx->image = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
	mlx->address = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel,
			&mlx->line_len, &mlx->endian);
	if (mlx->fractal == 1)
		julia_set(mlx);
	if (mlx->fractal == 2)
		mandelbrot_set(mlx);
	if (mlx->fractal == 3)
		newton_set(mlx);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->image, 0, 0);
	if (mlx->menu == 1)
		menu(mlx);
	else
		mlx_string_put(mlx->connection, mlx->window, 25, 20, 0xFFFFFF, "Menu [H]");
}
