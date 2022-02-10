/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:00:08 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 15:00:09 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_str;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = (char *) malloc ((s1_len + s2_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	ft_strlcpy(new_str, s1, s1_len + s2_len + 1);
	ft_strlcat(new_str + s1_len, s2, s1_len + s2_len + 1);
	return (new_str);
}
