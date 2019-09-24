/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:35:28 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/30 15:39:17 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_digrev(int n)
{
	return (n * -1);
}

static int	ft_diglen(int n)
{
	int l;

	l = 0;
	if (n <= 0)
	{
		n = ft_digrev(n);
		l++;
	}
	while (n >= 1)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char		*ft_itoa(int n)
{
	size_t		i;
	char		*dst;
	size_t		s;

	if (!(dst = (char *)malloc(sizeof(char) * (ft_diglen(n) + 1))))
		return (0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648\0"));
	i = 0;
	s = ft_diglen(n);
	dst[s] = '\0';
	if (n < 0)
	{
		dst[0] = '-';
		n = ft_digrev(n);
		i++;
	}
	while (i < s--)
	{
		dst[s] = (n % 10) + '0';
		n = n / 10;
	}
	return (dst);
}
