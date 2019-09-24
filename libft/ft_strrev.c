/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrev.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 15:52:33 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/30 15:53:38 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *src)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	i--;
	while (j < i)
	{
		tmp = src[i];
		src[i] = src[j];
		src[j] = tmp;
		i--;
		j++;
	}
	return (src);
}
