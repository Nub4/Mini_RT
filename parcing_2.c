/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:09:32 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:22:42 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_check_right_values_2(t_values *val, int a)
{
        while (a++ < val->sp_count - 1)
        {
                if (val->sphere[a].radius < 0)
                        ft_malloc_error(val, 6);
                if (val->sphere[a].color.red > 255 || val->sphere[a].color.red < 0
                || val->sphere[a].color.blue > 255 || val->sphere[a].color.blue < 0
                || val->sphere[a].color.green > 255 || val->sphere[a].color.green < 0)
                        ft_malloc_error(val, 6);
        }
        a = -1;
        while (a++ < val->sq_count - 1)
        {
                if (val->square[a].normal.x > 1 || val->square[a].normal.x < -1
                || val->square[a].normal.y > 1 || val->square[a].normal.y < -1
                || val->square[a].normal.z > 1 || val->square[a].normal.z < -1)
                        ft_malloc_error(val, 6);
                if (val->square[a].size < 0)
                        ft_malloc_error(val, 6);
                if (val->square[a].color.red > 255 || val->square[a].color.red < 0
                || val->square[a].color.blue > 255 || val->square[a].color.blue < 0
                || val->square[a].color.green > 255 || val->square[a].color.green < 0)
                        ft_malloc_error(val, 6);
        }
}

void	ft_check_right_values_3(t_values *val, int a)
{
	while (a++ < val->tr_count - 1)
        {
                if (val->triangle[a].color.red > 255 || val->triangle[a].color.red < 0
                || val->triangle[a].color.blue > 255 || val->triangle[a].color.blue < 0
                || val->triangle[a].color.green > 255 || val->triangle[a].color.green < 0)
                        ft_malloc_error(val, 6);
        }
        a = -1;
	while (a++ < val->cy_count - 1)
        {
                if (val->cylinder[a].normal.x > 1 || val->cylinder[a].normal.x < -1
                || val->cylinder[a].normal.y > 1 || val->cylinder[a].normal.y < -1
                || val->cylinder[a].normal.z > 1 || val->cylinder[a].normal.z < -1)
                        ft_malloc_error(val, 6);
                if (val->cylinder[a].diameter < 0)
                        ft_malloc_error(val, 6);
                if (val->cylinder[a].height < 0)
                        ft_malloc_error(val, 6);
                if (val->cylinder[a].color.red > 255 || val->cylinder[a].color.red < 0
                || val->cylinder[a].color.blue > 255 || val->cylinder[a].color.blue < 0
                || val->cylinder[a].color.green > 255 || val->cylinder[a].color.green < 0)
                        ft_malloc_error(val, 6);
        }
}

void	ft_check_right_values(t_values *val)
{
	int a;

	a = -1;
	ft_check_right_values_2(val, a);
	ft_check_right_values_3(val, a);
	ft_check_right_values_4(val, a);
	while (a++ < val->l_count - 1)
	{
		if (val->light[a].brightness > 1 || val->light[a].brightness < -1)
			ft_malloc_error(val, 6);
		if (val->light[a].color.red > 255 || val->light[a].color.red < 0
                || val->light[a].color.blue > 255 || val->light[a].color.blue < 0
                || val->light[a].color.green > 255 || val->light[a].color.green < 0)
                        ft_malloc_error(val, 6);
	}
}

void	ft_check_scene_rules(t_values *val)
{
	if (val->ambient.brightness > 1 || val->ambient.brightness < -1)
		ft_malloc_error(val, 6);
	if (val->ambient.color.green > 255 || val->ambient.color.green < 0 || val->ambient.color.red > 255
	|| val->ambient.color.red < 0 || val->ambient.color.blue > 255 || val->ambient.color.blue < 0)
		ft_malloc_error(val, 6);
	if (val->width > 1920)
		val->width = 1920;
	if (val->height > 1080)
		val->height = 1080;
}

void	ft_zero(t_values *val)
{
	val->triangle = NULL;
	val->sphere = NULL;
	val->plane = NULL;
	val->square = NULL;
	val->camera = NULL;
	val->light = NULL;
	val->cylinder = NULL;
	val->ca = 0;
	val->a_count = 0;
	val->r_count = 0;
	val->l_x = 0;
	val->sp_x = 0;
	val->pl_x = 0;
	val->sq_x = 0;
	val->c_x = 0;
	val->tr_x = 0;
	val->cy_x = 0;
	val->sp_count = 0;
	val->tr_count = 0;
	val->pl_count = 0;
	val->sq_count = 0;
	val->cy_count = 0;
	val->c_count = 0;
	val->l_count = 0;
}
