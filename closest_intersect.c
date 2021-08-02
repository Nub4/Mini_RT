/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:53:52 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 18:52:15 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int		ft_find_shadows(t_values *val, int a)
{
	t_vector	v;
	float		t;

	val->au = 0;
	a = 0;
	v = ft_vector_sub(val->current_light.position, val->newstart);
	t = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	v = ft_vector_normalize(v);
	ft_intersect_2(val, t, v, a);
	a = 0;
	ft_plane_2(val, t, v, a);
	a = 0;
	ft_square_2(val, t, v, a);
	a = 0;
	ft_triangle_2(val, t, v, a);
	a = 0;
	ft_cylinder_shadow(val, t, v, a);
	a = 0;
	ft_cylinder_shadow_2(val, t, v, a);
	a = 0;
	ft_cylinder_shadow_3(val, t, v, a);
	if (val->au == 1)
		return (-1);
	return (val->obj);
}

void	ft_find_intersect_normal_2(t_values *val)
{
	val->n =
	ft_vector_normalize(ft_vector_sub(val->sphere[val->sp_i].position,
	val->newstart));
	if (ft_vector_dot(val->ray.direction, val->n) >= 0)
		val->n = ft_vector_normalize(ft_vector_sub(val->newstart,
		val->sphere[val->sp_i].position));
	val->temp_red = val->sphere[val->sp_i].color.red;
	val->temp_green = val->sphere[val->sp_i].color.green;
	val->temp_blue = val->sphere[val->sp_i].color.blue;
}

void	ft_find_intersect_normal(t_values *val)
{
	if (val->obj == 0)
		ft_find_intersect_normal_2(val);
	else if (val->obj == 4 || val->obj == 5 || val->obj == 6)
		ft_n_c_cylinder(val);
	else if (val->obj == 1 || val->obj == 2)
		ft_n_c_plane_square(val);
	else if (val->obj == 3)
	{
		if (ft_vector_dot(val->ray.direction,
			val->triangle[val->tr_i].normal) >= 0)
			val->n = ft_vector_normalize(
				ft_vector_scalar(val->triangle[val->tr_i].normal, -1));
		else
			val->n = ft_vector_normalize(val->triangle[val->tr_i].normal);
		val->temp_red = val->triangle[val->tr_i].color.red;
		val->temp_green = val->triangle[val->tr_i].color.green;
		val->temp_blue = val->triangle[val->tr_i].color.blue;
	}
}

void	ft_lambertian(t_values *val)
{
	float lambert;

	lambert = ft_vector_dot(val->light_ray.direction, val->n) * val->coef;
	val->red = val->red + lambert * val->current_light.color.red /
		255 * val->current_light.brightness * val->temp_red / 255;
	val->green = val->green + lambert * val->current_light.color.green /
		255 * val->current_light.brightness * val->temp_green / 255;
	val->blue = val->blue + lambert * val->current_light.color.blue /
		255 * val->current_light.brightness * val->temp_blue / 255;
}

void	ft_find_light_value(t_values *val, int a)
{
	t_vector	distance;
	int			i;
	int			shadow;
	float		t;

	i = 0;
	while (i < val->l_count)
	{
		shadow = 0;
		val->current_light = val->light[i];
		distance = ft_vector_sub(val->current_light.position, val->newstart);
		if (ft_vector_dot(val->n, distance) <= 0.0f)
		{
			i++;
			continue;
		}
		t = sqrtf(ft_vector_dot(distance, distance));
		val->light_ray.start = val->newstart;
		val->light_ray.direction = ft_vector_scalar(distance, 1 / t);
		if (ft_find_shadows(val, a) == -1)
			shadow = 1;
		if (shadow == 0)
			ft_lambertian(val);
		i++;
	}
}
