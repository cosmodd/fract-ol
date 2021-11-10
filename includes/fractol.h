/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 08:37:58 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/10 11:35:53 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "keys.h"
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# ifndef WIDTH
#  define WIDTH 600
# endif
# ifndef HEIGHT
#  define HEIGHT 600
# endif
# ifndef MAX_ITER
#  define MAX_ITER 100
# endif

// # define TH_H	5
# define TH_N	120
# define PPU	400

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractal
{
	int		(*f)(t_complex, int, double, double);
	double	scale;
	double	offset_x;
	double	offset_y;
}	t_fractal;

typedef struct s_workspace
{
	int			mouse;
	int			max_iter;
	void		*mlx;
	void		*window;
	t_data		frame;
	double		mmx;
	double		mmy;
	double		width;
	double		height;
	t_fractal	*fractal;

}	t_workspace;

typedef struct s_draw
{
	t_workspace	*ws;
	int			y_min;
	int			y_max;
	int			x;
	int			y;
	int			color;
}	t_draw;

// errors.c
void		malloc_error(t_workspace *ws);
void		argument_error(t_workspace *ws);
// color_utils.c
int			get_color(int iteration, t_workspace *workspace);
int			from_rgb(int r, int g, int b);
// number_utils.c
double		map(double value, double xi, double no, double xo);
// fractals.c
int			mandelbrot(t_complex c, int max_i, double mx, double my);
int			julia(t_complex c, int max_i, double mx, double my);
int			burningship(t_complex c, int max_i, double mx, double my);
// image.c
t_data		create_image(t_workspace *workspace);
void		image_pixel_put(t_data data, int x, int y, int color);
// workspace.c
t_workspace	*init_workspace(int width, int height);
int			free_workspace(t_workspace *workspace);
void		init_frame(t_workspace *ws);
void		zoom(t_workspace *workspace, double val);
// hooks.c
void		init_hooks(t_workspace *workspace);
// main.c
void		draw(t_workspace *workspace);
// drawer.c
void		*draw_to_max(void *param);
void		threaded_draw(t_workspace *ws);

#endif
