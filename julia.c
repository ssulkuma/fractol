/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:34:48 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/01 15:38:26 by ssulkuma         ###   ########.fr       */
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

void	julia_set(t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_fractal	julia;

	if (mlx->max_iteration < 10)
		mlx->max_iteration = 10;
	julia.x = 0;
	while (julia.x < WIDTH)
	{
		julia.y = 0;
		while (julia.y < HEIGHT)
		{
			z.real = julia.x / (HEIGHT / (mlx->max_real - mlx->min_real))
				+ mlx->min_real;
			z.imag = julia.y / (HEIGHT / (mlx->max_imag - mlx->min_imag))
				+ mlx->min_imag;
			c.real = mlx->mouse_x;
			c.imag = mlx->mouse_y;
			fractal(&julia, z, c, mlx);
			julia.y++;
		}
		julia.x++;
	}
}
