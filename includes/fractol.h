/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:37:58 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/28 08:18:39 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "keys.h"
# include "libft.h"
# include "xutils.h"
# include "colors.h"
# include "maths.h"

# ifndef WIDTH
#  define WIDTH 1080
# endif

# ifndef HEIGHT
#  define HEIGHT 680
# endif

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

# define LMB 1
# define RMB 2
# define MMB 3
# define MSU 4
# define MSD 5

typedef struct s_env
{
	void	*mlx;
	void	*window;
	t_image	frame;
	int		width;
	int		height;
	int		max_iter;
	int		res;
	int		update_mouse;
	double	scale_x;
	double	scale_y;
	double	offset_x;
	double	offset_y;
	double	mmx;
	double	mmy;
	double	rot;
	int		(*f)(struct s_env *, t_complex);
}	t_env;

void	reset(t_env *env);
void	validate_args(t_env *env, int ac, char **av);
void	init_events(t_env *env);
int		iter_color(t_env *env, int iter);
void	draw(t_env *env);

int		mandelbrot(t_env *env, t_complex c);
int		julia(t_env *env, t_complex z);
int		burningship(t_env *env, t_complex c);

#endif
