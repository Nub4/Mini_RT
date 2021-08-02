/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:03:48 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:16:23 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_c(char *str, t_values *val)
{
	str++;
	str = ft_first_block_c(str, val);
	str = ft_second_block_c(str, val);
	str = ft_third_block_c(str, val);
	if (*str != '\n' && *str != '\0')
		ft_malloc_error(val, 6);
	val->c_x++;
}

char	*ft_first_block_c(char *str, t_values *val)
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
	val->camera[val->c_x].origin.x = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->camera[val->c_x].origin.y = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->camera[val->c_x].origin.z = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_second_block_c(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_5(str, val);
	val->camera[val->c_x].direction.x = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_6(str, val);
	val->camera[val->c_x].direction.y = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_6(str, val);
	val->camera[val->c_x].direction.z = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while (*str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	return (str);
}

char	*ft_third_block_c(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_3(str, val);
	val->camera[val->c_x].fov = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}
