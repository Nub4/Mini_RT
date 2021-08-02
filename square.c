/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:05:16 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:23:04 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

float           mod(t_vector v)
{
        return (sqrtf(ft_vector_dot(v, v)));
}

float           vcos(t_vector a, t_vector b)
{
        return (ft_vector_dot(a, b) / (mod(a) * mod(b)));
}

int		ft_square_2_equ(t_values *val)
{
	val->au = 1;
	val->i = 2;
	return (1);
}

int		ft_square_2(t_values *val, float q, t_vector v, int a)
{
	float		denom;
	float		t;
	t_vector        ip;
        t_vector        guide;
        t_vector        guide2;
        t_vector        ip2;
        float           cos1;
        float           limit;

	if (a >= val->sq_count)
		return (0);
	val->square[a].normal = ft_vector_normalize(val->square[a].normal);
	val->p = val->square[a].size / 2;
	denom = ft_vector_dot(val->square[a].normal, v);
	if (fabsf(denom) > 0)
	{
		t = ft_vector_dot(ft_vector_sub(val->square[a].center,
					val->newstart), val->square[a].normal) / denom;
		ip = ft_vector_add(val->newstart, ft_vector_scalar(v, t));
                guide = fabs(val->square[a].normal.y) == 1 ? ft_create_vector(1, 0, 0) : ft_create_vector(0, 1, 0);
                guide2 = ft_vector_cross(val->square[a].normal, guide);
                ip2 = ft_vector_sub(ip, val->square[a].center);
                cos1 = fabs(vcos(guide2, ip2));
                if (cos1 < sqrt(2) / 2)
                        cos1 = cos(M_PI_2 - acos(cos1));
                limit = val->p / cos1;
                if (mod(ip2) <= limit)
                        if (t >= 0.1f && t < q)
                                return (ft_square_2_equ(val));
	}
	ft_square_2(val, q, v, ++a);
	return (0);
}

int		ft_square_equ(t_values *val, int a, float t)
{
	val->t = t;
	val->obj = 2;
	val->sq_i = a;
	ft_square(val, ++a);
	return (1);
}

int		ft_square(t_values *val, int a)
{
	float		denom;
	float		t;
	t_vector	ip;
	t_vector	guide;
	t_vector	guide2;
	t_vector	ip2;
	float		cos1;
	float		limit;

	if (a >= val->sq_count)
		return (1);
	val->square[a].normal = ft_vector_normalize(val->square[a].normal);
	val->p = val->square[a].size / 2;
	denom = ft_vector_dot(val->square[a].normal, val->ray.direction);
	if (fabsf(denom) > 0)
	{
		t = ft_vector_dot(ft_vector_sub(val->square[a].center,
			val->ray.start), val->square[a].normal) / denom;
		ip = ft_vector_add(val->ray.start, ft_vector_scalar(val->ray.direction, t));
		guide = fabs(val->square[a].normal.y) == 1 ? ft_create_vector(1, 0, 0) : ft_create_vector(0, 1, 0);
		guide2 = ft_vector_cross(val->square[a].normal, guide);
		ip2 = ft_vector_sub(ip, val->square[a].center);
		cos1 = fabs(vcos(guide2, ip2));
		if (cos1 < sqrt(2) / 2)
			cos1 = cos(M_PI_2 - acos(cos1));
		limit = val->p / cos1;
		if (mod(ip2) <= limit)
			if (t >= 0.1f && t < val->t)
				return (ft_square_equ(val, a, t));
	}
	ft_square(val, ++a);
	return (0);
}
