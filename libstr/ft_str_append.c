/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:15 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:44:16 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_str_append(t_string *str, char ch)
{
	if (!str || !str->c_str)
		return (-1);
	if (ch == '\0')
		return (0);
	if (str->_allocated < str->size + 2)
	{
		if (re_alloc(str, str->size) == 69)
			return (-1);
	}
	str->c_str[str->size] = ch;
	str->size += 1;
	str->c_str[str->size] = 0;
	return (0);
}
