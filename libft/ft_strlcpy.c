/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:01:02 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 15:01:06 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	if (ft_strlen(src) + 1 < dst_size)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	else if (dst_size != 0)
	{
		ft_memcpy(dst, src, dst_size - 1);
		dst[dst_size - 1] = '\0';
	}
	return (ft_strlen(src));
}
