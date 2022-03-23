/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:14:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/23 14:43:53 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	define_julia(t_julia *julia, int x, int y)
{
	int		iteration;
	double	temp;

	julia->z_real = 2 * julia->depth * (x - WIDTH / 2) / HEIGHT;
	julia->z_imaginary = 2 * julia->depth * (y - HEIGHT / 2) / HEIGHT;
	iteration = 0;
	while ((iteration < julia->max_iteration) && (julia->z_real
			* julia->z_real + julia->z_imaginary * julia->z_imaginary < 4))
	{
		temp = julia->z_real * julia->z_real - julia->z_imaginary
			* julia->z_imaginary + julia->c_real;
		julia->z_imaginary = 2 * julia->z_real * julia->z_imaginary
			+ julia->c_imaginary;
		julia->z_real = temp;
		iteration++;
	}
	return (iteration);
}

static void	julia_struct_intel(t_julia *julia)
{
	julia->max_iteration = 100;
	julia->max_real = 1;
	julia->max_imaginary = 1;
	julia->min_real = -1;
	julia->min_imaginary = -1;
	julia->c_real = -0.8;
	julia->c_imaginary = 0.156;
	julia->depth = julia->min_real - julia->max_real;
}

void	julia_set(t_mlx *mlx)
{
	int		x;
	int		y;
	int		iteration;
	t_julia	julia;

	julia_struct_intel(&julia);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iteration = define_julia(&julia, x, y);
			if (sqrt(julia.z_real * julia.z_real + julia.z_imaginary
					* julia.z_imaginary) > julia.depth)
				draw_pixel_to_image(mlx, x, y, 255 * iteration);
			else
				draw_pixel_to_image(mlx, x, y, 255);
			y++;
		}
		x++;
	}
}
