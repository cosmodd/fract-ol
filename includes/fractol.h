/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:37:58 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/26 15:59:01 by mrattez          ###   ########.fr       */
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
#  define WIDTH 1920
# endif

# ifndef HEIGHT
#  define HEIGHT 980
# endif

# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

# define LMB 1
# define RMB 2
# define MSD 4
# define MSU 5

typedef struct s_env
{
	void	*mlx;
	void	*window;
	t_image	frame;
	int		width;
	int		height;
	int		max_iter;
	int		res;
	double	scale_x;
	double	scale_y;
	double	offset_x;
	double	offset_y;
	double	rot;
}	t_env;

int		validate_args(int ac, char **av);
void	init_events(t_env *env);
int		iter_color(t_env *env, int iter);
int		mandelbrot(t_env *env, t_complex c);
void	draw(t_env *env);

#endif
