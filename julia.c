/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:14:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/23 13:04:03 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	define_julia(t_mlx *mlx, t_julia *julia, int x, int y)
{
	int		iteration;
	double	temp;

	julia->z_real = 2 * julia->depth * (x - WIDTH / 2) / HEIGHT;
	julia->z_imaginary = 2 * julia->depth * (y - HEIGHT / 2) / HEIGHT;
	iteration = 1;
	while (iteration <= julia->max_iteration)
	{
		temp = julia->z_real * julia->z_real - julia->z_imaginary * julia->z_imaginary + julia->c_real;
		julia->z_imaginary = 2 * julia->z_real * julia->z_imaginary + julia->c_imaginary;
		julia->z_real = temp;
		if (sqrt(julia->z_real * julia->z_real + julia->z_imaginary * julia->z_imaginary) > julia->depth)
		{
			draw_pixel_to_image(mlx, x, y, 255 * iteration);
			break ;
		}
		iteration++;
	}
	if (iteration > julia->max_iteration)
		draw_pixel_to_image(mlx, x, y, 0x000000);
}

static void	julia_struct_intel(t_julia *julia)
{
	julia->max_iteration = 100;
	julia->c_real = -0.70176;
	julia->c_imaginary = -0.3842;
	julia->depth = 5;
}

void	julia_set(t_mlx *mlx)
{
	int		x;
	int		y;
	t_julia	julia;

	julia_struct_intel(&julia);
	x = 0;
	while (x <= WIDTH)
	{
		y = 0;
		while (y <= HEIGHT)
		{
			define_julia(mlx, &julia, x, y);
			y++;
		}
		x++;
	}
}
