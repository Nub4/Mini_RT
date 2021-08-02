/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_equations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:55:33 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 16:43:52 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_vector	ft_vector_add(t_vector v1, t_vector v2)
{
	t_vector v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vector	ft_vector_scalar(t_vector v1, float s)
{
	t_vector v;

	v.x = v1.x * s;
	v.y = v1.y * s;
	v.z = v1.z * s;
	return (v);
}

t_vector	ft_vector_division(t_vector v1, float d)
{
	t_vector v;

	v.x = v1.x * d;
	v.y = v1.y * d;
	v.z = v1.z * d;
	return (v);
}

t_vector	ft_vector_sub(t_vector v1, t_vector v2)
{
	t_vector result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

float		ft_vector_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
