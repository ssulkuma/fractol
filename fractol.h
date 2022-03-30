/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:25:17 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/30 17:00:12 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# include <stdio.h>
# include <math.h>

# define WIDTH 1500
# define HEIGHT 800

# define ESC_KEY 53
# define ONE_KEY 18
# define TWO_KEY 19
# define THREE_KEY 20
# define FOUR_KEY 21
# define FIVE_KEY 23
# define SIX_KEY 22
# define SEVEN_KEY 26
# define PLUS_KEY 27
# define MINUS_KEY 44
# define J_KEY 38
# define M_KEY 46
# define N_KEY 45
# define H_KEY 4

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
	int		menu;
	int		max_iteration;
	int		lock;
	double	zoom_x;
	double	zoom_y;
	double	mouse_x;
	double	mouse_y;
	double	max_real;
	double	max_imag;
	double	min_real;
	double	min_imag;
}			t_mlx;

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_fractal
{
	int		x;
	int		y;
	double	max_real;
	double	max_imag;
	double	min_real;
	double	min_imag;
	double	tolerance;
}			t_fractal;

void		error(const char *str);
void		draw(t_mlx *mlx);
void		draw_pixel_to_image(t_mlx *mlx, int x, int y, int color);
void		menu(t_mlx *mlx);
void		mandelbrot_set(t_mlx *mlx);
void		julia_set(t_mlx *mlx);
void		newton_set(t_mlx *mlx);
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
