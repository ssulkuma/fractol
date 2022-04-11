/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:58:27 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/11 11:53:09 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	reset_range(t_mlx *mlx)
{
	if (mlx->fractal == 1)
	{
		mlx->position_x = 580;
		mlx->position_y = 0;
	}
	if (mlx->fractal == 2)
	{
		mlx->position_x = -150;
		mlx->position_y = 0;
	}
	if (mlx->fractal == 3)
	{
		mlx->position_x = 580;
		mlx->position_y = 0;
	}
	if (mlx->fractal == 4)
	{
		mlx->position_x = 120;
		mlx->position_y = -200;
	}
}

static void	reset_position(t_mlx *mlx)
{
	mlx->min_real = -2.0;
	mlx->max_real = 0.47;
	mlx->min_imag = -1.12;
	mlx->max_imag = 1.12;
	if (mlx->fractal == 2)
	{
		mlx->min_real = -2.0;
		mlx->max_real = 2.0;
		mlx->min_imag = -1.25;
		mlx->max_imag = 1.25;
	}
}

void	reset(t_mlx *mlx)
{
	reset_range(mlx);
	reset_position(mlx);
}
