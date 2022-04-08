/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:24:45 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/08 13:35:13 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	newton_func(t_complex z)
{
	t_complex	one;

	one.real = 1;
	one.imag = 0;
	return (complex_sub(complex_pow(z, 3), one));
}

static	t_complex	newton_deri(t_complex z)
{
	t_complex	three;

	three.real = 3;
	three.imag = 0;
	return (complex_mul(complex_mul(z, z), three));
}

static void	fractal(t_fractal *newton, t_complex z, t_complex *root, t_mlx *mlx)
{
	int	x;
	int	y;
	int	iteration;

	x = newton->x;
	y = newton->y;
	iteration = 0;
	while (complex_abs(complex_sub(z, root[0])) > newton->tolerance
		&& complex_abs(complex_sub(z, root[1])) > newton->tolerance
		&& complex_abs(complex_sub(z, root[2])) > newton->tolerance
		&& iteration < mlx->max_iteration)
	{
		z = complex_sub(z, complex_div(newton_func(z), newton_deri(z)));
		iteration++;
	}
	if (complex_abs(complex_sub(z, root[0])) < newton->tolerance)
		draw_pixel_to_image(mlx, x, y, define_root0_color(iteration, mlx));
	else if (complex_abs(complex_sub(z, root[1])) < newton->tolerance)
		draw_pixel_to_image(mlx, x, y, define_root1_color(iteration, mlx));
	else if (complex_abs(complex_sub(z, root[2])) < newton->tolerance)
		draw_pixel_to_image(mlx, x, y, define_root2_color(iteration, mlx));
}

static void	newton_struct_intel(t_mlx *mlx, t_complex *root, t_fractal *newton)
{
	root[0].real = 1;
	root[0].imag = 0;
	root[1].real = -0.5;
	root[1].imag = sqrt(3) / 2;
	root[2].real = -0.5;
	root[2].imag = -sqrt(3) / 2;
	newton->tolerance = 0.000001;
	if (mlx->max_iteration < 5)
		mlx->max_iteration = 5;
}

void	*newton_set(void *data)
{
	t_complex	z;
	t_complex	root[3];
	t_fractal	newton;
	t_thread	*thread;

	thread = (t_thread *)data;
	newton_struct_intel(thread->mlx, root, &newton);
	newton.x = thread->start_x;
	while (newton.x < thread->end_x)
	{
		newton.y = 0;
		while (newton.y < HEIGHT)
		{
			z.real = (newton.x + thread->mlx->position_x) / (WIDTH
					/ (thread->mlx->max_real - thread->mlx->min_real))
				+ thread->mlx->min_real;
			z.imag = (newton.y + thread->mlx->position_y) / (HEIGHT
					/ (thread->mlx->max_imag - thread->mlx->min_imag))
				+ thread->mlx->min_imag;
			fractal(&newton, z, root, thread->mlx);
			newton.y++;
		}
		newton.x++;
	}
	pthread_exit(NULL);
}
