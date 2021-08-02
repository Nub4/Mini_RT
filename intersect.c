/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:18:51 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 17:50:35 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	ft_intersect_equ(t_values *val, int a, float t0, float t1)
{
	if (t0 >= 0 && t1 >= 0)
		t0 > t1 ? t0 = t1 : 0;
	else
		t0 < 0 ? t0 = t1 : 0;
	if (t0 > 0.1f && t0 < val->t)
	{
		val->t = t0;
		val->obj = 0;
		val->sp_i = a;
		ft_intersect(val, ++a);
		return (1);
	}
	ft_intersect(val, ++a);
	return (0);
}

int	ft_intersect(t_values *val, int a)
{
	float		t0;
	float		t1;
	float		b;
	t_vector	distance;

	if (a >= val->sp_count)
		return (1);
	distance = ft_vector_sub(val->ray.start, val->sphere[a].position);
	b = 2 * (val->ray.direction.x * distance.x + val->ray.direction.y *
		distance.y + val->ray.direction.z * distance.z);
	val->discr = b * b - 4 * ft_vector_dot(val->ray.direction,
		val->ray.direction) * (ft_vector_dot(distance, distance) -
		(val->sphere[a].radius * val->sphere[a].radius));
	if (val->discr > 0)
	{
		val->discr = sqrtf(val->discr);
		t0 = (-b + val->discr) / 2;
		t1 = (-b - val->discr) / 2;
		ft_intersect_equ(val, a, t0, t1);
	}
	ft_intersect(val, ++a);
	return (0);
}

int	ft_intersect_2_equ(t_values *val, float q, float t0, float t1)
{
	if (t0 >= 0.1f && t1 >= 0.1f)
		t0 > t1 ? t0 = t1 : 0;
	else
		t0 < 0.1f ? t0 = t1 : 0;
	if (t0 > 0.1f - 0.1f && t0 < q)
	{
		val->au = 1;
		val->i = 1;
		return (1);
	}
	return (0);
}

int	ft_intersect_2(t_values *val, float q, t_vector v, int a)
{
	float		sqrtdiscr;
	float		t0;
	float		t1;
	float		b;
	t_vector	distance;

	if (a >= val->sp_count)
		return (0);
	distance = ft_vector_sub(val->newstart, val->sphere[a].position);
	b = 2 * (v.x * distance.x + v.y * distance.y + v.z * distance.z);
	val->discr = b * b - 4 * ft_vector_dot(v, v) *
		(ft_vector_dot(distance, distance) -
		(val->sphere[a].radius * val->sphere[a].radius));
	if (val->discr > 0)
	{
		sqrtdiscr = sqrtf(val->discr);
		t0 = (-b + sqrtdiscr) / 2;
		t1 = (-b - sqrtdiscr) / 2;
		if (ft_intersect_2_equ(val, q, t0, t1) == 1)
			return (1);
	}
	ft_intersect_2(val, q, v, ++a);
	return (0);
}
