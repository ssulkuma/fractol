/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:30:12 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/25 13:57:39 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	complex_abs(t_complex a)
{
	return (a.real * a.real + a.imag * a.imag);
}

t_complex	complex_pow(t_complex base, double power)
{
	t_complex	result;
	double		index;

	index = 0;
	result.real = 1;
	result.imag = 0;
	while(index < power)
	{
		result = complex_mul(result, base);
		index++;
	}
	return (result);
}
