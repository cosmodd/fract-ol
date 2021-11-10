/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:39:06 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/10 11:35:20 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(t_workspace *ws)
{
	printf("Couldn't allocate memory !");
	free_workspace(ws);
	exit(1);
}

void	argument_error(t_workspace *ws)
{
	printf("You have to specify an argument !\n%s\n",
		"Usage: ./fractol <mandelbrot|julia|burningship>\n");
	free_workspace(ws);
	exit(1);
}
