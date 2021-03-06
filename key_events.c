/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:50:55 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/11 11:04:25 by ssulkuma         ###   ########.fr       */
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
	if (keycode == B_KEY)
		mlx->fractal = 4;
	reset(mlx);
	draw(mlx);
}

static void	iteration_and_movement_keys(int keycode, t_mlx *mlx)
{
	if (keycode == ARROW_LEFT)
		mlx->position_x += 10;
	if (keycode == ARROW_RIGHT)
		mlx->position_x -= 10;
	if (keycode == ARROW_DOWN)
		mlx->position_y -= 10;
	if (keycode == ARROW_UP)
		mlx->position_y += 10;
	if (keycode == PLUS_KEY)
		mlx->max_iteration += 5;
	if (keycode == MINUS_KEY)
		mlx->max_iteration -= 5;
	draw(mlx);
}

static void	menu_key(t_mlx *mlx)
{
	if (mlx->menu == 1)
		mlx->menu = 0;
	else
		mlx->menu = 1;
	draw(mlx);
}

int	key_events(int keycode, t_mlx *mlx)
{
	if (keycode == ONE_KEY || keycode == TWO_KEY || keycode == THREE_KEY
		|| keycode == FOUR_KEY || keycode == FIVE_KEY || keycode == SIX_KEY
		|| keycode == SEVEN_KEY)
		color_keys(keycode, mlx);
	if (keycode == J_KEY || keycode == M_KEY || keycode == N_KEY
		|| keycode == B_KEY)
		fractal_keys(keycode, mlx);
	if (keycode == PLUS_KEY || keycode == MINUS_KEY
		|| (keycode >= ARROW_LEFT && keycode <= ARROW_UP))
		iteration_and_movement_keys(keycode, mlx);
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
