/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:54:55 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 20:04:30 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vector	ft_return_point(t_values *val, int a, float x)
{
	t_vector point;

	point =
	ft_vector_add(ft_vector_scalar(ft_vector_normalize(val->cylinder[a].normal),
	x), val->cylinder[a].point);
	return (point);
}

float		ft_return_denom(t_values *val, t_vector v1, int a)
{
	float denom;

	denom =
	ft_vector_dot(ft_vector_scalar(ft_vector_normalize(val->cylinder[a].normal),
	-1), v1);
	return (denom);
}

int			ft_cylinder_2_equation(t_values *val, int a, float t)
{
	val->t = t;
	val->obj = 5;
	val->cy_i = a;
	ft_cylinder_2(val, ++a);
	return (1);
}

void		ft_get_t0(t_values *val, float b, float discr)
{
	val->t0 = (-b + sqrtf(discr)) / (val->a1 * 2);
	val->t1 = (-b - sqrtf(discr)) / (val->a1 * 2);
	if (val->t0 >= 0.1f && val->t1 >= 0.1f)
		val->t0 > val->t1 ? val->t0 = val->t1 : 0;
	else
		val->t0 < 0.1f ? val->t0 = val->t1 : 0;
}

int			ft_cylinder_3(t_values *val, int a)
{
	float		denom;
	float		t;
	t_vector	point;

	if (a >= val->cy_count)
		return (1);
	point = ft_vector_add(
	ft_vector_scalar(ft_vector_normalize(val->cylinder[a].normal),
	0.11f), val->cylinder[a].point);
	denom = ft_vector_dot(ft_vector_scalar(ft_vector_normalize(
	val->cylinder[a].normal), -1), val->ray.direction);
	if (fabsf(denom) > 0)
	{
		t = ft_vector_dot(ft_vector_sub(point, val->ray.start),
		ft_vector_scalar(ft_vector_normalize(val->cylinder[a].normal),
		-1)) / denom;
		if (t >= 0.1f && t < val->t)
			ft_cylinder_3_equation(val, a, t, point);
	}
	ft_cylinder_3(val, ++a);
	return (0);
}
