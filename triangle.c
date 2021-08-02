/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:49:16 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:23:21 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int		ft_triangle_equ(t_values *val, int a, t_vector tvec, t_vector v0)
{
	tvec = ft_vector_cross(tvec, v0);
	val->b = ft_vector_dot(val->ray.direction, tvec) * val->c;
	if (val->b >= 0 && val->a + val->b <= 1)
	{
		val->t2 = ft_vector_dot(val->v1, tvec) * val->c;
		if (val->t2 > 0.1f && val->t2 < val->t)
		{
			val->t = val->t2;
			val->tr_i = a;
			val->obj = 3;
			ft_triangle(val, ++a);
			return (1);
		}
	}
	ft_triangle(val, ++a);
	return (0);
}

int		ft_triangle(t_values *val, int a)
{
	float		denom;
	t_vector	v0;
	t_vector	pvec;
	t_vector	tvec;

	if (a >= val->tr_count)
		return (1);
	v0 = ft_vector_sub(val->triangle[a].b, val->triangle[a].a);
	val->v1 = ft_vector_sub(val->triangle[a].c, val->triangle[a].a);
	pvec = ft_vector_cross(val->ray.direction, val->v1);
	denom = ft_vector_dot(v0, pvec);
	val->triangle[a].normal = ft_vector_cross(v0, val->v1);
	if (fabsf(denom) >= 0)
	{
		val->c = 1 / denom;
		tvec = ft_vector_sub(val->ray.start, val->triangle[a].a);
		val->a = ft_vector_dot(tvec, pvec) * val->c;
		if (val->a >= 0 && val->a <= 1)
			return (ft_triangle_equ(val, a, tvec, v0));
	}
	ft_triangle(val, ++a);
	return (0);
}

int		ft_triangle_2_equ(t_values *val, float q, t_vector v, int a)
{
	if (val->b >= 0 && val->a + val->b <= 1)
	{
		val->t2 = ft_vector_dot(val->v1, val->tvec) * val->c;
		if (val->t2 > 0.1f && val->t2 < q)
		{
			val->au = 1;
			val->i = 3;
			return (1);
		}
	}
	ft_triangle_2(val, q, v, ++a);
	return (0);
}

int		ft_triangle_2(t_values *val, float q, t_vector v, int a)
{
	t_vector	v0;
	float		denom;
	t_vector	pvec;

	if (a >= val->tr_count)
		return (0);
	v0 = ft_vector_sub(val->triangle[a].b, val->triangle[a].a);
	val->v1 = ft_vector_sub(val->triangle[a].c, val->triangle[a].a);
	pvec = ft_vector_cross(v, val->v1);
	denom = ft_vector_dot(v0, pvec);
	if (fabsf(denom) >= 0.00001f)
	{
		val->c = 1.0f / denom;
		val->tvec = ft_vector_sub(val->newstart, val->triangle[a].a);
		val->a = ft_vector_dot(val->tvec, pvec) * val->c;
		if (val->a >= 0 && val->a <= 1)
		{
			val->tvec = ft_vector_cross(val->tvec, v0);
			val->b = ft_vector_dot(v, val->tvec) * val->c;
			return (ft_triangle_2_equ(val, q, v, a));
		}
	}
	ft_triangle_2(val, q, v, ++a);
	return (0);
}
