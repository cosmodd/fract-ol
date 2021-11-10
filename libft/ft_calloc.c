/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:09:37 by mrattez           #+#    #+#             */
/*   Updated: 2021/10/19 16:13:56 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;
	size_t	i;

	dest = malloc(count * size);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
		((unsigned char *)dest)[i++] = 0;
	return (dest);
}
