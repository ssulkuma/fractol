/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_julia.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:34:48 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/25 17:04:15 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_julia(t_julia *julia, t_complex z, t_complex c, t_mlx *mlx)
{
	int	x;
	int	y;
	int	iteration;

	x = julia->x;
	y = julia->y;
	iteration = 0;
	while (iteration < julia->max_iteration && complex_abs(z) < 4)
	{
		z = complex_add(complex_mul(z, z), c);
		iteration++;
	}
	if (iteration != julia->max_iteration)
		draw_pixel_to_image(mlx, x, y, iteration * 15);
	else
		draw_pixel_to_image(mlx, x, y, 0x000000);
}

static void	julia_struct_intel(t_julia *julia)
{
	julia->max_iteration = 150;
	julia->max_real = 0.5;
	julia->max_imag = 0.5;
	julia->min_real = -0.5;
	julia->min_imag = -0.5;
}

void	julia_set(t_mlx *mlx)
{
	t_complex	z;
	t_complex	c;
	t_julia		julia;

	julia_struct_intel(&julia);
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
			c.real = -0.8;
			c.imag = 0.156;
			draw_julia(&julia, z, c, mlx);
			julia.y++;
		}
		julia.x++;
	}
}
