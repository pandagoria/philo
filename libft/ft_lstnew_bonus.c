/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:55:27 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 14:55:29 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *) malloc (sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}
