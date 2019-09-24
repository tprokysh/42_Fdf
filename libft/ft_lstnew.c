/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_lstnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:01:38 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/29 15:01:04 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	lst->next = 0;
	if (!content)
	{
		lst->content = 0;
		lst->content_size = 0;
	}
	else
	{
		if (!(lst->content = malloc(content_size)))
			return (0);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	return (lst);
}
