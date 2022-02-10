/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:56:17 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 14:56:19 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*str1;

	str = (char *) dst;
	str1 = (char *) src;
	if (!str && !str1)
		return (0);
	while (n--)
	{
		*str++ = *str1++;
	}
	return (dst);
}
