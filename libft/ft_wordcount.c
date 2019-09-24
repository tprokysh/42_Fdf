/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:21:06 by tprokysh          #+#    #+#             */
/*   Updated: 2018/11/12 11:22:07 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_wordcount(char const *s, char c)
{
	int w;
	int i;
	int b;

	i = 0;
	w = 0;
	b = 0;
	while (s[i])
	{
		if (s[i] != c && !b)
		{
			w++;
			b = 1;
		}
		if (s[i] == c)
			b = 0;
		i++;
	}
	return (w);
}
