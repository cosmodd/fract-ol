/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:24:22 by mrattez           #+#    #+#             */
/*   Updated: 2022/02/01 10:07:12 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include <math.h>

typedef struct s_range_d
{
	int	min;
	int	max;
}	t_rd;

typedef struct s_range_f
{
	float	min;
	float	max;
}	t_rf;

typedef struct s_range_fd
{
	double	min;
	double	max;
}	t_rfd;

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

int		range_d(int value, t_rd from, t_rd to);
float	range_f(float value, t_rf from, t_rf to);
double	range_fd(double value, t_rfd from, t_rfd to);

int		abs_d(int value);
float	abs_f(float value);
double	abs_fd(double value);

void	rotate(double *x, double *y, double angle);

#endif
