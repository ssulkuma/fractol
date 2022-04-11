/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:30:04 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/11 11:06:43 by ssulkuma         ###   ########.fr       */
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
	else if (!ft_strcmp(argv[1], "Burning_Ship")
		|| !ft_strcmp(argv[1], "burning_ship"))
		mlx->fractal = 4;
	else
	{
		ft_putendl("Invalid fractal type. Available types:");
		ft_putendl("-->> Julia");
		ft_putendl("-->> Mandelbrot");
		ft_putendl("-->> Newton");
		ft_putendl("-->> Burning_Ship");
		exit(1);
	}
}

static void	struct_intel(t_mlx *mlx)
{
	mlx->color = 1;
	mlx->max_iteration = 80;
	mlx->menu = 0;
	reset(mlx);
	mlx->mouse_x = -0.08;
	mlx->mouse_y = 0.156;
	mlx->lock = 1;
	mlx->rainbow = 5;
	mlx->image = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
	mlx->address = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel,
			&mlx->line_len, &mlx->endian);
}

static void	usage(void)
{
	ft_putendl("Usage: ./fractol [name of fractal type]");
	ft_putendl("-->> Julia");
	ft_putendl("-->> Mandelbrot");
	ft_putendl("-->> Newton");
	ft_putendl("-->> Burning_Ship");
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
		usage();
		return (1);
	}
	check_fractal_type(&mlx, argv);
	mlx.connection = mlx_init();
	if (!mlx.connection)
		error("error");
	mlx.window = mlx_new_window(mlx.connection, WIDTH, HEIGHT, "Fract'ol");
	if (!mlx.window)
		error("error");
	struct_intel(&mlx);
	draw(&mlx);
	mlx_hook(mlx.window, 2, 0, key_events, &mlx);
	mlx_hook(mlx.window, 4, 0, mouse_events, &mlx);
	mlx_hook(mlx.window, 6, 0, mouse_movements, &mlx);
	mlx_loop_hook(mlx.connection, rainbow_colors, &mlx);
	mlx_loop(mlx.connection);
	return (0);
}
