/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:19:36 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/29 18:33:14 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
int	mouse_movements(int x, int y, t_mlx *mlx)
{
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
	return (0);
}*/

static void	zoom(int x, int y, int direction, t_mlx *mlx)
{
	double	move_x;
	double	move_y;

	move_x = (double)x * (mlx->max_real - mlx->min_real) / WIDTH + mlx->min_real;
	move_y = (double)y * (mlx->max_imag - mlx->min_imag) / HEIGHT + mlx->min_imag;
	if (direction == 1)
	{
		mlx->max_real *= 0.9 + move_x * (1 - 0.9);
		mlx->min_real *= 0.9 + move_x * (1 - 0.9);
		mlx->max_imag *= 0.9 + move_y * (1 - 0.9);
		mlx->max_imag *= 0.9 + move_y * (1 - 0.9);
	}
	else
	{
		mlx->max_real *= 1.1 + move_x * (1 - 1.1);
		mlx->min_real *= 1.1 + move_x * (1 - 1.1);
		mlx->max_imag *= 1.1 + move_y * (1 - 1.1);
		mlx->max_imag *= 1.1 + move_y * (1 - 1.1);
	}
}

int	mouse_events(int button, int x, int y, t_mlx *mlx)
{
	if (button == SCROLL_UP)
		zoom(x, y, 1, mlx);
	if (button == SCROLL_DOWN)
		zoom(x, y, 2, mlx);
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
	return (0);
}
