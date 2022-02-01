/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:04:11 by mrattez           #+#    #+#             */
/*   Updated: 2021/10/25 10:01:42 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (c == 0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = ft_strlen(s1);
	while (in_set(s1[start], set) && start <= end)
		start++;
	while (in_set(s1[end], set) && end >= start)
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
