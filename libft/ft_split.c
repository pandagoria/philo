/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlaunch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:57:49 by hlaunch           #+#    #+#             */
/*   Updated: 2021/10/15 14:57:51 by hlaunch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_c(char const *s, char c)
{
	int	am;
	int	flag;

	am = 0;
	flag = 0;
	while (*s != '\0')
	{
		if (*s != c && flag == 0)
		{
			am++;
			flag = 1;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (am);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

static void	free_mat(char **mat, int i)
{
	while (i--)
		free(mat[i]);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int		words;
	int		i;

	if (!s)
		return (0);
	words = words_c(s, c);
	mat = (char **) malloc((words + 1) * sizeof(char *));
	if (mat == NULL)
		return (NULL);
	i = 0;
	mat[words] = NULL;
	while (i < words)
	{
		while (*s == c)
			s++;
		mat[i] = ft_substr(s, 0, (word_len(s, c)));
		if (mat[i] == NULL)
			free_mat(mat, i);
		s = (s + word_len(s, c));
		i++;
	}
	return (mat);
}
