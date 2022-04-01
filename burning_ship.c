/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:32:39 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/01 17:54:40 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal(t_fractal *ship, t_complex z, t_complex c, t_mlx *mlx)
{
	int	x;
	int	y;
	int	iteration;

	x = ship->x;
	y = ship->y;
	iteration = 0;
	while (iteration < mlx->max_iteration && complex_abs(z) < 4)
	{
		z = ;
		iteration++;
	}
	if (iteration == mlx->max_iteration)
		draw_pixel_to_image(mlx, x, y, 0x000000);
	else
		draw_pixel_to_image(mlx, x, y, define_color(iteration, mlx));
}

void	burning_ship_set(t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_fractal	ship;

	if (mlx->max_iteration < 10)
		mlx->max_iteration = 10;
	ship.x = 0;
	while (ship.x < WIDTH)
	{
		ship.y = 0;
		while (ship.y < HEIGHT)
		{
			z.real = 0;
			z.imag = 0;
			c.real = (ship.x + mlx->position_x) / (WIDTH
					/ (mlx->max_real - mlx->min_real)) + mlx->min_real;
			c.imag = (ship.y + mlx->position_y) / (HEIGHT
					/ (mlx->max_imag - mlx->min_imag)) + mlx->min_imag;
			fractal(&ship, z, c, mlx);
			ship.y++;
		}
		ship.x++;
	}
}
