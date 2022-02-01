/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 09:52:30 by mrattez           #+#    #+#             */
/*   Updated: 2022/02/01 10:22:58 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_env *e)
{
	double	mmx;
	double	mmy;
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < e->height)
	{
		x = 0;
		while (x < e->width)
		{
			mmx = range_fd(x, (t_rfd){0, e->width}, \
				(t_rfd){-e->scale_x + e->offset_x, e->scale_x + e->offset_x});
			mmy = range_fd(y, (t_rfd){0, e->height}, \
				(t_rfd){-e->scale_y + e->offset_y, e->scale_y + e->offset_y});
			rotate(&mmx, &mmy, e->rot);
			i = e->f(e, (t_complex){mmx, mmy});
			rect(e->frame, (t_rect){x, y, e->res, e->res}, iter_color(e, i));
			x += e->res;
		}
		y += e->res;
	}
	mlx_put_image_to_window(e->mlx, e->window, e->frame.ptr, 0, 0);
}
