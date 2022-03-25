/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssulkuma <ssulkuma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:10:08 by ssulkuma          #+#    #+#             */
/*   Updated: 2022/03/25 12:25:26 by ssulkuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return (result);
}

t_complex	complex_sub(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return (result);
}

t_complex	complex_mul(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = a.real * b.real - a.imag * b.imag;
	result.imag = a.real * b.imag + a.imag * b.real;
	return (result);
}

t_complex	complex_div(t_complex a, t_complex b)
{
	t_complex	result;

	result.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
	result.imag = (-a.real * b.imag + a.imag * b.real) / (b.real * b.real + b.imag * b.imag);
	return (result);
}
