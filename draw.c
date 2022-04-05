/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:45:37 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/05 15:33:49 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
static void	*render_threads(void *data)
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

static void create_threads(t_mlx *mlx)
{
	int			index;
	int			ret_value;
	pthread_t	thread_id;

	index = 0;
	while (index < MAX_THREADS)
	{
		ret_value = pthread_create(&thread_id, NULL, render_threads, NULL);
		if (ret_value)
			error("error");
		pthread_join(thread_id, NULL);
		index++;
	}
	draw(mlx);
}
*/
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
	mlx->image = mlx_new_image(mlx->connection, WIDTH, HEIGHT);
	mlx->address = mlx_get_data_addr(mlx->image, &mlx->bits_per_pixel,
			&mlx->line_len, &mlx->endian);
	if (mlx->fractal == 1)
		julia_set(mlx);
	if (mlx->fractal == 2)
		mandelbrot_set(mlx);
	if (mlx->fractal == 3)
		newton_set(mlx);
	if (mlx->fractal == 4)
		burning_ship_set(mlx);
	mlx_put_image_to_window(mlx->connection, mlx->window, mlx->image, 0, 0);
	if (mlx->menu == 1)
		menu(mlx);
	else
		mlx_string_put(con, win, 35, 20, 0xFFFFFF, "Menu [H]");
}
