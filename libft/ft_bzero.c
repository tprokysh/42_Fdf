/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:14:45 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/30 16:08:58 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	i = 0;
	str = s;
	if (n > 0)
	{
		while (n > 0)
		{
			str[i] = 0;
			i++;
			n--;
		}
	}
}
