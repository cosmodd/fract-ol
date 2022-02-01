/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 10:22:06 by mrattez           #+#    #+#             */
/*   Updated: 2021/10/25 10:01:46 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	sublen;
	size_t	i;

	if (start > (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	sublen = 0;
	while (s[start + sublen] && sublen < len)
		sublen++;
	dst = malloc((sublen + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (i < sublen)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
