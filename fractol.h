/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:25:17 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/23 14:26:34 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# include <stdio.h>
# include <math.h>

# define WIDTH 1500
# define HEIGHT 1200

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

void	error(const char *str);
void	events(t_mlx *mlx);
void	draw(t_mlx *mlx);
void	draw_pixel_to_image(t_mlx *mlx, int x, int y, int color);
void	mandelbrot_set(t_mlx *mlx);
void	julia_set(t_mlx *mlx);

#endif
