/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprokysh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:25:04 by tprokysh          #+#    #+#             */
/*   Updated: 2018/10/30 16:16:54 by tprokysh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *dst;
	t_list *dlst;

	if (!lst || !f || !(*f))
		return (0);
	if (!(dst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	dlst = f(lst);
	dst = dlst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(dlst->next = f(lst)))
			return (0);
		dlst = dlst->next;
	}
	return (dst);
}
