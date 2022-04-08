/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:34:48 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/08 13:46:09 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal(t_fractal *julia, t_complex z, t_complex c, t_mlx *mlx)
{
	int	x;
	int	y;
	int	iteration;

	x = julia->x;
	y = julia->y;
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

void	*julia_set(void *data)
{
	t_complex	z;
	t_complex	c;
	t_fractal	julia;
	t_thread	*thread;

	thread = (t_thread *)data;
	julia.x = thread->start_x - 1;
	while (julia.x++ < thread->end_x)
	{
		julia.y = -1;
		while (julia.y++ < HEIGHT)
		{
			z.real = (julia.x + thread->mlx->position_x) / (WIDTH
					/ (thread->mlx->max_real - thread->mlx->min_real))
				+ thread->mlx->min_real;
			z.imag = (julia.y + thread->mlx->position_y) / (HEIGHT
					/ (thread->mlx->max_imag - thread->mlx->min_imag))
				+ thread->mlx->min_imag;
			c.real = thread->mlx->mouse_x;
			c.imag = thread->mlx->mouse_y;
			fractal(&julia, z, c, thread->mlx);
		}
	}
	pthread_exit(NULL);
}
