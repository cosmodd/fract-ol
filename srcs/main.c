/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:38:53 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/28 16:00:42 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_env(t_env *env)
{
	env->mlx = mlx_init();
	env->width = WIDTH;
	env->height = HEIGHT;
	env->max_iter = MAX_ITER;
	env->window = mlx_new_window(env->mlx, env->width, env->height, "fractol");
	env->frame = new_image(env->mlx, env->width, env->height);
	env->scale_x = env->width / 400.;
	env->scale_y = env->height / 400.;
	env->offset_x = 0;
	env->offset_y = 0;
	env->mmx = 0;
	env->mmy = 0;
	env->res = 1;
	env->rot = 0;
	env->update_mouse = 1;
	mlx_do_key_autorepeaton(env->mlx);
}

void	reset(t_env *env)
{
	env->scale_x = env->width / 400.;
	env->scale_y = env->height / 400.;
	env->offset_x = 0;
	env->offset_y = 0;
	env->rot = 0;
}

void	draw(t_env *env)
{
	t_rfd	x_range;
	t_rfd	y_range;
	double	mrx, mry;
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < env->height)
	{
		x = 0;
		while (x < env->width)
		{
			x_range = (t_rfd){-env->scale_x + env->offset_x, \
								env->scale_x + env->offset_x};
			y_range = (t_rfd){-env->scale_y + env->offset_y, \
								env->scale_y + env->offset_y};
			mrx = range_fd(x, (t_rfd){0, env->width}, x_range);
			mry = range_fd(y, (t_rfd){0, env->height}, y_range);
			rotate(&mrx, &mry, env->rot);
			i = env->f(env, (t_complex){mrx, mry});
			rect(env->frame, (t_rect){x, y, env->res, env->res}, iter_color(env, i));
			x += env->res;
		}
		y += env->res;
	}
	mlx_put_image_to_window(env->mlx, env->window, env->frame.ptr, 0, 0);
}

int	main(int ac, char **av)
{
	t_env	env;

	validate_args(&env, ac, av);
	init_env(&env);
	init_events(&env);
	draw(&env);
	mlx_loop(env.mlx);
	return (0);
}
