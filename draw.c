/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:45:37 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/06 17:55:07 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
void	*render_threads(void *data)
{
	int	x;
	int	y;

	data = NULL;
	x = WIDTH / MAX_THREADS;
	while (x < WIDTH / MAX_THREADS)
	{
		y = 0;
		while (y < HEIGHT)
		{
			
			y++;
		}
		x++;
	}
	return (NULL);
}
*/
static void create_threads(t_mlx *mlx)
{
	int			index;
	pthread_t	thread_id[MAX_THREADS];

	index = 0;
	while (index < MAX_THREADS)
	{
		if (mlx->fractal == 2)
		{
			if (pthread_create(&(thread_id[index]), NULL, mandelbrot_set, mlx))
				error("error");
		}
		index++;
	}
	index = 0;
	while (index < MAX_THREADS)
	{
		pthread_join(thread_id[index], NULL);
		index++;
	}
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->image, 0, 0);
}

void	draw_pixel_to_image(t_mlx *mlx, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel = mlx->address + (y * mlx->line_len + \
			x * (mlx->bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

void	draw(t_mlx *mlx)
{
	void	*con;
	void	*win;

	con = mlx->connection;
	win = mlx->window;
	if (mlx->fractal == 1)
		julia_set(mlx);
	if (mlx->fractal == 2)
		create_threads(mlx);//mandelbrot_set(mlx);
	if (mlx->fractal == 3)
		newton_set(mlx);
	if (mlx->fractal == 4)
		burning_ship_set(mlx);
	//mlx_put_image_to_window(mlx->connection, mlx->window, mlx->image, 0, 0);
	if (mlx->menu == 1)
		menu(mlx);
	else
		mlx_string_put(con, win, 35, 20, 0xFFFFFF, "Menu [H]");
}
