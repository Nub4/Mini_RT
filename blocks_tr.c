/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_tr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:55:24 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:18:09 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_tr(char *str, t_values *val)
{
	str++;
	str++;
	str = ft_first_block_tr(str, val);
	str = ft_first_block_tr_2(str, val);
	str = ft_first_block_tr_3(str, val);
	str = ft_fourth_block_tr(str, val);
	if (*str != '\n' && *str != '\0')
		ft_malloc_error(val, 6);
	val->tr_x++;
}

char	*ft_first_block_tr(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str++;
	while (*str && *str != '\n')
	{
		if ((*str <= '9' && *str >= '0') || *str == '-')
			break ;
		if (*str != ' ')
			ft_malloc_error(val, 6);
		str++;
	}
	if (*str == '\0' || *str == '\n')
		ft_malloc_error(val, 6);
	val->triangle[val->tr_x].a.x = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->triangle[val->tr_x].a.y = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->triangle[val->tr_x].a.z = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_first_block_tr_2(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str++;
	while (*str && *str != '\n')
	{
		if ((*str <= '9' && *str >= '0') || *str == '-')
			break ;
		if (*str != ' ')
			ft_malloc_error(val, 6);
		str++;
	}
	if (*str == '\0' || *str == '\n')
		ft_malloc_error(val, 6);
	val->triangle[val->tr_x].b.x = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->triangle[val->tr_x].b.y = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->triangle[val->tr_x].b.z = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_first_block_tr_3(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str++;
	while (*str && *str != '\n')
	{
		if ((*str <= '9' && *str >= '0') || *str == '-')
			break ;
		if (*str != ' ')
			ft_malloc_error(val, 6);
		str++;
	}
	if (*str == '\0' || *str == '\n')
		ft_malloc_error(val, 6);
	val->triangle[val->tr_x].c.x = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->triangle[val->tr_x].c.y = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->triangle[val->tr_x].c.z = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_fourth_block_tr(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_3(str, val);
	val->triangle[val->tr_x].color.red = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_4(str, val);
	val->triangle[val->tr_x].color.green = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_4(str, val);
	val->triangle[val->tr_x].color.blue = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	while (*str <= '9' && *str >= '0')
		str++;
	return (str);
}
