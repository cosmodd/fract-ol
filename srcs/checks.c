/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:45:15 by mrattez           #+#    #+#             */
/*   Updated: 2022/02/01 10:23:36 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	printf("\033[104m Usage: \033[0m ./fractol <");
	printf("\033[1;34mmandelbrot\033[0m|");
	printf("\033[1;34mjulia\033[0m|");
	printf("\033[1;34mburningship\033[0m|");
	printf("\033[1;34mberyl\033[0m>");
}

void	validate_args(t_env *env, int ac, char **av)
{
	if (ac < 2)
	{
		print_usage();
		exit(0);
	}
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		env->f = &mandelbrot;
	else if (!ft_strncmp(av[1], "julia", 6))
		env->f = &julia;
	else if (!ft_strncmp(av[1], "burningship", 12))
		env->f = &burningship;
	else if (!ft_strncmp(av[1], "beryl", 6))
		env->f = &beryl;
	else
	{
		print_usage();
		exit(0);
	}
}
