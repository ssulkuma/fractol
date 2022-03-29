/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:16:43 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/29 14:20:54 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	define_color(int iteration, t_mlx *mlx)
{
	int	color;

	if (mlx->color == 1)
		color = (0xFF0000 + iteration * 10);
	else if (mlx->color == 2)
		color = (0x009900 + iteration * 10);
	else if (mlx->color == 3)
		color = (0x0000FF + iteration * 10);
	else if (mlx->color == 4)
		color = (0xFFE135 + iteration * 10);
	else if (mlx->color == 5)
		color = (0x301934 + iteration * 10);
	else if (mlx->color == 6)
		color = (0xFFA500 + iteration * 10);
	else
		color = (255 * iteration * 10);
	return (color);
}

int	define_root0_color(int iteration, t_mlx *mlx)
{
	int	color;

	if (mlx->color == 1)
		color = (0xC50000 + iteration * 15);
	else if (mlx->color == 2)
		color = (0x32CD32 + iteration * 13);
	else if (mlx->color == 3)
		color = (0x2A52BE - iteration * 10);
	else if (mlx->color == 4)
		color = (0xFFFF00 - iteration * 15);
	else if (mlx->color == 5)
		color = (0x8A2BE2 - iteration * 12);
	else if (mlx->color == 6)
		color = (0xFF8C00 + iteration * 15);
	else
		color = (255 - iteration * 15) << 16;
	return (color);
}

int	define_root1_color(int iteration, t_mlx *mlx)
{
	int	color;

	if (mlx->color == 1)
		color = (0xFF6EC7 - iteration * 10);
	else if (mlx->color == 2)
		color = (0x008000 + iteration * 13);
	else if (mlx->color == 3)
		color = (0x0073CF - iteration * 10);
	else if (mlx->color == 4)
		color = (0xFFD900 + iteration * 15);
	else if (mlx->color == 5)
		color = (0x8B0000 + iteration * 12);
	else if (mlx->color == 6)
		color = (0xD2691E + iteration * 15);
	else
		color = (255 - iteration * 15) << 8;
	return (color);
}

int	define_root2_color(int iteration, t_mlx *mlx)
{
	int	color;

	if (mlx->color == 1)
		color = (0xFF0800 + iteration * 15);
	else if (mlx->color == 2)
		color = (0x7CFC00 + iteration * 18);
	else if (mlx->color == 3)
		color = (0x191970 - iteration * 5);
	else if (mlx->color == 4)
		color = (0xF0E68C - iteration * 10);
	else if (mlx->color == 5)
		color = (0x4B0082 + iteration * 5);
	else if (mlx->color == 6)
		color = (0xFF7518 + iteration * 15);
	else
		color = (255 - iteration * 15);
	return (color);
}
