/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:48:44 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 19:52:43 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

float	ft_atof2(char *str, t_values *val, float res1, int mark)
{
	float res2;
	float res;

	res2 = (float)ft_atoi(str, val);
	val->len = ft_strlen_2(str, val);
	while (val->len > 0)
	{
		res2 = res2 / 10;
		val->len--;
	}
	if (res1 >= 0)
		res = res1 + res2;
	else
		res = res1 - res2;
	return (res * mark);
}

float	ft_atof(char *str, t_values *val)
{
	float	res1;
	int		mark;

	mark = 1;
	if (str[0] == '0' && ft_isdigit(str[1]) == 1)
		ft_malloc_error(val, 6);
	if (str[0] == '-' && str[1] == '0')
		mark = -1;
	res1 = (float)ft_atoi(str, val);
	while (*str && *str != '.')
		str++;
	if (*str == '\0')
		return (res1);
	if (*str == '.')
		str++;
	if (*str > '9' || *str < '0')
		ft_malloc_error(val, 6);
	return (ft_atof2(str, val, res1, mark));
}

int		ft_atoi(char *str, t_values *val)
{
	int i;
	int res;
	int sign;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] > '9' || str[i] < '0')
		ft_malloc_error(val, 6);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (sign * res);
}

char	*ft_strndup_2(char *s1, t_values *val)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != ',' && s1[i] != ' ' && s1[i] != '\n' && s1[i] != '\0')
		i++;
	if (!(val->str = (char *)malloc(sizeof(char) * i)))
		ft_malloc_error(val, 0);
	while (j < i)
	{
		val->str[j] = s1[j];
		j++;
	}
	val->str[i] = '\0';
	return (val->str);
}

char	*ft_strndup(char *s1, t_values *val)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i] != ' ' && s1[i] != '\n' && s1[i] != '\0')
		i++;
	if (!(val->str = (char *)malloc(sizeof(char) * i)))
		ft_malloc_error(val, 0);
	while (j < i)
	{
		val->str[j] = s1[j];
		j++;
	}
	val->str[i] = '\0';
	return (val->str);
}
