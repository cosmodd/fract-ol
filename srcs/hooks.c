/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:17:46 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/10 11:13:48 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keys(int keycode, t_workspace *workspace)
{
	// printf("Keycode: %d\n", keycode);
	if (keycode == K_ESC)
	{
		mlx_destroy_window(workspace->mlx, workspace->window);
		free_workspace(workspace);
		exit(0);
	}
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
			workspace->fractal->offset_x -= 1;
		if (keycode == K_RIGHT)
			workspace->fractal->offset_x += 1;
		if (keycode == K_DOWN)
			workspace->fractal->offset_y += 1;
		if (keycode == K_UP)
			workspace->fractal->offset_y -= 1;
		threaded_draw(workspace);
	}
	if (keycode == 82)
		workspace->mouse = !workspace->mouse;
	if (keycode == K_PGUP || keycode == K_PGDOWN)
	{
		if (keycode == K_PGUP)
			zoom(workspace, 10);
		if (keycode == K_PGDOWN)
			zoom(workspace, 0.1);
		threaded_draw(workspace);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, t_workspace *workspace)
{
	(void) x;
	(void) y;
	if (button == M_LB)
	{
		workspace->fractal->offset_x += map(x, workspace->width, workspace->width / -2, workspace->width / 2);
		workspace->fractal->offset_y += map(y, workspace->height, workspace->height / -2, workspace->height / 2);
		threaded_draw(workspace);
	}
	if (button >= 4)
	{
		if (button == M_SU)
			zoom(workspace, 1.2);
		if (button == M_SD)
			zoom(workspace, 0.8);
		// printf("Scale: %f\n", workspace->fractal->scale);
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
	mlx_key_hook(workspace->window, &handle_keys, workspace);
	mlx_mouse_hook(workspace->window, &handle_mouse, workspace);
	mlx_hook(workspace->window, 6, 0, &mouse_move, workspace);
}
