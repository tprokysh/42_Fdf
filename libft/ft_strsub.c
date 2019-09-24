/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:56:44 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/28 16:47:10 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;

	if (!s)
		return (0);
	if (!(dst = ft_strnew(len)))
		return (0);
	else
	{
		i = -1;
		s = s + start;
		while (++i < len)
			dst[i] = s[i];
	}
	return (dst);
}
