/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:50:55 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/28 12:20:34 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color_choose_keys(int keycode, t_mlx *mlx)
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

static int	key_events(int keycode, t_mlx *mlx)
{
	printf("%d\n", keycode);
	if ((keycode >= ONE_KEY && keycode <= FIVE_KEY) || keycode == SEVEN_KEY)
		color_choose_keys(keycode, mlx);
	if (keycode == J_KEY || keycode == M_KEY || keycode == N_KEY)
	{
		if (keycode == J_KEY)
			mlx->fractal = 1;
		if (keycode == M_KEY)
			mlx->fractal = 2;
		if (keycode == N_KEY)
			mlx->fractal = 3;
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_clear_window(mlx->connection, mlx->window);
		draw(mlx);
	}
	if (keycode == ESC_KEY)
	{
		mlx_destroy_image(mlx->connection, mlx->image);
		mlx_destroy_window(mlx->connection, mlx->window);
		exit(0);
	}
	return (0);
}

static int	mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
	x = 0;
	y = 0;
	if (button == SCROLL_UP)
		mlx->zoom += 1;
	if (button == SCROLL_DOWN)
		mlx->zoom -= 1;
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
	return (0);
}
/*
static int	mouse_movement(int x, int y, t_mlx *mlx)
{
	if ()
		mlx->range += 0.001;
	if ()
		mlx->range -= 0.001;
	mlx_destroy_image(mlx->connection, mlx->image);
	mlx_clear_window(mlx->connection, mlx->window);
	draw(mlx);
	return (0);
}
*/
void	events(t_mlx *mlx)
{
	mlx_hook(mlx->window, 2, 0, key_events, mlx);
	mlx_hook(mlx->window, 4, 0, mouse_zoom, mlx);
	//mlx_hook(mlx->window, 6, 0, mouse_movement, mlx);
}
