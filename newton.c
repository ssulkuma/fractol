/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:24:45 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/25 14:24:32 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	newton_function(t_complex z)
{
	t_complex	one;

	one.real = 1;
	one.imag = 0;
	return (complex_sub(complex_pow(z, 3), one));
}

static	t_complex	newton_derivative(t_complex z)
{
	t_complex	three;

	three.real = 3;
	three.imag = 0;
	return (complex_mul(complex_mul(z, z), three));
}

static int	define_newton(t_newton *newton, t_complex z, t_complex *root, int x, int y, t_mlx *mlx)
{
	int			iteration;

	iteration = 0;
	while (complex_abs(complex_sub(z, root[0])) > newton->tolerance
		&& complex_abs(complex_sub(z, root[1])) > newton->tolerance
		&& complex_abs(complex_sub(z, root[2])) > newton->tolerance
		&& iteration < newton->max_iteration)
	{
		z = complex_sub(z, complex_div(newton_function(z), newton_derivative(z)));
		iteration++;
	}
	if (complex_abs(complex_sub(z, root[0])) < newton->tolerance)
		draw_pixel_to_image(mlx, x, y, (255 - iteration * 15) << 16);
	else if (complex_abs(complex_sub(z, root[1])) < newton->tolerance)
		draw_pixel_to_image(mlx, x, y, (255 - iteration * 15) << 8);
	else if (complex_abs(complex_sub(z, root[2])) < newton->tolerance)
		draw_pixel_to_image(mlx, x, y, 255 - iteration * 15);
	return (iteration);
}

void	newton_struct_intel(t_complex *root, t_newton *newton)
{
	root[0].real = 1;
	root[0].imag = 0;
	root[1].real = -0.5;
	root[1].imag = sqrt(3) / 2;
	root[2].real = -0.5;
	root[2].imag = -sqrt(3) / 2;
	newton->max_iteration = 100;
	newton->max_real = 1;
	newton->max_imaginary = 1;
	newton->min_real = -1;
	newton->min_imaginary = -1;
	newton->tolerance = 0.000001;
}

void	newton_set(t_mlx *mlx)
{
	int			x;
	int			y;
	t_complex	z;
	t_complex	root[3];
	t_newton	newton;

	x = 0;
	newton_struct_intel(root, &newton);
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			z.real = newton.min_real + ((newton.max_real - newton.min_real) / HEIGHT) * x;
			z.imag = newton.min_imaginary + ((newton.max_imaginary - newton.min_imaginary) / HEIGHT) * y;
			newton.iteration = define_newton(&newton, z, root, x, y, mlx);
			y++;
		}
		x++;
	}
}
