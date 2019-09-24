/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:38:10 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/28 21:21:32 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1)
		return (0);
	if (!s2)
		return (0);
	if (ft_strcmp(s1, s2) != 0)
		return (0);
	else
		return (1);
}
