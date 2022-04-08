/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:45:37 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/08 11:09:48 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static void	define_threads(pthread_t *id, void *data, t_mlx *mlx)
{
	if (mlx->fractal == 1)
	{
		if (pthread_create(id, NULL, julia_set, data))
			error("error");
	}
	if (mlx->fractal == 2)
	{
		if (pthread_create(id, NULL, mandelbrot_set, data))
			error("error");
	}
	if (mlx->fractal == 3)
	{
		mlx_clear_window(mlx->connection, mlx->window);
		if (pthread_create(id, NULL, newton_set, data))
			error("error");
	}
	if (mlx->fractal == 4)
	{
		if (pthread_create(id, NULL, burning_ship_set, data))
			error("error");
	}
}

static void	create_threads(t_mlx *mlx)
{
	int			index;
	pthread_t	thread_id[MAX_THREADS];
	t_thread	thread[MAX_THREADS];

	index = -1;
	while (++index < MAX_THREADS)
	{
		thread[index].start_x = WIDTH / MAX_THREADS * index;
		thread[index].end_x = WIDTH / MAX_THREADS * (index + 1);
		thread[index].mlx = mlx;
	}
	index = -1;
	while (++index < MAX_THREADS)
		define_threads(&(thread_id[index]), &(thread[index]), mlx);
	index = -1;
	while (++index < MAX_THREADS)
		pthread_join(thread_id[index], NULL);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->image, 0, 0);
}

void	draw(t_mlx *mlx)
{
	void	*con;
	void	*win;

	con = mlx->connection;
	win = mlx->window;
	create_threads(mlx);
	if (mlx->menu == 1)
		menu(mlx);
	else
		mlx_string_put(con, win, 35, 20, 0xFFFFFF, "Menu [H]");
}
