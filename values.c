/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:56:06 by minummin          #+#    #+#             */
/*   Updated: 2021/03/13 16:41:30 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void		ft_val_values(t_values *val, int i)
{
	val->argc_value = i;
	val->endian = 0;
	val->line_length = val->width;
	val->bits_per_pixel = 24;
}

t_vector	ft_camera_dir2(t_values *val, t_vector right, t_vector up)
{
	t_vector	dir;
	float		norm_x;
	float		norm_y;
	t_vector	image_point;

	norm_x = ((val->x / (float)val->width) - 0.5) * val->radian;
	norm_y = ((val->y / (float)val->height) - 0.5) * val->radian;
	val->width < val->height ? norm_x *= val->camera[val->ca].aspect : 0;
	val->width > val->height ? norm_y /= val->camera[val->ca].aspect : 0;
	image_point =
	ft_vector_add(ft_vector_add(ft_vector_add(ft_vector_scalar(right, norm_x),
	ft_vector_scalar(up, norm_y)), val->camera[val->ca].origin),
	ft_vector_normalize(val->camera[val->ca].direction));
	dir = ft_vector_normalize(ft_vector_sub(image_point,
	val->camera[val->ca].origin));
	return (dir);
}

t_vector	ft_camera_dir(t_values *val, t_vector upguide)
{
	t_vector right;
	t_vector up;
	t_vector rightguide;

	rightguide = ft_create_vector(-1, 0, 0);
	if (val->camera[val->ca].direction.y == 1 || val->camera[val->ca].direction.y == -1)
	{
		val->camera[val->ca].direction = ft_vector_normalize(val->camera[val->ca].direction);
		if (val->camera[val->ca].direction.z < 0)
			rightguide.x = 1;
		up = ft_vector_scalar(ft_vector_cross(rightguide,
		ft_vector_normalize(val->camera[val->ca].direction)), -1);
		right =
		ft_vector_cross(ft_vector_normalize(val->camera[val->ca].direction),
		up);
	}
	else
	{
	val->camera[val->ca].direction = ft_vector_normalize(val->camera[val->ca].direction);
	right = ft_vector_normalize(ft_vector_cross(val->camera[val->ca].direction, upguide));
	up = ft_vector_cross(right,
	ft_vector_normalize(val->camera[val->ca].direction));
	}
	return (ft_camera_dir2(val, right, up));
}

void		ft_ray_values(t_values *val)
{
	t_vector upguide;
	t_vector ye;
	float angle;

	angle = ft_vector_dot(val->camera[val->ca].direction, ft_create_vector(0, -1, 0));
	ye = ft_vector_normalize(val->camera[val->ca].direction);
	upguide.x = ye.x * (-1) * sinf(angle);
	upguide.y = -1 * cosf(angle);
	upguide.z = ye.z * (-1) * sinf(angle);
	upguide = ft_vector_normalize(upguide);
	val->radian = tanf(val->camera[val->ca].fov * (3.14159f / 180) / 2);
	val->camera[val->ca].aspect = (float)val->width / (float)val->height;
	val->ray.direction = ft_camera_dir(val, upguide);
	val->ray.start = val->camera[val->ca].origin;
	val->green = 0;
	val->blue = 0;
	val->red = 0;
	val->level = 0;
	val->coef = 1.0f;
	val->reflect = 1.0f;
	val->mark = 0;
}
