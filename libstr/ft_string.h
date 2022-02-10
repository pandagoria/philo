/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marmand <marmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:44:54 by marmand           #+#    #+#             */
/*   Updated: 2022/02/02 10:44:55 by marmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_string
{
	char			*c_str;
	unsigned long	size;
	unsigned long	_allocated;
}	t_string;

size_t	ft_strlen(const char *s);
int		ft_str_init(t_string *str, const char *src);
void	ft_str_clear(t_string *str);
int		ft_str_copy(t_string *to, const t_string *src);
int		ft_str_append(t_string *str, char ch);
void	ft_str_pop(t_string *str);
int		ft_str_substr(t_string *to, const t_string *src, int pos, int count);
int		ft_str_paste(t_string *str, const t_string *src, int index);
int		ft_str_find(const t_string *str, const t_string *pattern);
void	ft_str_erase(t_string *str, int pos, int count);
int		ft_str_compare(const t_string *s1, const t_string *s2);
int		ft_str_compare_nchar(const t_string *s1, const t_string *s2, int n);
int		ft_str_c_copy(t_string *to, const char *src);
int		ft_str_c_substr(t_string *to, const char *src, int pos, int count);
int		ft_str_c_paste(t_string *str, const char *src, int index);
int		ft_str_c_find(const t_string *str, const char *pattern);
int		re_alloc(t_string *str, int size);

#endif
