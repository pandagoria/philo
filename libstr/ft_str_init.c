/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:37 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:44:38 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_str_init(t_string *str, const char *src)
{
	unsigned long	i;

	i = 0;
	str->size = (unsigned long) ft_strlen(src);
	str->c_str = (char *) malloc (sizeof(char) * (str->size + 10));
	if (!str->c_str)
		return (-1);
	str->_allocated = str->size + 10;
	if (str->size == 0)
	{
		*(str->c_str) = '\0';
		return (0);
	}
	while (src[i])
	{
		str->c_str[i] = src[i];
		i++;
	}
	str->c_str[i] = '\0';
	return (0);
}
