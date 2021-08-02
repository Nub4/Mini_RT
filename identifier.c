/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:32:24 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:21:16 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_check_right_values_4(t_values *val, int a)
{
	while (a++ < val->pl_count - 1)
	{
		if (val->plane[a].normal.x > 1 || val->plane[a].normal.x < -1
		|| val->plane[a].normal.y > 1 || val->plane[a].normal.y < -1
		|| val->plane[a].normal.z > 1 || val->plane[a].normal.z < -1)
			ft_malloc_error(val, 6);
		if (val->plane[a].color.red > 255 || val->plane[a].color.red < 0
		|| val->plane[a].color.blue > 255 || val->plane[a].color.blue < 0
		|| val->plane[a].color.green > 255 || val->plane[a].color.green < 0)
			ft_malloc_error(val, 6);
	}
	a = -1;
	while (a++ < val->c_count - 1)
	{
		if (val->camera[a].direction.x > 1 || val->camera[a].direction.x < -1
		|| val->camera[a].direction.y > 1 || val->camera[a].direction.y < -1
		|| val->camera[a].direction.z > 1 || val->camera[a].direction.z < -1)
			ft_malloc_error(val, 6);
		if (val->camera[a].fov > 180 || val->camera[a].fov < 0)
			ft_malloc_error(val, 6);
	}
}

void	ft_identifier(char *str, t_values *val)
{
	str++;
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str++;
	str = ft_magic(str, val);
	val->width = ft_atoi(ft_strndup(str, val), val);
	free(val->str);
	while (*str != ' ')
		str++;
	str = ft_magic(str, val);
	val->height = ft_atoi(ft_strndup(str, val), val);
	free(val->str);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str != '\0' && *str != '\n')
		ft_malloc_error(val, 6);
	val->r_count++;
}
