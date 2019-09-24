/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:25:20 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/27 15:32:52 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	i = -1;
	s1 = (unsigned char *)s;
	while (++i < n)
		if (s1[i] == (unsigned char)c)
			return ((char *)&s1[i]);
	if (i == n)
		return (0);
	return (0);
}
