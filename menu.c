/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:53:01 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/04 14:46:31 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fractal_name(void *con, void *win, t_mlx *mlx)
{
	if (mlx->fractal == 1)
		mlx_string_put(con, win, 35, 20, 0x000000, "Julia");
	else if (mlx->fractal == 2)
		mlx_string_put(con, win, 35, 20, 0x000000, "Mandelbrot");
	else if (mlx->fractal == 3)
		mlx_string_put(con, win, 35, 20, 0x000000, "Newton");
	else if (mlx->fractal == 4)
		mlx_string_put(con, win, 35, 20, 0x000000, "Burning Ship");
}

static void	color_list(void *con, void *win)
{
	mlx_string_put(con, win, 105, 170, 0xFFFFFF, "Red [1]");
	mlx_string_put(con, win, 85, 190, 0xFFFFFF, "Green [2]");
	mlx_string_put(con, win, 95, 210, 0xFFFFFF, "Blue [3]");
	mlx_string_put(con, win, 75, 230, 0xFFFFFF, "Yellow [4]");
	mlx_string_put(con, win, 75, 250, 0xFFFFFF, "Purple [5]");
	mlx_string_put(con, win, 75, 270, 0xFFFFFF, "Orange [6]");
	mlx_string_put(con, win, 65, 290, 0xFFFFFF, "Rainbow [7]");
}

void	menu(t_mlx *mlx)
{
	void	*con;
	void	*win;

	con = mlx->connection;
	win = mlx->window;
	fractal_name(con, win, mlx);
	mlx_string_put(con, win, 35, 40, 0xFFFFFF, "Change fractal:");
	mlx_string_put(con, win, 85, 60, 0xFFFFFF, "Julia [J]");
	mlx_string_put(con, win, 35, 80, 0xFFFFFF, "Mandelbrot [M]");
	mlx_string_put(con, win, 75, 100, 0xFFFFFF, "Newton [N]");
	mlx_string_put(con, win, 15, 120, 0xFFFFFF, "Burning ship [B]");
	mlx_string_put(con, win, 35, 150, 0xFFFFFF, "Change color:");
	color_list(con, win);
	mlx_string_put(con, win, 35, 320, 0xFFFFFF, "Precision: [+] / [-]");
	mlx_string_put(con, win, 35, 340, 0xFFFFFF, "Lock: [left mouse click]");
	mlx_string_put(con, win, 35, 360, 0xFFFFFF, "Manipulate: [move mouse]");
	mlx_string_put(con, win, 35, 380, 0xFFFFFF, "Move: [arrow keys]");
	mlx_string_put(con, win, 35, 400, 0xFFFFFF, "Zoom: [scroll mouse]");
	mlx_string_put(con, win, 35, 430, 0xFFFFFF, "Hide menu: [H]");
	mlx_string_put(con, win, 35, 450, 0xFFFFFF, "Exit: [ESC]");
}
