/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:14:26 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 18:02:12 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	move_objects(int keycode, t_values *val)
{
	if (val->your_obj == 1)
		move_sphere(keycode, val, val->sp_count);
	else if (val->your_obj == 2)
		move_triangle(keycode, val, val->tr_count);
	else if (val->your_obj == 3)
		move_square(keycode, val, val->sq_count);
	else if (val->your_obj == 4)
		move_cylinder(keycode, val, val->cy_count);
	else if (val->your_obj == 5)
		move_plane(keycode, val, val->pl_count);
	else if (val->your_obj == 6)
		move_light(keycode, val, val->l_count);
}

void	move_camera_3(t_values *val)
{
	val->ca > val->c_count - 1 ? val->ca = val->c_count - 1 : 0;
	val->ca < 0 ? val->ca = 0 : 0;
	val->camera[val->ca].direction.z > 1.0f ?
		val->camera[val->ca].direction.z = 1.0 : 0;
	val->camera[val->ca].direction.z < -1.0f ?
		val->camera[val->ca].direction.z = -1.0 : 0;
	val->camera[val->ca].direction.y > 1.0f ?
		val->camera[val->ca].direction.y = 1.0 : 0;
	val->camera[val->ca].direction.y < -1.0f ?
		val->camera[val->ca].direction.y = -1.0 : 0;
	val->camera[val->ca].direction.x < -1.0f ?
		val->camera[val->ca].direction.x = -1.0 : 0;
	val->camera[val->ca].direction.x > 1.0f ?
		val->camera[val->ca].direction.x = 1.0 : 0;
	val->camera[val->ca].direction.x < -1.0f ?
		val->camera[val->ca].direction.x = -1.0 : 0;
	val->camera[val->ca].direction.x > 1.0f ?
		val->camera[val->ca].direction.x = 1.0 : 0;
}

void	move_camera_2(int keycode, t_values *val)
{
	if (val->camera[val->ca].direction.z > 0)
	{
		if (keycode == 0)
			val->camera[val->ca].origin.x -= 20;
		else if (keycode == 2)
			val->camera[val->ca].origin.x += 20;
		else if (keycode == 37)
			val->camera[val->ca].direction.x -= 0.1;
		else if (keycode == 39)
			val->camera[val->ca].direction.x += 0.1;
	}
	else
	{
		if (keycode == 2)
			val->camera[val->ca].origin.x -= 20;
		else if (keycode == 0)
			val->camera[val->ca].origin.x += 20;
		else if (keycode == 39)
			val->camera[val->ca].direction.x -= 0.1;
		else if (keycode == 37)
			val->camera[val->ca].direction.x += 0.1;
	}
	move_camera_3(val);
}

void	move_camera(int keycode, t_values *val)
{
	if (keycode == 3)
		val->ca++;
	else if (keycode == 5)
		val->ca--;
	else if (keycode == 49)
		val->camera[val->ca].origin.y -= 20;
	else if (keycode == 46)
		val->camera[val->ca].origin.y += 20;
	else if (keycode == 13)
		val->camera[val->ca].origin = ft_vector_add(val->camera[val->ca].origin,
				ft_vector_scalar(val->camera[val->ca].direction, 20));
	else if (keycode == 1)
		val->camera[val->ca].origin = ft_vector_add(val->camera[val->ca].origin,
				ft_vector_scalar(val->camera[val->ca].direction, -20));
	else if (keycode == 33)
		val->camera[val->ca].direction.z += 0.1;
	else if (keycode == 31)
		val->camera[val->ca].direction.z -= 0.1;
	else if (keycode == 35)
		val->camera[val->ca].direction.y += 0.1;
	else if (keycode == 41)
		val->camera[val->ca].direction.y -= 0.1;
	move_camera_2(keycode, val);
}

int		key_hook(int keycode, t_values *val)
{
	if (keycode == 18 || keycode == 19 || keycode == 20 ||
			keycode == 21 || keycode == 23 || keycode == 22)
		choose_obj(keycode, val);
	else if (keycode == 32 || keycode == 38 || keycode == 4 || keycode == 40 ||
			keycode == 34 || keycode == 16 || keycode == 11 || keycode == 45 ||
			keycode == 6 || keycode == 7 || keycode == 123 || keycode == 124 ||
			keycode == 125 || keycode == 126 || keycode == 47 || keycode == 43)
		move_objects(keycode, val);
	else if (keycode == 3 || keycode == 5 || keycode == 49 || keycode == 46 ||
	keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2 ||
	keycode == 35 || keycode == 41 || keycode == 37 || keycode == 39 ||
	keycode == 33 || keycode == 31)
		move_camera(keycode, val);
	ft_build_image(val, 0);
	return (0);
}
