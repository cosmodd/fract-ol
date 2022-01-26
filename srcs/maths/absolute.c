/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:56:40 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/26 11:02:51 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"

int	abs_d(int value)
{
	return (value * ((value >= 0) * 2 - 1));
}

float	abs_f(float value)
{
	return (value * ((value >= 0) * 2 - 1));
}

double	abs_fd(double value)
{
	return (value * ((value >= 0) * 2 - 1));
}
