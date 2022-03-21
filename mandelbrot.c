/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:56:27 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/21 19:39:38 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*z = z*z + c*/

static int	define_mandelbrot(t_mandel *mandel, t_mlx *mlx)
{
	double	temp;
	int		iteration;

	iteration = 0;
	mandel->z_real = 0;
	mandel->z_imaginary;
	while ((iteration < mandel->max_iteration)
		&& (mandel->z_real * mandel->z_real + mandel->z_imaginary * mandel->z_imaginary < 4))
	{
		temp = mandel->z_real * mandel->z_real - mandel->z_imaginary * mandel->z_imaginary + mandel->c_real;
		mandel->z_imaginary = 2 * mandel->z_real * mandel->z_imaginary + mandel->c_imaginary;
		mandel->z_real = temp;
		iteration++;
	}
	return (iteration);
}

static void	complex_number(t_mandel *mandel, int x, int y)
{
	double	real_range;
	double	imaginary_range;

	real_range = mandel->max_real - mandel->min_real / WIDTH;
	imaginary_range = mandel->max_imaginary - mandel->min_imaginary / HEIGHT;
	mandel->c_real = x * real_range + mandel->min_real;
	mandel->c_imaginary = y * imaginary_range + mandel->min_imaginary;
}

void	mandelbrot_set(t_mlx *mlx)
{
	int			x;
	int			y;
	int			iteration;
	t_mandel	mandel;

	mandel.max_iteration = 30;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			complex_number(&mandel, x, y);
			iteration = define_mandelbrot(&mandel, mlx);
			if (iteration == mandel.max_iteration)
				mlx->color = 0x000000;
			else
				mlx->color = 0x0000FF * iteration / 100;

			y++;
		}
		x++;
	}
}
