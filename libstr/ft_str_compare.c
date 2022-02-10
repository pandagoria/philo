/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_compare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:25 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:44:26 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_str_compare(const t_string *s1, const t_string *s2)
{
	int	i;

	i = 0;
	while (s1->c_str[i] && s2->c_str[i])
	{
		if (s1->c_str[i] != s2->c_str[i])
			break ;
		i++;
	}
	return ((unsigned char) s1->c_str[i] - s2->c_str[i]);
}
