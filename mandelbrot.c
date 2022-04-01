/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:31:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/01 16:54:56 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal(t_fractal *mandel, t_complex z, t_complex c, t_mlx *mlx)
{
	int	x;
	int	y;
	int	iteration;

	x = mandel->x;
	y = mandel->y;
	iteration = 0;
	while (iteration < mlx->max_iteration && complex_abs(z) < 4)
	{
		z = complex_add(complex_mul(z, z), c);
		iteration++;
	}
	if (iteration == mlx->max_iteration)
		draw_pixel_to_image(mlx, x, y, 0x000000);
	else
		draw_pixel_to_image(mlx, x, y, define_color(iteration, mlx));
}

void	mandelbrot_set(t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_fractal	mandel;

	if (mlx->max_iteration < 10)
		mlx->max_iteration = 10;
	mandel.x = 0;
	while (mandel.x < WIDTH)
	{
		mandel.y = 0;
		while (mandel.y < HEIGHT)
		{
			z.real = 0;
			z.imag = 0;
			c.real = (mandel.x + mlx->position_x) / (WIDTH
					/ (mlx->max_real - mlx->min_real)) + mlx->min_real;
			c.imag = (mandel.y + mlx->position_y) / (HEIGHT
					/ (mlx->max_imag - mlx->min_imag)) + mlx->min_imag;
			fractal(&mandel, z, c, mlx);
			mandel.y++;
		}
		mandel.x++;
	}
}
