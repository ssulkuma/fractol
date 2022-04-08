/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:32:39 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/08 11:00:15 by ssulkuma         ###   ########.fr       */
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
		z.real = ft_fabs(z.real);
		z.imag = ft_fabs(z.imag);
		z = complex_add(complex_mul(z, z), c);
		iteration++;
	}
	if (iteration == mlx->max_iteration)
		draw_pixel_to_image(mlx, x, y, 0x000000);
	else
		draw_pixel_to_image(mlx, x, y, define_color(iteration, mlx));
}

void	*burning_ship_set(void *data)
{
	t_complex	z;
	t_complex	c;
	t_fractal	ship;
	t_thread	*thread;

	thread = (t_thread *)data;
	ship.x = thread->start_x - 1;
	while (ship.x++ < thread->end_x)
	{
		ship.y = -1;
		while (ship.y++ < HEIGHT)
		{
			z.real = 0;
			z.imag = 0;
			c.real = (ship.x + thread->mlx->position_x) / (WIDTH
					/ (thread->mlx->max_real - thread->mlx->min_real))
				+ thread->mlx->min_real;
			c.imag = (ship.y + thread->mlx->position_y) / (HEIGHT
					/ (thread->mlx->max_imag - thread->mlx->min_imag))
				+ thread->mlx->min_imag;
			fractal(&ship, z, c, thread->mlx);
		}
	}
	pthread_exit(NULL);
}
