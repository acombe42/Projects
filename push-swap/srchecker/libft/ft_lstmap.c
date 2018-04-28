/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acombe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 22:25:08 by acombe            #+#    #+#             */
/*   Updated: 2016/11/21 23:44:26 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dst;
	t_list	*begin;

	if (!lst)
		return (NULL);
	if (!(dst = (t_list*)malloc(sizeof(t_list) * (lst->content_size))))
		return (NULL);
	dst = f(lst);
	begin = dst;
	while (lst->next)
	{
		if (!(dst->next =
					(t_list*)malloc(sizeof(t_list) * (lst->content_size))))
			return (NULL);
		lst = lst->next;
		dst->next = f(lst);
		dst = dst->next;
	}
	return (begin);
}
