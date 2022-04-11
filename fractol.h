/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:25:17 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/04/11 11:04:43 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# include <stdio.h>
# include <math.h>
# include <pthread.h>

# define WIDTH 1920
# define HEIGHT 1200
# define MAX_THREADS 12

# define ESC_KEY 53
# define ONE_KEY 18
# define TWO_KEY 19
# define THREE_KEY 20
# define FOUR_KEY 21
# define FIVE_KEY 23
# define SIX_KEY 22
# define SEVEN_KEY 26
# define PLUS_KEY 24
# define MINUS_KEY 27
# define J_KEY 38
# define M_KEY 46
# define N_KEY 45
# define H_KEY 4
# define B_KEY 11
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define ARROW_UP 126

# define MOUSE_LEFT 1
# define SCROLL_UP 4
# define SCROLL_DOWN 5 

typedef struct s_mlx
{
	void	*connection;
	void	*window;
	void	*image;
	char	*address;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		fractal;
	int		color;
	int		rainbow;
	int		menu;
	int		max_iteration;
	int		lock;
	int		position_x;
	int		position_y;
	double	mouse_x;
	double	mouse_y;
	double	max_real;
	double	max_imag;
	double	min_real;
	double	min_imag;
}			t_mlx;

typedef struct s_thread
{
	int		start_x;
	int		end_x;
	t_mlx	*mlx;
}			t_thread;

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_fractal
{
	int		x;
	int		y;
	double	tolerance;
}			t_fractal;

void		error(const char *str);
void		draw(t_mlx *mlx);
void		draw_pixel_to_image(t_mlx *mlx, int x, int y, int color);
void		menu(t_mlx *mlx);
void		*mandelbrot_set(void *data);
void		*julia_set(void *data);
void		*newton_set(void *data);
void		*burning_ship_set(void *data);
void		reset(t_mlx *mlx);
int			rainbow_colors(t_mlx *mlx);
int			define_color(int iteration, t_mlx *mlx);
int			define_root0_color(int iteration, t_mlx *mlx);
int			define_root1_color(int iteration, t_mlx *mlx);
int			define_root2_color(int iteration, t_mlx *mlx);
int			key_events(int keycode, t_mlx *mlx);
int			mouse_events(int button, int x, int y, t_mlx *mlx);
int			mouse_movements(int x, int y, t_mlx *mlx);
double		complex_abs(t_complex a);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_sub(t_complex a, t_complex b);
t_complex	complex_mul(t_complex a, t_complex b);
t_complex	complex_div(t_complex a, t_complex b);
t_complex	complex_pow(t_complex base, double power);

#endif
