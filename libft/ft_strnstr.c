/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:03:42 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/26 21:33:41 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int i_temp;

	i = -1;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[++i] && i <= (int)(len - ft_strlen(needle)))
	{
		i_temp = i;
		j = 0;
		while (haystack[i_temp] == needle[j] && haystack[i_temp] && needle[j])
		{
			i_temp++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
	}
	return (0);
}
