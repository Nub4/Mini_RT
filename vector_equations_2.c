/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_equations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:54:34 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 17:49:02 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vector	ft_vector_cross(t_vector v1, t_vector v2)
{
	t_vector v;

	v.x = v1.y * v2.z - v1.z * v2.y;
	v.y = v1.z * v2.x - v1.x * v2.z;
	v.z = v1.x * v2.y - v1.y * v2.x;
	return (v);
}

t_vector	ft_vector_normalize(t_vector v)
{
	t_vector	normal;
	float		len;

	len = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	normal.x = v.x / len;
	normal.y = v.y / len;
	normal.z = v.z / len;
	return (normal);
}

t_vector	ft_create_vector(float a, float b, float c)
{
	t_vector v;

	v.x = a;
	v.y = b;
	v.z = c;
	return (v);
}
