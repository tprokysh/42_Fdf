/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:36:56 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/30 16:19:54 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	psrc = (unsigned char *)src;
	pdest = (unsigned char *)dest;
	if (pdest <= psrc)
		ft_memcpy(dest, src, len);
	else
	{
		while (len--)
			pdest[len] = psrc[len];
	}
	return (dest);
}
