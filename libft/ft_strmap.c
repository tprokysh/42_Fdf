/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 18:01:48 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/30 16:24:56 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dst;

	i = -1;
	if (!s)
		return (0);
	if (!(dst = ft_strnew(ft_strlen(s))))
		return (0);
	while (s[++i])
		dst[i] = f(s[i]);
	dst[i] = '\0';
	return (dst);
}
