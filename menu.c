/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:53:01 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/28 16:42:05 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_mlx *mlx)
{
	if (mlx->fractal == 1)
		mlx_string_put(mlx->connection, mlx->window, 25, 20, 0xFF0000, "Julia");
	else if (mlx->fractal == 2)
		mlx_string_put(mlx->connection, mlx->window, 25, 20, 0xFF0000, "Mandelbrot");
	else if (mlx->fractal == 3)
		mlx_string_put(mlx->connection, mlx->window, 25, 20, 0xFF0000, "Newton");
	mlx_string_put(mlx->connection, mlx->window, 25, 40, 0xFFFFFF, "Change fractal:");
	mlx_string_put(mlx->connection, mlx->window, 75, 60, 0xFFFFFF, "Julia [J]");
	mlx_string_put(mlx->connection, mlx->window, 25, 80, 0xFFFFFF, "Mandelbrot [M]");
	mlx_string_put(mlx->connection, mlx->window, 65, 100, 0xFFFFFF, "Newton [N]");
	mlx_string_put(mlx->connection, mlx->window, 25, 130, 0xFFFFFF, "Change color:");
	mlx_string_put(mlx->connection, mlx->window, 95, 150, 0xFFFFFF, "Red [1]");
	mlx_string_put(mlx->connection, mlx->window, 75, 170, 0xFFFFFF, "Green [2]");
	mlx_string_put(mlx->connection, mlx->window, 85, 190, 0xFFFFFF, "Blue [3]");
	mlx_string_put(mlx->connection, mlx->window, 65, 210, 0xFFFFFF, "Yellow [4]");
	mlx_string_put(mlx->connection, mlx->window, 65, 230, 0xFFFFFF, "Purple [5]");
	mlx_string_put(mlx->connection, mlx->window, 65, 250, 0xFFFFFF, "Orange [6]");
	mlx_string_put(mlx->connection, mlx->window, 55, 270, 0xFFFFFF, "Rainbow [7]");
	mlx_string_put(mlx->connection, mlx->window, 25, 300, 0xFFFFFF, "Precision: [+] / [-]");
	mlx_string_put(mlx->connection, mlx->window, 25, 320, 0xFFFFFF, "Manipulate: [move mouse]");
	mlx_string_put(mlx->connection, mlx->window, 25, 340, 0xFFFFFF, "Zoom: [scroll mouse]");
	mlx_string_put(mlx->connection, mlx->window, 25, 370, 0xFFFFFF, "Hide menu: [H]");
	mlx_string_put(mlx->connection, mlx->window, 25, 390, 0xFFFFFF, "Exit: [ESC]");
}
