/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:19:36 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/08 15:03:59 by ssulkuma         ###   ########.fr       */
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
		draw(mlx);
	}
	return (0);
}

static void	apply_zoom(int x, int y, double zoom, t_mlx *mlx)
{
	double	real_factor;
	double	imag_factor;

	real_factor = (double)(x + mlx->position_x) / (WIDTH
			/ (mlx->max_real - mlx->min_real)) + mlx->min_real;
	imag_factor = (double)(y + mlx->position_y) / (HEIGHT
			/ (mlx->max_imag - mlx->min_imag)) + mlx->min_imag;
	mlx->max_real = real_factor + ((mlx->max_real - real_factor) * zoom);
	mlx->min_real = real_factor + ((mlx->min_real - real_factor) * zoom);
	mlx->max_imag = imag_factor + ((mlx->max_imag - imag_factor) * zoom);
	mlx->min_imag = imag_factor + ((mlx->min_imag - imag_factor) * zoom);
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
		zoom = 1.1;
		apply_zoom(x, y, zoom, mlx);
	}
	if (button == SCROLL_DOWN)
	{
		zoom = 0.9;
		apply_zoom(x, y, zoom, mlx);
	}
	draw(mlx);
	return (0);
}
