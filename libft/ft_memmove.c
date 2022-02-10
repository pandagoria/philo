/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:56:29 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 14:56:30 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*str1;
	size_t	i;

	str = (char *) dst;
	str1 = (char *) src;
	i = 0;
	if (str == 0 && str1 == 0)
		return (0);
	if (str < str1)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (len > 0)
	{
		str[len - 1] = str1[len - 1];
		len--;
	}
	return (dst);
}
