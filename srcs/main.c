/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:38:53 by mrattez           #+#    #+#             */
/*   Updated: 2021/11/10 12:22:25 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_fractal(char *av, t_workspace *workspace)
{
	if (!ft_strcmp(av, "mandelbrot"))
		workspace->fractal->f = mandelbrot;
	if (!ft_strcmp(av, "julia"))
	{
		workspace->fractal->f = julia;
		workspace->mouse = 1;
	}
	if (!ft_strcmp(av, "burningship"))
		workspace->fractal->f = burningship;
}

int	main(int ac, char **av)
{
	t_workspace	*workspace;

	if (ac < 2)
		argument_error(workspace);
	workspace = init_workspace(WIDTH, HEIGHT);
	choose_fractal(av[1], workspace);
	threaded_draw(workspace);
	mlx_loop(workspace->mlx);
	return (0);
}
