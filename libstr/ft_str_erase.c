/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_erase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:31 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:47:00 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_str_erase(t_string *str, int pos, int count)
{
	unsigned long	i;

	if (!str || !str->c_str || (unsigned long) pos > str->size)
		return ;
	if (count < 0 || (unsigned long)(pos + count) > str->size)
		count = str->size - pos;
	i = 0;
	while (pos + count + i < str->size)
	{
		str->c_str[pos + i] = str->c_str[pos + count + i];
		i++;
	}
	str->c_str[pos + i] = 0;
	str->size -= count;
}
