/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:17:46 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/10 13:27:43 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keys_2(int keycode, t_workspace *workspace)
{
	if (keycode == K_SPC)
	{
		workspace->fractal->offset_x = 0;
		workspace->fractal->offset_y = 0;
		workspace->fractal->scale = 0.25;
		threaded_draw(workspace);
	}
	if (keycode >= 123 && keycode <= 126)
	{
		if (keycode == K_LEFT)
			workspace->fractal->offset_x -= 10;
		if (keycode == K_RIGHT)
			workspace->fractal->offset_x += 10;
		if (keycode == K_DOWN)
			workspace->fractal->offset_y += 10;
		if (keycode == K_UP)
			workspace->fractal->offset_y -= 10;
		threaded_draw(workspace);
	}
	return (0);
}

int	handle_keys(int keycode, t_workspace *workspace)
{
	if (keycode == K_ESC)
	{
		mlx_destroy_window(workspace->mlx, workspace->window);
		free_workspace(workspace);
		exit(0);
	}
	if (keycode == 82)
		workspace->mouse = !workspace->mouse;
	if (keycode == K_PGUP || keycode == K_PGDOWN)
	{
		zoom(workspace, 10.0 - 9.9 * (keycode == K_PGDOWN));
		threaded_draw(workspace);
	}
	handle_keys_2(keycode, workspace);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_workspace *workspace)
{
	if (button == M_LB)
	{
		workspace->fractal->offset_x += map(x, workspace->width,
				workspace->width / -2, workspace->width / 2);
		workspace->fractal->offset_y += map(y, workspace->height,
				workspace->height / -2, workspace->height / 2);
		threaded_draw(workspace);
	}
	if (button >= 4)
	{
		zoom(workspace, 0.8 + 0.4 * (button == M_SU));
		threaded_draw(workspace);
	}
	return (0);
}

int	mouse_move(int x, int y, t_workspace *workspace)
{
	if (!workspace->mouse)
		return (0);
	workspace->mmx = map(x + workspace->fractal->offset_x, workspace->width,
			workspace->width / (PPU * -2) / workspace->fractal->scale,
			workspace->width / (PPU * 2) / workspace->fractal->scale);
	workspace->mmy = map(y + workspace->fractal->offset_y, workspace->height,
			workspace->height / (PPU * -2) / workspace->fractal->scale,
			workspace->height / (PPU * 2) / workspace->fractal->scale);
	threaded_draw(workspace);
	return (0);
}

void	init_hooks(t_workspace *workspace)
{
	mlx_key_hook(workspace->window, handle_keys, workspace);
	mlx_mouse_hook(workspace->window, handle_mouse, workspace);
	mlx_hook(workspace->window, 6, 0, mouse_move, workspace);
}
