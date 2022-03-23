/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:24:45 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/23 16:56:11 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	define_newton(t_newton *newton, int x, int y)
{
	int		iteration;
	double	temp;
	double	check;

	iteration = 0;
	newton->z_real = x * 4 / WIDTH - 2;
	newton->z_imaginary = -y * 4 / HEIGHT + 2;
	while (iteration < newton->max_iteration)
	{
		check = fabs(pow(newton->z_real, 3) - 1);
		if (check < 0.0001)
				break;
		check = fabs(pow(newton->z_imaginary, 3) - 1);
		if (check < 0.0001)
				break;
		temp = (newton->z_real - (pow(newton->z_real, 3) - 1)) / (newton->z_real * newton->z_real * 3);
		newton->z_imaginary = (newton->z_imaginary - pow(newton->z_imaginary, 3)) / (newton->z_imaginary * newton->z_imaginary * 3);
		newton->z_real = temp;
		iteration++;
	}
	return (iteration);
}

static void	newton_struct_intel(t_newton *newton)
{
	newton->max_iteration = 100;
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
			if(iteration != newton.max_iteration)
				draw_pixel_to_image(mlx, x, y, 0xFFFFFF);
			else
				draw_pixel_to_image(mlx, x, y, 0x000000);
			y++;
		}
		x++;
	}
}
