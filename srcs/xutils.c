/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xutils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:39:53 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/26 14:41:14 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xutils.h"

t_image	new_image(void *mlx, int width, int height)
{
	t_image	image;

	image.ptr = mlx_new_image(mlx, width, height);
	image.data = mlx_get_data_addr(image.ptr,
			&image.bits_per_pixel,
			&image.line_length,
			&image.endian);
	image.width = width;
	image.height = height;
	return (image);
}

void	rect(t_image image, t_rect rect, int color)
{
	int		x;
	int		y;

	x = rect.x;
	while (x < rect.x + rect.width)
	{
		y = rect.y;
		while (y < rect.y + rect.height)
		{
			put_pixel(image, x, y, color);
			y++;
		}
		x++;
	}
}

void	put_pixel(t_image image, int x, int y, int color)
{
	char	*destination;

	if (x < 0 || x >= image.width || y < 0 || y >= image.height)
		return ;
	destination = image.data;
	destination += y * image.line_length + x * (image.bits_per_pixel / 8);
	*(unsigned int *)destination = color;
}

int	get_pixel(t_image image, int x, int y)
{
	char	*source;

	if (x < 0 || x >= image.width || y < 0 || y >= image.height)
		return (0);
	source = image.data;
	source += y * image.line_length + x * (image.bits_per_pixel / 8);
	return (*(unsigned int *)source);
}
