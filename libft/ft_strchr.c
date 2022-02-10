/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:58:01 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 14:58:02 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*pntr;

	i = 0;
	pntr = (char *) str;
	while (pntr[i])
	{
		if (pntr[i] == (char) ch)
			return (&pntr[i]);
		i++;
	}
	if (ch == '\0')
		return (&pntr[i]);
	return (0);
}
