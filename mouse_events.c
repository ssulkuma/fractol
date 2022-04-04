/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:19:36 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/04 14:39:48 by ssulkuma         ###   ########.fr       */
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

static void	apply_zoom(int x, int y, double zoom_factor, t_mlx *mlx)
{
	double	real_factor;
	double	imag_factor;
	double	zoom;

	zoom = 1.0 / zoom_factor;
	real_factor = (double)x / (WIDTH / (mlx->max_real - mlx->min_real))
		+ mlx->min_real;
	imag_factor = (double)y / (HEIGHT / (mlx->max_imag - mlx->min_imag))
		+ mlx->min_imag;
	mlx->max_real = real_factor + ((mlx->max_real - real_factor) * zoom);
	mlx->min_real = real_factor + ((mlx->min_real - real_factor) * zoom);
	mlx->max_imag = imag_factor + ((mlx->max_imag - imag_factor) * zoom);
	mlx->min_imag = imag_factor + ((mlx->min_imag - imag_factor) * zoom);
}

int	mouse_events(int button, int x, int y, t_mlx *mlx)
{
	double	zoom_factor;

	if (button == MOUSE_LEFT)
	{
		if (mlx->lock == 1)
			mlx->lock = 0;
		else
			mlx->lock = 1;
		return (0);
	}
	if (button == SCROLL_DOWN)
	{
		zoom_factor = 1.1;
		apply_zoom(x, y, zoom_factor, mlx);
	}
	if (button == SCROLL_UP)
	{
		zoom_factor = 0.9;
		apply_zoom(x, y, zoom_factor, mlx);
	}
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
	return (0);
}
