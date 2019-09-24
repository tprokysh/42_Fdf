/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:56:26 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/30 15:48:33 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k_temp;

	i = -1;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[++i])
	{
		k_temp = i;
		j = 0;
		while (haystack[k_temp] == needle[j] && haystack[k_temp] && needle[j])
		{
			k_temp++;
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
	}
	return (0);
}
