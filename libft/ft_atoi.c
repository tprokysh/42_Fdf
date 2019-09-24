/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:52:08 by tprokysh          #+#    #+#             */
/*   Updated: 2018/11/13 17:05:13 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	int	space(char c)
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

int			ft_atoi(const char *str)
{
	size_t				i;
	unsigned long int	n;
	int					s;

	i = 0;
	s = 1;
	n = 0;
	while (space(str[i]))
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((n > 922337203685477580 || (n == 922337203685477580
		&& (str[i] - '0') > 7)) && s == 1)
			return (-1);
		else if ((n > 922337203685477580 || (n == 922337203685477580
		&& (str[i] - '0') > 8)) && s == -1)
			return (0);
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * s);
}
