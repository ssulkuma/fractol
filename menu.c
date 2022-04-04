/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:53:01 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/04 12:15:24 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_list(void *con, void *win)
{
	mlx_string_put(con, win, 95, 170, 0xFFFFFF, "Red [1]");
	mlx_string_put(con, win, 75, 190, 0xFFFFFF, "Green [2]");
	mlx_string_put(con, win, 85, 210, 0xFFFFFF, "Blue [3]");
	mlx_string_put(con, win, 65, 230, 0xFFFFFF, "Yellow [4]");
	mlx_string_put(con, win, 65, 250, 0xFFFFFF, "Purple [5]");
	mlx_string_put(con, win, 65, 270, 0xFFFFFF, "Orange [6]");
	mlx_string_put(con, win, 55, 290, 0xFFFFFF, "Rainbow [7]");
}

void	menu(t_mlx *mlx)
{
	void	*con;
	void	*win;

	con = mlx->connection;
	win = mlx->window;
	if (mlx->fractal == 1)
		mlx_string_put(con, win, 25, 20, 0x000000, "Julia");
	else if (mlx->fractal == 2)
		mlx_string_put(con, win, 25, 20, 0x000000, "Mandelbrot");
	else if (mlx->fractal == 3)
		mlx_string_put(con, win, 25, 20, 0x000000, "Newton");
	else if (mlx->fractal == 4)
		mlx_string_put(con, win, 25, 20, 0x000000, "Burning Ship");
	mlx_string_put(con, win, 25, 40, 0xFFFFFF, "Change fractal:");
	mlx_string_put(con, win, 75, 60, 0xFFFFFF, "Julia [J]");
	mlx_string_put(con, win, 25, 80, 0xFFFFFF, "Mandelbrot [M]");
	mlx_string_put(con, win, 65, 100, 0xFFFFFF, "Newton [N]");
	mlx_string_put(con, win, 25, 120, 0xFFFFFF, "Burning Ship [B]");
	mlx_string_put(con, win, 25, 150, 0xFFFFFF, "Change color:");
	color_list(con, win);
	mlx_string_put(con, win, 25, 320, 0xFFFFFF, "Precision: [+] / [-]");
	mlx_string_put(con, win, 25, 340, 0xFFFFFF, "Lock: [left mouse click]");
	mlx_string_put(con, win, 25, 360, 0xFFFFFF, "Manipulate: [move mouse]");
	mlx_string_put(con, win, 25, 380, 0xFFFFFF, "Move: [arrow keys]");
	mlx_string_put(con, win, 25, 400, 0xFFFFFF, "Zoom: [scroll mouse]");
	mlx_string_put(con, win, 25, 430, 0xFFFFFF, "Hide menu: [H]");
	mlx_string_put(con, win, 25, 450, 0xFFFFFF, "Exit: [ESC]");
}
