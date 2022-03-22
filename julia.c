/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:14:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/22 16:13:33 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	define_julia(t_julia *julia)
{
	double	temp;
	int		iteration;

	iteration = 0;
	julia->z_real = 0;
	julia->z_imaginary = 0;
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
	julia->max_iteration = 50;
	julia->c_real = 0.285;
	julia->c_imaginary = 0.01;
	julia->max_real = 2;
	julia->max_imaginary = 2;
	julia->min_real = -2;
	julia->min_imaginary = -2;
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
			iteration = define_julia(&julia);
			if (iteration == julia.max_iteration)
				draw_pixel_to_image(mlx, x, y, 0x000000);
			else
				draw_pixel_to_image(mlx, x, y, mlx->color * iteration);
			y++;
		}
		x++;
	}
}
