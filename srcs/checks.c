/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:45:15 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/26 15:23:22 by mrattez          ###   ########.fr       */
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

int	validate_args(int ac, char **av)
{
	(void) av;
	if (ac < 2)
	{
		print_usage();
		exit(0);
	}
	if (!ft_strcmp(av[1], "mandelbrot"))
		return (0);
	if (!ft_strcmp(av[2], "julia"))
		return (0);
	if (!ft_strcmp(av[3], "burningship"))
		return (0);
	print_usage();
	exit(0);
}
