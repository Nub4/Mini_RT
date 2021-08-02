/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:49:20 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 20:01:25 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	ft_cylinder_shadow_equ(t_values *val, float q, t_vector v, int a)
{
	t_vector	newstart;
	float		t1;
	float		t2;

	val->a1 = 2 * val->a1;
	val->discr1 = sqrtf(val->discr1);
	val->t0 = (-val->b1 + val->discr1) / val->a1;
	val->t1 = (-val->b1 - val->discr1) / val->a1;
	if (val->t0 >= 0.1f && val->t1 >= 0.1f)
		val->t0 > val->t1 ? val->t0 = val->t1 : 0;
	else
		val->t0 < 0.1f ? val->t0 = val->t1 : 0;
	newstart = ft_vector_add(val->newstart, ft_vector_scalar(v, val->t0));
	t1 = ft_cyplane(val->cylinder[a].normal,
	ft_vector_add(ft_vector_scalar(ft_vector_normalize(val->cylinder[a].normal),
	val->cylinder[a].height), val->cylinder[a].point), newstart);
	t2 = ft_cyplane(ft_vector_scalar(ft_vector_normalize(val->
	cylinder[a].normal), -1), val->cylinder[a].point, newstart);
	if (val->t0 > 0.1f && val->t0 < q && t1 + t2 == 2)
		return (ft_cylinder_shadow_2_equ(val));
	ft_cylinder_shadow(val, q, v, ++a);
	return (0);
}

int	ft_cylinder_shadow(t_values *val, float q, t_vector v, int a)
{
	t_vector	distance;
	float		c;
	float		radius;

	if (a >= val->cy_count)
		return (0);
	radius = val->cylinder[a].diameter / 2;
	val->cross = ft_vector_cross(v, val->cylinder[a].normal);
	distance = ft_vector_sub(val->newstart, val->cylinder[a].point);
	val->cross2 = ft_vector_cross(distance, val->cylinder[a].normal);
	val->a1 = ft_vector_dot(val->cross, val->cross);
	val->b1 = 2 * ft_vector_dot(val->cross, val->cross2);
	c = ft_vector_dot(val->cross2, val->cross2) - ((radius * radius) *
			ft_vector_dot(val->cylinder[a].normal, val->cylinder[a].normal));
	val->discr1 = (val->b1 * val->b1) - (4 * val->a1 * c);
	if (val->discr1 >= 0)
		return (ft_cylinder_shadow_equ(val, q, v, a));
	ft_cylinder_shadow(val, q, v, ++a);
	return (0);
}

int	ft_cylinder_shadow_2_equ(t_values *val)
{
	val->i = 4;
	val->au = 1;
	return (1);
}

int	ft_cylinder_shadow_2(t_values *val, float q, t_vector v1, int a)
{
	float		denom;
	float		t;
	t_vector	point;
	t_vector	newstart;
	t_vector	v;

	if (a >= val->cy_count)
		return (0);
	point = ft_return_point(val, a, val->cylinder[a].height - 0.11f);
	denom = ft_vector_dot(ft_vector_normalize(val->cylinder[a].normal), v1);
	if (fabsf(denom) >= 0)
	{
		t = ft_vector_dot(ft_vector_sub(point, val->newstart),
				ft_vector_normalize(val->cylinder[a].normal)) / denom;
		if (t >= 0.01f && t < q)
		{
			newstart = ft_vector_add(val->newstart, ft_vector_scalar(v1, t));
			v = ft_vector_sub(newstart, point);
			if (sqrtf(ft_vector_dot(v, v)) <= (val->cylinder[a].diameter / 2))
				return (ft_cylinder_shadow_2_equ(val));
		}
	}
	ft_cylinder_shadow_2(val, q, v1, ++a);
	return (0);
}

int	ft_cylinder_shadow_3(t_values *val, float q, t_vector v1, int a)
{
	float		denom;
	float		t;
	t_vector	v;
	t_vector	point;

	if (a >= val->cy_count)
		return (0);
	point = ft_return_point(val, a, 0.11f);
	denom = ft_return_denom(val, v1, a);
	if (fabsf(denom) >= 0)
	{
		t = ft_vector_dot(ft_vector_sub(point, val->newstart),
		ft_vector_scalar(ft_vector_normalize(val->cylinder[a].normal),
		-1)) / denom;
		if (t > 0.01f && t < q)
		{
			v = ft_vector_sub(ft_vector_add(val->newstart,
			ft_vector_scalar(v1, t)), point);
			if (sqrtf(ft_vector_dot(v, v)) <= (val->cylinder[a].diameter / 2))
				return (ft_cylinder_shadow_2_equ(val));
		}
	}
	ft_cylinder_shadow_3(val, q, v1, ++a);
	return (0);
}
