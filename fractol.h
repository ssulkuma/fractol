/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:25:17 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/25 14:59:48 by ssulkuma         ###   ########.fr       */
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
}			t_mlx;

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

typedef struct s_mandel
{
	int		max_iteration;
	double	z_real;
	double	c_real;
	double	max_real;
	double	min_real;
	double	z_imaginary;
	double	c_imaginary;
	double	max_imaginary;
	double	min_imaginary;
}			t_mandel;

typedef struct s_julia
{
	int		max_iteration;
	double	depth;
	double	z_real;
	double	c_real;
	double	max_real;
	double	min_real;
	double	z_imaginary;
	double	c_imaginary;
	double	max_imaginary;
	double	min_imaginary;
}			t_julia;

typedef struct s_newton
{
	int		x;
	int		y;
	int		max_iteration;
	double	max_real;
	double	max_imag;
	double	min_real;
	double	min_imag;
	double	tolerance;
}			t_newton;

void		error(const char *str);
void		events(t_mlx *mlx);
void		draw(t_mlx *mlx);
void		draw_pixel_to_image(t_mlx *mlx, int x, int y, int color);
void		mandelbrot_set(t_mlx *mlx);
void		julia_set(t_mlx *mlx);
void		newton_set(t_mlx *mlx);
double		complex_abs(t_complex a);
t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_sub(t_complex a, t_complex b);
t_complex	complex_mul(t_complex a, t_complex b);
t_complex	complex_div(t_complex a, t_complex b);
t_complex	complex_pow(t_complex base, double power);

#endif
