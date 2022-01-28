/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:09:21 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/28 08:52:00 by mrattez          ###   ########.fr       */
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

// TODO: Implement the beautiful Béryl fractal
// http://samuel.bizien.info/nouvelle_fractale/dossier/synth%C3%A8se/beryl.pdf
int	beryl(t_env *env, t_complex c)
{
	
}
