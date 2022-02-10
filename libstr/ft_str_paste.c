/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_paste.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:39 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:50:15 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_str_paste(t_string *str, const t_string *src, int index)
{
	unsigned long	i;

	if (!str || !src || !str->c_str || !src->c_str)
		return (-1);
	if (index < 0 || (unsigned long) index > str->size)
		index = str->size;
	if (str->_allocated < src->size + str->size + 1)
	{
		if (re_alloc(str, src->size + str->size))
			return (-1);
	}
	i = index;
	ft_memmove(str->c_str + src->size, str->c_str + index, str->size - index);
	str->c_str[src->size + str->size] = 0;
	i = -1;
	while (++i < src->size)
		str->c_str[index + i] = src->c_str[i];
	str->size += src->size;
	return (0);
}

int	ft_str_c_paste(t_string *str, const char *src, int index)
{
	unsigned long	i;
	unsigned long	len;

	len = ft_strlen(src);
	if (!str || !src || !str->c_str)
		return (-1);
	if (index < 0 || (unsigned long) index > str->size)
		index = str->size;
	if (str->_allocated < len + str->size + 1)
	{
		if (re_alloc(str, len + str->size))
			return (-1);
	}
	ft_memmove(str->c_str + len, str->c_str + index, str->size - index);
	str->c_str[len + str->size] = 0;
	i = -1;
	while (++i < len)
		str->c_str[index + i] = src[i];
	str->size += len;
	return (0);
}
