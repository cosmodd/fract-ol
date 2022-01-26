/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:17:56 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/26 11:40:33 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	from_rgb(int r, int g, int b)
{
	r &= 0xFF;
	g &= 0xFF;
	b &= 0xFF;
	return (
		r << 16
		| g << 8
		| b);
}

int	iter_color(t_env *env, int i)
{
	int	r;
	int	g;
	int	b;

	r = range_d(i, (t_rd){0, env->max_iter}, (t_rd){255 * 3, 0});
	g = range_d(i, (t_rd){0, env->max_iter}, (t_rd){255 * 5, 0});
	b = range_d(i, (t_rd){0, env->max_iter}, (t_rd){255 * 8, 0});
	return (from_rgb(r, g, b));
}
