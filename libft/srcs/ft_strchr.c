/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 12:25:24 by mrattez           #+#    #+#             */
/*   Updated: 2021/10/20 14:41:20 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*out;
	char	search;

	out = (char *)s;
	search = c;
	while (*out)
	{
		if (*out == search)
			return (out);
		out++;
	}
	if (*out == c)
		return (out);
	return ((void *)0);
}
