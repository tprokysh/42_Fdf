/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:09:37 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/27 17:02:04 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	i = -1;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (++i < n && c1[i] == c2[i])
		;
	if (i == n)
		return (0);
	else
		return (c1[i] - c2[i]);
}
