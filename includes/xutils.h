/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xutils.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <mrattez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:40:13 by mrattez           #+#    #+#             */
/*   Updated: 2022/01/26 15:26:02 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XUTILS_H
# define XUTILS_H

# include "mlx.h"

typedef struct s_image
{
	void	*ptr;
	char	*data;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
}	t_rect;

void	recreate_image(void *mlx, t_image *image);
t_image	new_image(void *mlx, int width, int height);
void	rect(t_image image, t_rect rect, int color);
void	put_pixel(t_image image, int x, int y, int color);
int		get_pixel(t_image image, int x, int y);

#endif
