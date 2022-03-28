/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:19:36 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/28 14:34:39 by ssulkuma         ###   ########.fr       */
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

int	mouse_events(int button, int x, int y, t_mlx *mlx)
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
