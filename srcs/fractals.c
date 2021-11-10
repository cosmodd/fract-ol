/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:16:52 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/10 11:00:17 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, int max_iter, double mmx, double mmy)
{
	t_complex	z;
	double		zr2;
	double		zi2;
	int			iteration;

	(void) mmx;
	(void) mmy;
	zr2 = 0;
	zi2 = 0;
	z.r = 0;
	z.i = 0;
	iteration = 0;
	while (zr2 + zi2 <= 4 && iteration < max_iter)
	{
		z.i = 2 * z.r * z.i + c.i;
		z.r = zr2 - zi2 + c.r;
		zr2 = z.r * z.r;
		zi2 = z.i * z.i;
		iteration++;
	}
	return (iteration);
}

int	julia(t_complex c, int max_iter, double mmx, double mmy)
{
	t_complex	z;
	double		zr_temp;
	int			iter;

	iter = 0;
	z.r = c.r;
	z.i = c.i;
	c.r = mmx;
	c.i = mmy;
	while (z.r * z.r + z.i * z.i < 4 && iter < max_iter)
	{
		zr_temp = z.r * z.r - z.i * z.i;
		z.i = 2 * z.r * z.i + c.r;
		z.r = zr_temp + c.i;
		iter++;
	}
	return (iter);
}

int	burningship(t_complex c, int max_iter, double mmx, double mmy)
{
	t_complex	z;
	double		zr_temp;
	int			iter;

	(void) mmx;
	(void) mmy;
	iter = 0;
	z.r = c.r;
	z.i = c.i;
	while (z.r * z.r + z.i * z.i < 4 && iter < max_iter)
	{
		zr_temp = z.r * z.r - z.i * z.i + c.r;
		z.i = fabs(2 * z.r * z.i) + c.i;
		z.r = zr_temp;
		iter++;
	}
	return (iter);
}
