/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:50:49 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:50:50 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	re_alloc(t_string *str, int size)
{
	char	*new;
	int		i;

	new = (char *) malloc(sizeof(char) * size * 2);
	if (!new)
		return (69);
	i = 0;
	while (str->c_str[i])
	{
		new[i] = str->c_str[i];
		i++;
	}
	new[i] = 0;
	free(str->c_str);
	str->c_str = new;
	str->_allocated = size * 2;
	return (0);
}
