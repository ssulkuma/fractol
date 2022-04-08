/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:31:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/08 11:39:49 by ssulkuma         ###   ########.fr       */
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

void	*mandelbrot_set(void *data)
{
	t_complex	z;
	t_complex	c;
	t_fractal	mandel;
	t_thread	*thread;

	thread = (t_thread *)data;
	mandel.x = thread->start_x - 1;
	while (mandel.x++ < thread->end_x)
	{
		mandel.y = -1;
		while (mandel.y++ < HEIGHT)
		{
			z.real = 0;
			z.imag = 0;
			c.real = (mandel.x + thread->mlx->position_x) / (WIDTH
					/ (thread->mlx->max_real - thread->mlx->min_real))
				+ thread->mlx->min_real;
			c.imag = (mandel.y + thread->mlx->position_y) / (HEIGHT
					/ (thread->mlx->max_imag - thread->mlx->min_imag))
				+ thread->mlx->min_imag;
			fractal(&mandel, z, c, thread->mlx);
		}
	}
	pthread_exit(NULL);
}
