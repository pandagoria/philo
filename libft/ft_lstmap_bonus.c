/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:55:17 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 14:55:19 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*beg;

	beg = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst -> content));
		if (!new)
			ft_lstclear(&beg, del);
		lst = lst -> next;
		ft_lstadd_back(&beg, new);
	}
	return (beg);
}
