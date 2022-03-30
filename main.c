/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:30:04 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/30 16:58:50 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_fractal_type(t_mlx *mlx, char **argv)
{
	if (!ft_strcmp(argv[1], "Julia") || !ft_strcmp(argv[1], "julia"))
		mlx->fractal = 1;
	else if (!ft_strcmp(argv[1], "Mandelbrot")
		|| !ft_strcmp(argv[1], "mandelbrot"))
		mlx->fractal = 2;
	else if (!ft_strcmp(argv[1], "Newton") || !ft_strcmp(argv[1], "newton"))
		mlx->fractal = 3;
	else
	{
		ft_putendl("Invalid fractal type. Available types:");
		ft_putendl("-->> Julia");
		ft_putendl("-->> Mandelbrot");
		ft_putendl("-->> Newton");
		exit(1);
	}
}

static void	struct_intel(t_mlx *mlx)
{
	mlx->color = 1;
	//mlx->zoom = 1;
	mlx->max_iteration = 100;
	mlx->menu = 0;
	mlx->min_real = -2;
	mlx->max_real = 2;
	mlx->min_imag = -2;
	mlx->max_imag = mlx->min_imag - (mlx->max_real - mlx->min_real) * HEIGHT / WIDTH;
	mlx->mouse_x = -0.08;
	mlx->mouse_y = 0.156;
	mlx->lock = 1;
}

void	error(const char *str)
{
	perror(str);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
	{
		ft_putendl("Usage: ./fractol [name of fractal type]");
		ft_putendl("-->> Julia");
		ft_putendl("-->> Mandelbrot");
		ft_putendl("-->> Newton");
		return (1);
	}
	check_fractal_type(&mlx, argv);
	struct_intel(&mlx);
	mlx.connection = mlx_init();
	if (!mlx.connection)
		error("error");
	mlx.window = mlx_new_window(mlx.connection, WIDTH, HEIGHT, "Fract'ol");
	if (!mlx.window)
		error("error");
	draw(&mlx);
	mlx_hook(mlx.window, 2, 0, key_events, &mlx);
	mlx_hook(mlx.window, 4, 0, mouse_events, &mlx);
	mlx_hook(mlx.window, 6, 0, mouse_movements, &mlx);
	mlx_loop(mlx.connection);
	return (0);
}
