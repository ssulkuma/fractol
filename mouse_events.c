/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:19:36 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/30 17:02:00 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_movements(int x, int y, t_mlx *mlx)
{
	if (!mlx->lock)
	{
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		mlx->mouse_x = ((double)x / WIDTH) * 2;
		mlx->mouse_y = ((double)y / HEIGHT) * 2;
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_clear_window(mlx->connection, mlx->window);
		draw(mlx);
	}
	return (0);
}

static void	apply_zoom(int x, int y, double zoom, t_mlx *mlx)
{
	double	real_factor;
	double	imag_factor;

	zoom = 1;
	real_factor = (mlx->max_real - mlx->min_real) / (WIDTH - 1);
	imag_factor = (mlx->max_imag - mlx->min_imag) / (HEIGHT - 1);
	mlx->zoom_x = mlx->min_real + x * real_factor;
	mlx->zoom_y = mlx->max_imag - y * imag_factor;
}

int	mouse_events(int button, int x, int y, t_mlx *mlx)
{
	double	zoom;

	if (button == MOUSE_LEFT)
	{
		if (mlx->lock == 1)
			mlx->lock = 0;
		else
			mlx->lock = 1;
		return (0);
	}
	if (button == SCROLL_UP)
	{
		zoom = 1.0 * 1.1;
		apply_zoom(x, y, zoom, mlx);
	}
	if (button == SCROLL_DOWN)
	{
		zoom = 1.0 * 0.9;
		apply_zoom(x, y, zoom, mlx);
	}
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
	return (0);
}
