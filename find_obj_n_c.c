/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_obj_n_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:35:16 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 18:13:25 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_n_c_cylinder_2(t_values *val)
{
	if (ft_vector_dot(val->ray.direction,
	val->cylinder[val->cy_i].normal) >= 0)
		val->n = ft_vector_normalize(
		ft_vector_scalar(val->cylinder[val->cy_i].normal, -1));
	else
		val->n = ft_vector_normalize(val->cylinder[val->cy_i].normal);
}

void	ft_n_c_cylinder(t_values *val)
{
	float		len;
	float		temp;
	t_vector	v;

	if (val->obj == 5 || val->obj == 6)
		ft_n_c_cylinder_2(val);
	else if (val->obj == 4)
	{
		v = ft_vector_sub(val->newstart, val->cylinder[val->cy_i].point);
		len = sqrtf(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
		temp = sqrtf(pow(len, 2) -
			pow(val->cylinder[val->cy_i].diameter / 2, 2));
		v =
		ft_vector_scalar(ft_vector_normalize(val->cylinder[val->cy_i].normal),
		temp);
		v = ft_vector_add(v, val->cylinder[val->cy_i].point);
		val->n = ft_vector_normalize(ft_vector_sub(val->newstart, v));
		if (ft_vector_dot(val->ray.direction, val->n) >= 0)
			val->n =
			ft_vector_normalize(ft_vector_scalar(ft_vector_sub(val->newstart,
			v), -1));
	}
	val->temp_red = val->cylinder[val->cy_i].color.red;
	val->temp_green = val->cylinder[val->cy_i].color.green;
	val->temp_blue = val->cylinder[val->cy_i].color.blue;
}

void	ft_n_c_plane_square(t_values *val)
{
	if (val->obj == 1)
	{
		if (ft_vector_dot(val->ray.direction,
				val->plane[val->pl_i].normal) >= 0)
			val->n = ft_vector_normalize(
				ft_vector_scalar(val->plane[val->pl_i].normal, -1));
		else
			val->n = ft_vector_normalize(val->plane[val->pl_i].normal);
		val->temp_red = val->plane[val->pl_i].color.red;
		val->temp_green = val->plane[val->pl_i].color.green;
		val->temp_blue = val->plane[val->pl_i].color.blue;
	}
	else if (val->obj == 2)
	{
		if (ft_vector_dot(val->ray.direction,
				val->square[val->sq_i].normal) >= 0)
			val->n = ft_vector_normalize(
				ft_vector_scalar(val->square[val->sq_i].normal, -1));
		else
			val->n = ft_vector_normalize(val->square[val->sq_i].normal);
		val->temp_red = val->square[val->sq_i].color.red;
		val->temp_green = val->square[val->sq_i].color.green;
		val->temp_blue = val->square[val->sq_i].color.blue;
	}
}
