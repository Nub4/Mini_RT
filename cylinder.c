/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:42:12 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 20:19:21 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	ft_cyplane(t_vector normal, t_vector point, t_vector start)
{
	float		denom;
	float		t;
	float		t0;
	t_vector	direction;

	direction = normal;
	t0 = 20000.0f;
	denom = ft_vector_dot(normal, direction);
	if (fabsf(denom) > 0)
	{
		t = ft_vector_dot(ft_vector_sub(point, start), normal) / denom;
		if (t >= 0.1f && t < t0)
			return (1);
	}
	return (0);
}

int	ft_cylinder_equation(t_values *val, int a, float discr, float b)
{
	t_vector	newstart;
	float		t1;
	float		t2;

	ft_get_t0(val, b, discr);
	newstart = ft_vector_add(val->ray.start,
			ft_vector_scalar(val->ray.direction, val->t0));
	t1 = ft_cyplane(val->cylinder[a].normal,
	ft_vector_add(ft_vector_scalar(ft_vector_normalize(val->cylinder[a].normal),
	val->cylinder[a].height), val->cylinder[a].point), newstart);
	t2 =
	ft_cyplane(ft_vector_scalar(ft_vector_normalize(val->cylinder[a].normal),
	-1), val->cylinder[a].point, newstart);
	if (val->t0 > 0.1f && val->t0 < val->t && t1 + t2 == 2)
	{
		val->obj = 4;
		val->t = val->t0;
		val->cy_i = a;
		ft_cylinder(val, ++a);
		return (1);
	}
	ft_cylinder(val, ++a);
	return (0);
}

int	ft_cylinder(t_values *val, int a)
{
	t_vector	distance;
	float		b;
	float		c;
	float		radius;
	float		discr;

	if (a >= val->cy_count)
		return (1);
	radius = val->cylinder[a].diameter / 2;
	val->cross = ft_vector_cross(val->ray.direction, val->cylinder[a].normal);
	distance = ft_vector_sub(val->ray.start, val->cylinder[a].point);
	val->cross2 = ft_vector_cross(distance, val->cylinder[a].normal);
	val->a1 = ft_vector_dot(val->cross, val->cross);
	b = 2 * ft_vector_dot(val->cross, val->cross2);
	c = ft_vector_dot(val->cross2, val->cross2) - ((radius * radius) *
			ft_vector_dot(val->cylinder[a].normal, val->cylinder[a].normal));
	discr = (b * b) - (4 * val->a1 * c);
	if (discr >= 0)
		return (ft_cylinder_equation(val, a, discr, b));
	ft_cylinder(val, ++a);
	return (0);
}

int	ft_cylinder_2(t_values *val, int a)
{
	float		denom;
	float		t;
	t_vector	point;
	t_vector	v;

	if (a >= val->cy_count)
		return (1);
	point = ft_return_point(val, a, val->cylinder[a].height - 0.11f);
	denom = ft_vector_dot(ft_vector_normalize(val->cylinder[a].normal),
	val->ray.direction);
	if (fabsf(denom) > 0)
	{
		t = ft_vector_dot(ft_vector_sub(point, val->ray.start),
				ft_vector_normalize(val->cylinder[a].normal)) / denom;
		if (t >= 0.0f && t < val->t)
		{
			v = ft_vector_sub(ft_vector_add(val->ray.start,
			ft_vector_scalar(val->ray.direction, t)), point);
			if (sqrtf(ft_vector_dot(v, v)) <= (val->cylinder[a].diameter / 2))
				return (ft_cylinder_2_equation(val, a, t));
		}
	}
	ft_cylinder_2(val, ++a);
	return (0);
}

int	ft_cylinder_3_equation(t_values *val, int a, float t, t_vector point)
{
	t_vector newstart;
	t_vector v;

	newstart = ft_vector_add(val->ray.start,
	ft_vector_scalar(val->ray.direction, t));
	v = ft_vector_sub(newstart, point);
	if (sqrtf(ft_vector_dot(v, v)) <= (val->cylinder[a].diameter / 2))
	{
		val->t = t;
		val->obj = 6;
		val->cy_i = a;
		ft_cylinder_3(val, ++a);
		return (1);
	}
	ft_cylinder_3(val, ++a);
	return (0);
}
