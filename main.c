/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:30:04 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/21 13:49:24 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		return (1);
	}
	mlx.connection = mlx_init();
	if (!mlx.connection)
		error("error");
	mlx.window = mlx_new_window(mlx.connection, 1200, 1200, "Fract'ol");
	if (!mlx.window)
		error("error");
	printf("%s\n", argv[1]);
	events(&mlx);
	mlx_loop(mlx.connection);
	return (0);
}
