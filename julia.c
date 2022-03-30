/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:34:48 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/30 11:55:34 by ssulkuma         ###   ########.fr       */
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
	if (iteration != mlx->max_iteration)
		draw_pixel_to_image(mlx, x, y, define_color(iteration, mlx));
	else
		draw_pixel_to_image(mlx, x, y, 0x000000);
}

static void	julia_struct_intel(t_mlx *mlx, t_fractal *julia)
{
	julia->max_real = 0.5;
	julia->max_imag = 0.5;
	julia->min_real = -0.5;
	julia->min_imag = -0.5;
	if (mlx->max_iteration < 10)
		mlx->max_iteration = 10;
}

void	julia_set(t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_fractal	julia;

	julia_struct_intel(mlx, &julia);
	julia.x = 0;
	while (julia.x < WIDTH)
	{
		julia.y = 0;
		while (julia.y < HEIGHT)
		{
			z.real = 2 * (julia.max_real - julia.min_real)
				* (julia.x - WIDTH / 2) / HEIGHT;
			z.imag = 2 * (julia.max_imag - julia.min_imag)
				* (julia.y - HEIGHT / 2) / HEIGHT;
			c.real = mlx->mouse_x;
			c.imag = mlx->mouse_y;
			fractal(&julia, z, c, mlx);
			julia.y++;
		}
		julia.x++;
	}
}
