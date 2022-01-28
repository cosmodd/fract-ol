/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:00:48 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/28 16:00:57 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

void	rotate(double *x, double *y, double angle)
{
	double	tmp;

	tmp = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = tmp * sin(angle) + *y * cos(angle);
}
