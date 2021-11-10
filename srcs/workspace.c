/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workspace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:12:09 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/10 11:25:52 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_workspace	*init_workspace(int width, int height)
{
	t_workspace	*workspace;

	workspace = malloc(sizeof(t_workspace));
	if (!workspace)
		malloc_error(workspace);
	workspace->width = width;
	workspace->height = height;
	workspace->mlx = mlx_init();
	workspace->window = mlx_new_window(
			workspace->mlx,
			width, height,
			"Fract-ol");
	workspace->mouse = 1;
	workspace->max_iter = MAX_ITER;
	workspace->fractal = malloc(sizeof(t_fractal));
	if (!workspace->fractal)
		malloc_error(workspace);
	workspace->fractal->scale = 0.25;
	workspace->fractal->offset_x = 0;
	workspace->fractal->offset_y = 0;
	init_frame(workspace);
	init_hooks(workspace);
	return (workspace);
}

int	free_workspace(t_workspace *workspace)
{
	if (workspace->fractal)
		free(workspace->fractal);
	if (workspace)
		free(workspace);
	return (0);
}

void	init_frame(t_workspace *ws)
{
	ws->frame.img = mlx_new_image(ws->mlx, ws->width, ws->height);
	ws->frame.addr = mlx_get_data_addr(
			ws->frame.img,
			&ws->frame.bits_per_pixel,
			&ws->frame.line_length,
			&ws->frame.endian);
}

void	zoom(t_workspace *workspace, double val)
{
	workspace->fractal->scale *= val;
	workspace->fractal->offset_x *= val;
	workspace->fractal->offset_y *= val;
	threaded_draw(workspace);
}
