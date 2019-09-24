/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:29:01 by tprokysh          #+#    #+#             */
/*   Updated: 2019/02/15 19:27:11 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int					char_to_int(int c)
{
	char	s[12];
	char	*hex;
	int		i;
	int		result;

	i = 0;
	result = 0;
	hex = ft_memmove(s, "aAbBcCdDeEfF", 12);
	while (result == 0 && hex[i] != '\0')
	{
		if (hex[i] == c)
			result = 10 + (i / 2);
		i++;
	}
	return (result);
}

unsigned int		ft_atoi_hex(char *s)
{
	unsigned int	value;
	int				i;

	i = 0;
	value = 0;
	while (s[i] != 'x' && s[i])
		i++;
	if (s[i] == 'x')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			value = (value * 16) + (s[i] - '0');
		else
			value = (value * 16) + char_to_int(s[i]);
		i++;
	}
	return (value);
}
