/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:53:44 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 14:53:46 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		n_len;

	n_len = len(n);
	str = (char *) malloc ((n_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", 12);
	str[n_len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[n_len - 1] = (n % 10) + '0';
		n_len--;
		n = n / 10;
	}
	return (str);
}
