/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:41:42 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/27 15:51:57 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc;
	size_t	lendst;
	int		i;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dst);
	i = 0;
	while (dst[i] && i < (int)dstsize - 1)
		i++;
	if (dst[i] != '\0')
		return (lensrc + dstsize);
	while (*src && i < (int)dstsize - 1)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (lensrc + lendst);
}
