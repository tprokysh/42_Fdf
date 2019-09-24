/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:10:24 by tprokysh          #+#    #+#             */
/*   Updated: 2018/11/12 11:26:00 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		a;
	char	**tab;

	i = -1;
	j = 0;
	if (!s)
		return (0);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_wordlen(s, c) + 1))))
		return (0);
	while (++i < ft_wordcount(s, c))
	{
		a = 0;
		while (s[j] == c)
			j++;
		if (!(tab[i] = ft_strnew((ft_wordlen(s, c) + 1))))
			return (0);
		while (s[j] != c && s[j] != '\0')
			tab[i][a++] = s[j++];
		tab[i][a] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
