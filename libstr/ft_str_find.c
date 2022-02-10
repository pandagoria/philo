/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:34 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:47:21 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_str_find(const t_string *str, const t_string *pattern)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str || !pattern || !str->c_str || !pattern->c_str)
		return (-1);
	while (str->c_str[i])
	{
		while (pattern->c_str[j] && str->c_str[i + j] == pattern->c_str[j])
			j++;
		if (!pattern->c_str[j])
			return (i);
		j = 0;
		i++;
	}
	return (-1);
}

int	ft_str_c_find(const t_string *str, const char *pattern)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str || !pattern || !str->c_str || !pattern)
		return (-1);
	while (str->c_str[i])
	{
		while (pattern[j] && str->c_str[i + j] == pattern[j])
			j++;
		if (!pattern[j])
			return (i);
		j = 0;
		i++;
	}
	return (-1);
}
