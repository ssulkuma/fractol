/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:24:45 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/24 17:58:02 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
static void	newton_function(t_newton *newton)
{
	double	temp;

	temp = pow(newton->z_real, 3) - 1;
	newton->z_imaginary = pow(newton->z_imaginary, 0);
	newton->z_real = temp;
}

static void	newton_derivative(t_newton *newton)
{
	double	temp;

	temp = (newton->z_real * newton->z_real - newton->z_imaginary * newton->z_imaginary) * 3;
	newton->z_imaginary = (newton->z_real * newton->z_imaginary + newton->z_imaginary * newton->z_real) * 3;
	newton->z_real = temp;
}
*/
static int	define_newton(t_newton *newton, int x, int y)
{
	int		iteration;
	double	real_range;
	double	imaginary_range;
	double	temp;

	iteration = 0;
	real_range = (newton->max_real - newton->min_real) / WIDTH;
	imaginary_range = (newton->max_imaginary - newton->min_imaginary) / HEIGHT;
	newton->z_real = newton->min_real + real_range * x;
	newton->z_imaginary = newton->min_imaginary + imaginary_range * y;
	//printf("%f\n", newton->z_real);
	//printf("%f\n\n", newton->z_imaginary);
	while (iteration < newton->max_iteration)
	{
		if (fabs((pow(newton->z_real, 3) - 1)) < newton->tolerance || abs((pow(newton->z_imaginary, 0) < newton->tolerance)))
			break ;
		temp = (newton->z_real - (pow(newton->z_real, 3) - 1)) / ((newton->z_real * newton->z_real - newton->z_imaginary * newton->z_imaginary) * 3);
		newton->z_imaginary = (newton->z_imaginary - pow(newton->z_imaginary, 0)) / (newton->z_real * newton->z_imaginary + newton->z_imaginary * newton->z_real) * 3;
		newton->z_real = temp;
		//printf("%f\n", newton->z_real);
		//printf("%f\n\n", newton->z_imaginary);
		iteration++;
	}
	return (iteration);
}

static void	newton_struct_intel(t_newton *newton)
{
	newton->tolerance = 0.000001;
	newton->max_iteration = 100;
	newton->root_1_real = 1;
	newton->root_2_real = -0.5;
	newton->root_3_real = -0.5;
	newton->root_1_imaginary = 0;
	newton->root_2_imaginary = sqrt(3) / 2;
	newton->root_3_imaginary = -sqrt(3) / 2;
	newton->max_real = 1;
	newton->max_imaginary = 1;
	newton->min_real = -2.5;
	newton->min_imaginary = -1;
}

void	newton_set(t_mlx *mlx)
{
	int			x;
	int			y;
	int			iteration;
	t_newton	newton;

	newton_struct_intel(&newton);
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			iteration = define_newton(&newton, x, y);
			//printf("%d\n", iteration);
			if (fabs(newton.z_real - newton.root_1_real) < newton.tolerance)
				draw_pixel_to_image(mlx, x, y, 0x00FF00 * iteration);
			else if (fabs(newton.z_imaginary - newton.root_1_imaginary) < newton.tolerance)
				draw_pixel_to_image(mlx, x, y, 0x00FF00 * iteration);
			else if (fabs(newton.z_real - newton.root_2_real) < newton.tolerance)
				draw_pixel_to_image(mlx, x, y, 0xFF0000 * iteration);
			else if (fabs(newton.z_imaginary - newton.root_2_imaginary) < newton.tolerance)
				draw_pixel_to_image(mlx, x, y, 0xFF0000 * iteration);
			else
				draw_pixel_to_image(mlx, x, y, 0x0000FF * iteration);
			y++;
		}
		x++;
	}
}
