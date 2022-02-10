/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:00:21 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 15:00:23 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	char	*d_str;
	char	*s_str;
	size_t	dst_len;
	size_t	i;

	d_str = (char *) dst;
	s_str = (char *) src;
	dst_len = ft_strlen(dst);
	i = 0;
	if (dst_size <= dst_len)
		return (ft_strlen(src) + dst_size);
	while (dst_len + i < dst_size - 1 && s_str[i])
	{
		d_str[dst_len + i] = s_str[i];
		i++;
	}
	d_str[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}
