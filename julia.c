/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:14:28 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/22 16:53:34 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	define_julia(t_julia *julia)
{
	double	real_range;
	double	imaginary_range;

	real_range = julia->max_real - julia->min_real;
	imaginary_range = julia->max_imaginary - julia->min_imaginary;

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
	julia->depth = 100;
}

void	julia_set(t_mlx *mlx)
{
	int		x;
	int		y;
	int		iteration;
	t_julia	julia;

	julia_struct_intel(&julia);
	x = WIDTH / 2 - HEIGHT / 2;
	while (x < WIDTH / 2 + HEIGHT / 2)
	{
		y = 0;
		while (y < HEIGHT)
		{
			define_julia(&julia);
			y++;
		}
		x++;
	}
}
