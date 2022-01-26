/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:24:11 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/26 11:04:53 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

int	range_d(int value, t_rd from, t_rd to)
{
	return ((value - from.min)
		* (to.max - to.min) / (from.max - from.min)
		+ to.min);
}

float	range_f(float value, t_rf from, t_rf to)
{
	return ((value - from.min)
		* (to.max - to.min) / (from.max - from.min)
		+ to.min);
}

double	range_fd(double value, t_rfd from, t_rfd to)
{
	return ((value - from.min)
		* (to.max - to.min) / (from.max - from.min)
		+ to.min);
}
