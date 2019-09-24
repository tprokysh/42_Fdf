/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:54:52 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 19:26:24 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int		space(char c)
{
	if (c == ' ' ||
	c == '\t' ||
	c == '\n' ||
	c == '\r' ||
	c == '\v' ||
	c == '\f')
		return (1);
	else
		return (0);
}

static int		test_base(const char c)
{
	int		nb;

	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'a' && c <= 'z')
		nb = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nb = c - 'A' + 10;
	else
		nb = -1;
	return (nb);
}

int				ft_atoi_base(const char *str, int str_base)
{
	int		sign;
	int		nb;
	int		current;

	nb = 0;
	sign = 1;
	str += 2;
	while (space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	current = test_base(*str);
	while (current >= 0 && current < str_base)
	{
		nb = nb * str_base + current;
		str++;
		current = test_base(*str);
	}
	return (sign * nb);
}
