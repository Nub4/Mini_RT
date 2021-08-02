/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:57:48 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:17:54 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_sq(char *str, t_values *val)
{
	str++;
	str++;
	str = ft_first_block_sq(str, val);
	str = ft_second_block_sq(str, val);
	str = ft_third_block_sq(str, val);
	str = ft_fourth_block_sq(str, val);
	if (*str != '\n' && *str != '\0')
		ft_malloc_error(val, 6);
	val->sq_x++;
}

char	*ft_first_block_sq(char *str, t_values *val)
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
	val->square[val->sq_x].center.x = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->square[val->sq_x].center.y = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->square[val->sq_x].center.z = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_second_block_sq(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_5(str, val);
	val->square[val->sq_x].normal.x = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_6(str, val);
	val->square[val->sq_x].normal.y = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_6(str, val);
	val->square[val->sq_x].normal.z = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while (*str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	return (str);
}

char	*ft_third_block_sq(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_3(str, val);
	val->square[val->sq_x].size = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_fourth_block_sq(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_3(str, val);
	val->square[val->sq_x].color.red = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_4(str, val);
	val->square[val->sq_x].color.green = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_4(str, val);
	val->square[val->sq_x].color.blue = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	while (*str <= '9' && *str >= '0')
		str++;
	return (str);
}
