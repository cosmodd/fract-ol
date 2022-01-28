/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:09:21 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/28 11:19:21 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_env *env, t_complex c)
{
	t_complex	z;
	t_complex	z2;
	int			i;

	z = (t_complex){0, 0};
	z2 = (t_complex){0, 0};
	i = 0;
	while (z2.re + z2.im <= 4 && i < env->max_iter)
	{
		z = (t_complex){z2.re - z2.im + c.re, 2 * z.re * z.im + c.im};
		z2 = (t_complex){z.re * z.re, z.im * z.im};
		i++;
	}
	return (i);
}

int	julia(t_env *env, t_complex z)
{
	t_complex	c;
	t_complex	z2;
	int			i;

	c = (t_complex){env->mmx, env->mmy};
	z2 = (t_complex){z.re * z.re, z.im * z.im};
	i = 0;
	while (z2.re + z2.im <= 4 && i < env->max_iter)
	{
		z = (t_complex){z2.re - z2.im + c.re, 2 * z.re * z.im + c.im};
		z2 = (t_complex){z.re * z.re, z.im * z.im};
		i++;
	}
	return (i);
}

int	burningship(t_env *env, t_complex c)
{
	t_complex	z;
	t_complex	z2;
	int			i;

	z = c;
	z2 = (t_complex){z.re * z.re, z.im * z.im};
	i = 0;
	while (z2.re + z.im <= 4 && i < env->max_iter)
	{
		z = (t_complex){z2.re - z2.im + c.re, fabs(2 * z.re * z.im) + c.im};
		z2 = (t_complex){z.re * z.re, z.im * z.im};
		i++;
	}
	return (i);
}

int	beryl(t_env *env, t_complex x)
{
	t_complex	tx;
	t_complex	ty;
	t_complex	y;
	int			i;

	y = (t_complex){1, 0};
	i = 0;
	while (x.re * x.im + y.re * y.im <= 4 && i < env->max_iter)
	{
		tx = x;
		ty = y;
		y = (t_complex){tx.re + ty.re, tx.im + ty.im};
		x = (t_complex){tx.re * ty.re - tx.im * ty.im, tx.re * ty.im + tx.im * ty.re};
		i++;
	}
	return (i);
}
