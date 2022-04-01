/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:50:55 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/01 16:24:12 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_keys(int keycode, t_mlx *mlx)
{
	if (keycode == ONE_KEY)
		mlx->color = 1;
	if (keycode == TWO_KEY)
		mlx->color = 2;
	if (keycode == THREE_KEY)
		mlx->color = 3;
	if (keycode == FOUR_KEY)
		mlx->color = 4;
	if (keycode == FIVE_KEY)
		mlx->color = 5;
	if (keycode == SIX_KEY)
		mlx->color = 6;
	if (keycode == SEVEN_KEY)
		mlx->color = 7;
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
}

static void	fractal_keys(int keycode, t_mlx *mlx)
{
	if (keycode == J_KEY)
		mlx->fractal = 1;
	if (keycode == M_KEY)
		mlx->fractal = 2;
	if (keycode == N_KEY)
		mlx->fractal = 3;
	mlx->min_real = -2;
	mlx->max_real = 1;
	mlx->min_imag = -2;
	mlx->max_imag = 2;
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
}

static void	iteration_keys(int keycode, t_mlx *mlx)
{
	if (keycode == PLUS_KEY)
		mlx->max_iteration += 5;
	if (keycode == MINUS_KEY)
		mlx->max_iteration -= 5;
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
}

static void	menu_key(t_mlx *mlx)
{
	if (mlx->menu == 1)
		mlx->menu = 0;
	else
		mlx->menu = 1;
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
}

int	key_events(int keycode, t_mlx *mlx)
{
	if (keycode == ONE_KEY || keycode == TWO_KEY || keycode == THREE_KEY
		|| keycode == FOUR_KEY || keycode == FIVE_KEY || keycode == SIX_KEY
		|| keycode == SEVEN_KEY)
		color_keys(keycode, mlx);
	if (keycode == J_KEY || keycode == M_KEY || keycode == N_KEY)
		fractal_keys(keycode, mlx);
	if (keycode == PLUS_KEY || keycode == MINUS_KEY)
		iteration_keys(keycode, mlx);
	if (keycode == H_KEY)
		menu_key(mlx);
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_destroy_window(mlx->connection, mlx->window);
		exit(0);
	}
	return (0);
}
