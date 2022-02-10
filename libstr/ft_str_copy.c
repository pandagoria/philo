/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:29 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:46:29 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_str_copy(t_string *to, const t_string *src)
{
	int	i;

	i = 0;
	if (!src || !to || !src->c_str)
		return (-1);
	if (to->_allocated < src->size + 1)
	{
		if (re_alloc(to, src->size))
			return (-1);
	}
	to->size = src->size;
	while (src->c_str[i])
	{
		to->c_str[i] = src->c_str[i];
		i++;
	}
	to->c_str[i] = 0;
	return (0);
}

int	ft_str_c_copy(t_string *to, const char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(src);
	if (!to || !src)
		return (-1);
	if (to->_allocated < (unsigned long) len + 1)
	{
		if (re_alloc(to, len))
			return (-1);
	}
	to->size = len;
	while (src[i])
	{
		to->c_str[i] = src[i];
		i++;
	}
	to->c_str[i] = 0;
	return (0);
}
