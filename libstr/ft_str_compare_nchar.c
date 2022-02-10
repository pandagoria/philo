/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_compare_nchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:23 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:46:07 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_str_compare_nchar(const t_string *s1, const t_string *s2, int n)
{
	int	i;

	i = 0;
	if (n <= 0 || !s1 || !s2 || !s1->c_str || !s2->c_str)
		return (0);
	while (i < n - 1 && s1->c_str[i] == s2->c_str[i]
		&& s1->c_str[i] && s2->c_str[i])
		i++;
	return ((unsigned char) s1->c_str[i] - s2->c_str[i]);
}
