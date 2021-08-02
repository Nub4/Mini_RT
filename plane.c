/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:52:30 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 17:36:30 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	ft_plane(t_values *val, int a)
{
	float denom;
	float t;

	if (a >= val->pl_count)
		return (1);
	denom = ft_vector_dot(ft_vector_normalize(val->plane[a].normal),
	val->ray.direction);
	if (fabsf(denom) > 0)
	{
		t = ft_vector_dot(ft_vector_sub(val->plane[a].plane_point,
		val->ray.start), ft_vector_normalize(val->plane[a].normal)) / denom;
		if (t >= 0.1f && t < val->t)
		{
			val->t = t;
			val->obj = 1;
			val->pl_i = a;
			ft_plane(val, ++a);
			return (1);
		}
	}
	ft_plane(val, ++a);
	return (0);
}

int	ft_plane_2(t_values *val, float q, t_vector v, int a)
{
	float denom;
	float t;

	if (a >= val->pl_count)
		return (0);
	denom = ft_vector_dot(val->plane[a].normal, v);
	if (fabsf(denom) > 0)
	{
		t = ft_vector_dot(ft_vector_sub(val->plane[a].plane_point,
					val->newstart), val->plane[a].normal) / denom;
		if (t >= 0.1f && t < q)
		{
			val->au = 1;
			val->i = 5;
			return (1);
		}
	}
	ft_plane_2(val, q, v, ++a);
	return (0);
}
