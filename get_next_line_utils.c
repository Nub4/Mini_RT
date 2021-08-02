/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:36:34 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:20:32 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int		ft_strlen_2(char *s, t_values *val)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			ft_malloc_error(val, 6);
		i++;
	}
	return (i);
}

int		ft_strlen(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == src || (dst == NULL && src == NULL))
		return (NULL);
	if (d > s)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}

char	*ft_strjoin(t_values *val, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!val->s && !s2)
		return (NULL);
	i = ft_strlen(val->s);
	j = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	ft_memmove(str, val->s, i);
	ft_memmove(str + i, s2, j);
	str[i + j] = '\0';
	if (val->s)
		free(val->s);
	return (str);
}
