/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:24:55 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/28 13:12:50 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_press(int keycode, t_env *env)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == ARROW_UP || keycode == ARROW_DOWN)
		env->offset_y += env->scale_y / 10 * ((keycode == ARROW_DOWN) * 2 - 1);
	if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		env->offset_x += env->scale_x / 10 * ((keycode == ARROW_RIGHT) * 2 - 1);
	if (keycode == NUMPAD_PLUS || keycode == NUMPAD_MINUS)
		env->rot += (M_PI / 90) * ((keycode == NUMPAD_PLUS) * 2 - 1);
	if (keycode == EQUAL || keycode == MINUS)
		env->rot += (M_PI / 90) * ((keycode == EQUAL) * 2 - 1);
	if (keycode == SPACE)
		env->update_mouse = !env->update_mouse;
	if (keycode == DIGIT_0 || keycode == NUMPAD_0)
		reset(env);
	draw(env);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_env *env)
{
	t_rfd	x_range;
	t_rfd	y_range;
	double	mx;
	double	my;

	x_range = (t_rfd){-env->scale_x, env->scale_x};
	y_range = (t_rfd){-env->scale_y, env->scale_y};
	if (button == 1)
	{
		env->offset_x += range_fd(x, (t_rfd){0, env->width}, x_range);
		env->offset_y += range_fd(y, (t_rfd){0, env->height}, y_range);
		draw(env);
	}
	if (button == MSU || button == MSD)
	{
		mx = range_fd(x, (t_rfd){0, env->width}, x_range) * ((button == MSU) * 2 - 1);
		my = range_fd(y, (t_rfd){0, env->height}, y_range) * ((button == MSU) * 2 - 1);
		env->offset_x += mx / 10;
		env->offset_y += my / 10;
		env->scale_x *= 0.9 + ((button == MSD) * 0.2);
		env->scale_y *= 0.9 + ((button == MSD) * 0.2);
		draw(env);
	}
	return (0);
}

int	mouse_move(int x, int y, t_env *env)
{
	t_rfd	x_range;
	t_rfd	y_range;

	if (!env->update_mouse)
		return (0);
	x_range = (t_rfd){-env->scale_x, env->scale_x};
	y_range = (t_rfd){-env->scale_y, env->scale_y};
	env->mmx = range_fd(x, (t_rfd){0, env->width}, x_range);
	env->mmy = range_fd(y, (t_rfd){0, env->height}, y_range);
	draw(env);
	return (0);
}

int	on_destroy(void)
{
	exit(0);
	return (0);
}

void	init_events(t_env *env)
{
	mlx_key_hook(env->window, key_press, env);
	mlx_mouse_hook(env->window, mouse_handler, env);
	mlx_hook(env->window, 0x6, 0x0, mouse_move, env);
	mlx_hook(env->window, 0x11, 0x0, on_destroy, NULL);
}
