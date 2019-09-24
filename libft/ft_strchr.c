/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 21:09:00 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/30 16:22:26 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int j;
	int len;

	i = -1;
	j = 0;
	len = ft_strlen(s) + 1;
	while (++i < len)
	{
		if (s[j] == c)
			return ((char *)&s[j]);
		if (s[j++] == '\0')
			return (0);
	}
	return (0);
}
