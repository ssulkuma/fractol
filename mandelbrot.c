/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_mandelbrot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:31:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/25 16:10:13 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	mandelbrot(t_mandel *mandel, t_complex z, t_complex c, t_mlx *mlx)
{
	int	x;
	int	y;
	int	iteration;

	x = mandel->x;
	y = mandel->y;
	iteration = 0;
	while (iteration < mandel->max_iteration && complex_abs(z) < 4)
	{
		z = complex_add(complex_mul(z, z), c);
		iteration++;
	}
	if (iteration == mandel->max_iteration)
		draw_pixel_to_image(mlx, x, y, 0x000000);
	else
		draw_pixel_to_image(mlx, x, y, 500 * iteration / 50);
}

static void	mandel_struct_intel(t_mandel *mandel)
{
	mandel->max_iteration = 100;
	mandel->max_real = 1;
	mandel->max_imag = 1;
	mandel->min_real = -2;
	mandel->min_imag = -1;
}

void	mandelbrot_set(t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_mandel	mandel;

	mandel_struct_intel(&mandel);
	mandel.x = 0;
	while (mandel.x < WIDTH)
	{
		mandel.y = 0;
		while (mandel.y < HEIGHT)
		{
			z.real = 0;
			z.imag = 0;
			c.real = (mandel.max_real - mandel.min_real) / WIDTH * mandel.x
				+ mandel.min_real;
			c.imag = (mandel.max_imag - mandel.min_imag) / HEIGHT * mandel.y
				+ mandel.min_imag;
			mandelbrot(&mandel, z, c, mlx);
			mandel.y++;
		}
		mandel.x++;
	}
}
