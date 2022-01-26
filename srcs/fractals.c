/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:09:21 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/26 15:17:39 by mrattez          ###   ########.fr       */
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
