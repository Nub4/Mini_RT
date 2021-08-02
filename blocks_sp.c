/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_sp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:59:19 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:17:43 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_sp(char *str, t_values *val)
{
	str++;
	str++;
	str = ft_first_block_sp(str, val);
	str = ft_third_block_sp(str, val);
	str = ft_fourth_block_sp(str, val);
	if (*str != '\n' && *str != '\0')
		ft_malloc_error(val, 6);
	val->sp_x++;
}

char	*ft_first_block_sp(char *str, t_values *val)
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
	val->sphere[val->sp_x].position.x = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->sphere[val->sp_x].position.y = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->sphere[val->sp_x].position.z = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_third_block_sp(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_3(str, val);
	val->sphere[val->sp_x].radius = ft_atof(ft_strndup_2(str, val), val);
	val->sphere[val->sp_x].radius = val->sphere[val->sp_x].radius / 2;
	free(val->str);
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_fourth_block_sp(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_3(str, val);
	val->sphere[val->sp_x].color.red = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_4(str, val);
	val->sphere[val->sp_x].color.green = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_4(str, val);
	val->sphere[val->sp_x].color.blue = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	while (*str <= '9' && *str >= '0')
		str++;
	return (str);
}
