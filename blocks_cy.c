/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_cy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:03:13 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:16:40 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_cy(char *str, t_values *val)
{
	str++;
	str++;
	str = ft_first_block_cy(str, val);
	str = ft_second_block_cy(str, val);
	str = ft_third_block_cy(str, val);
	str = ft_third_block_cy_2(str, val);
	str = ft_fourth_block_cy(str, val);
	if (*str != '\n' && *str != '\0')
		ft_malloc_error(val, 6);
	val->cy_x++;
}

char	*ft_first_block_cy(char *str, t_values *val)
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
	val->cylinder[val->cy_x].point.x = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->cylinder[val->cy_x].point.y = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_2(str, val);
	str++;
	val->cylinder[val->cy_x].point.z = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_second_block_cy(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_5(str, val);
	val->cylinder[val->cy_x].normal.x = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_6(str, val);
	val->cylinder[val->cy_x].normal.y = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_6(str, val);
	val->cylinder[val->cy_x].normal.z = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while (*str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	return (str);
}

char	*ft_third_block_cy(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_3(str, val);
	val->cylinder[val->cy_x].diameter = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_third_block_cy_2(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_3(str, val);
	val->cylinder[val->cy_x].height = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}
