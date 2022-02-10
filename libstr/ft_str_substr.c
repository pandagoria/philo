/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_substr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:44 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:50:41 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_str_substr(t_string *to, const t_string *src, int pos, int count)
{
	if (!src->c_str || pos < 0 || !to || (unsigned long) pos > src->size)
		return (-1);
	if (count < 0 || (unsigned long)(pos + count) > src->size)
		return (ft_str_substr(to, src, pos, (int) src->size - pos));
	if (to->_allocated < (unsigned long) count)
	{
		if (re_alloc(to, count) == 69)
			return (-1);
	}
	if ((unsigned long) pos > src->size)
	{
		*(to->c_str) = '\0';
		to->size = 0;
	}
	to->size = count;
	to->c_str[count] = 0;
	while (--count >= 0)
		to->c_str[count] = src->c_str[pos + count];
	return (0);
}

int	ft_str_c_substr(t_string *to, const char *src, int pos, int count)
{
	int	len;

	len = ft_strlen(src);
	if (!src || pos < 0 || !to || pos > len)
		return (-1);
	if (count < 0 || pos + count > len)
		return (ft_str_c_substr(to, src, pos, len - pos));
	if (to->_allocated < (unsigned long) count)
	{
		if (re_alloc(to, count) == 69)
			return (-1);
	}
	if (pos > len)
	{
		*(to->c_str) = '\0';
		to->size = 0;
	}
	to->size = count;
	to->c_str[count] = 0;
	while (--count >= 0)
		to->c_str[count] = src[pos + count];
	return (0);
}
