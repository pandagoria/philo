/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:02:03 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 15:02:05 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_l;

	n_l = ft_strlen(needle);
	if (len == 0 && n_l != 0)
		return (NULL);
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (len && *haystack)
	{
		if (ft_strncmp(haystack, needle, n_l) == 0 && len >= n_l)
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (0);
}
