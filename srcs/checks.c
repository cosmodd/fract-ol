/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:45:15 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/28 08:21:48 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	printf("\033[104m Usage: \033[0m ./fractol <");
	printf("\033[1;34mmandelbrot\033[0m|");
	printf("\033[1;34mjulia\033[0m|");
	printf("\033[1;34mburningship\033[0m>");
}

void	validate_args(t_env *env, int ac, char **av)
{
	if (ac < 2)
	{
		print_usage();
		exit(0);
	}
	if (!ft_strcmp(av[1], "mandelbrot"))
		env->f = &mandelbrot;
	else if (!ft_strcmp(av[1], "julia"))
		env->f = &julia;
	else if (!ft_strcmp(av[1], "burningship"))
		env->f = &burningship;
	else
	{
		print_usage();
		exit(0);
	}
}
