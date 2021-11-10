/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 09:42:29 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/10 08:57:02 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iteration, t_workspace *workspace)
{
	int	r;
	int	g;
	int	b;

	r = map(iteration, workspace->max_iter, 2, 0) * 255;
	g = map(iteration, workspace->max_iter, 5, 0) * 255;
	b = map(iteration, workspace->max_iter, 8, 0) * 255;
	return (from_rgb(r, g, b));
}

int	from_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
