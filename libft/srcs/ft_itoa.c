/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrattez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:32:21 by mrattez           #+#    #+#             */
/*   Updated: 2021/10/22 15:12:03 by mrattez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digit(int n)
{
	size_t	count;

	count = 1;
	while (n / 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_put_digits(char *s, unsigned int n, size_t size)
{
	if (n / 10)
		ft_put_digits(s, n / 10, size - 1);
	s[size] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	unsigned int	neg;
	unsigned int	num;
	size_t			digit_num;
	char			*res;

	digit_num = ft_count_digit(n);
	neg = n < 0;
	num = (unsigned int) n * ((n >= 0) * 2 - 1);
	res = malloc((digit_num + neg + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (neg)
		res[0] = '-';
	ft_put_digits(res, num, digit_num - !neg);
	res[digit_num + neg] = 0;
	return (res);
}
