/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:25:17 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/21 16:52:48 by ssulkuma         ###   ########.fr       */
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
}			t_mlx;

typedef struct s_mbrot
{
	float	z_real;
	float	z_imaginary;
	float	c_real;
	float	c_imaginary;
}			t_mbrot;

typedef struct s_julia
{
}			t_julia;

void	error(const char *str);
void	events(t_mlx *mlx);

#endif
