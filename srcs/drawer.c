/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:13:35 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/10 11:04:27 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_to_max(void *param)
{
	t_draw		d;
	int			it;
	t_complex	c;

	d = *(t_draw *)param;
	d.x = 0;
	while (d.x < WIDTH)
	{
		d.y = d.y_min;
		while (d.y < d.y_max)
		{
			c.r = map(d.x + d.ws->fractal->offset_x, d.ws->width,
					d.ws->width / (PPU * -2) / d.ws->fractal->scale,
					d.ws->width / (PPU * 2) / d.ws->fractal->scale);
			c.i = map(d.y + d.ws->fractal->offset_y, d.ws->height,
					d.ws->height / (PPU * -2) / d.ws->fractal->scale,
					d.ws->height / (PPU * 2) / d.ws->fractal->scale);
			it = d.ws->fractal->f(c, d.ws->max_iter, d.ws->mmx, d.ws->mmy);
			image_pixel_put(d.ws->frame, d.x, d.y, get_color(it, d.ws));
			d.y++;
		}
		d.x++;
	}
	return (param);
}

void	threaded_draw(t_workspace *ws)
{
	t_draw		draws[TH_N];
	pthread_t	threads[TH_N];
	int			i;

	i = 0;
	while (i < TH_N)
	{
		draws[i].color = 265;
		draws[i].y_min = (ws->height / TH_N) * i;
		draws[i].y_max = (ws->height / TH_N) * (i + 1);
		draws[i].ws = ws;
		pthread_create(&threads[i], NULL, draw_to_max, &draws[i]);
		i++;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(ws->mlx, ws->window, ws->frame.img, 0, 0);
}
