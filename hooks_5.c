/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:50:45 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 17:50:48 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	move_square_3(t_values *val, int i)
{
	while (i-- > 0)
	{
		val->square[i].normal.x < -1.0f ? val->square[i].normal.x = -1 : 0;
		val->square[i].normal.x > 1.0f ? val->square[i].normal.x = 1 : 0;
		val->square[i].normal.y < -1.0f ? val->square[i].normal.y = -1 : 0;
		val->square[i].normal.y > 1.0f ? val->square[i].normal.y = 1 : 0;
		val->square[i].normal.z < -1.0f ? val->square[i].normal.z = -1 : 0;
		val->square[i].normal.z > 1.0f ? val->square[i].normal.z = 1 : 0;
		val->square[i].size < 0 ? val->square[i].size = 0 : 0;
	}
}

void	move_light(int keycode, t_values *val, int i)
{
	if (keycode == 32)
		while (i-- > 0)
			val->light[i].position.z += 4;
	else if (keycode == 38)
		while (i-- > 0)
			val->light[i].position.z -= 4;
	else if (keycode == 4)
		while (i-- > 0)
			val->light[i].position.x -= 4;
	else if (keycode == 40)
		while (i-- > 0)
			val->light[i].position.x += 4;
	else if (keycode == 34)
		while (i-- > 0)
			val->light[i].position.y += 4;
	else if (keycode == 16)
		while (i-- > 0)
			val->light[i].position.y -= 4;
}

void	move_plane_2(int keycode, t_values *val, int i)
{
	if (keycode == 124)
		while (i-- > 0)
			val->plane[i].normal.x += 0.1;
	else if (keycode == 126)
		while (i-- > 0)
			val->plane[i].normal.y += 0.1;
	else if (keycode == 125)
		while (i-- > 0)
			val->plane[i].normal.y -= 0.1;
	else if (keycode == 7)
		while (i-- > 0)
			val->plane[i].normal.z += 0.1;
	else if (keycode == 6)
		while (i-- > 0)
			val->plane[i].normal.z -= 0.1;
	i = val->pl_count;
	while (i-- > 0)
	{
		val->plane[i].normal.x < -1.0f ? val->plane[i].normal.x = -1 : 0;
		val->plane[i].normal.x > 1.0f ? val->plane[i].normal.x = 1 : 0;
		val->plane[i].normal.y < -1.0f ? val->plane[i].normal.y = -1 : 0;
		val->plane[i].normal.y > 1.0f ? val->plane[i].normal.y = 1 : 0;
		val->plane[i].normal.z < -1.0f ? val->plane[i].normal.z = -1 : 0;
		val->plane[i].normal.z > 1.0f ? val->plane[i].normal.z = 1 : 0;
	}
}

void	move_plane(int keycode, t_values *val, int i)
{
	if (keycode == 32)
		while (i-- > 0)
			val->plane[i].plane_point.z += 4;
	else if (keycode == 38)
		while (i-- > 0)
			val->plane[i].plane_point.z -= 4;
	else if (keycode == 4)
		while (i-- > 0)
			val->plane[i].plane_point.x -= 4;
	else if (keycode == 40)
		while (i-- > 0)
			val->plane[i].plane_point.x += 4;
	else if (keycode == 34)
		while (i-- > 0)
			val->plane[i].plane_point.y += 4;
	else if (keycode == 16)
		while (i-- > 0)
			val->plane[i].plane_point.y -= 4;
	else if (keycode == 123)
		while (i-- > 0)
			val->plane[i].normal.x -= 0.1;
	move_plane_2(keycode, val, i);
}

void	choose_obj(int keycode, t_values *val)
{
	if (keycode == 18)
		val->your_obj = 1;
	else if (keycode == 19)
		val->your_obj = 2;
	else if (keycode == 20)
		val->your_obj = 3;
	else if (keycode == 21)
		val->your_obj = 4;
	else if (keycode == 23)
		val->your_obj = 5;
	else if (keycode == 22)
		val->your_obj = 6;
	printf("object %d has been chosen\n", val->your_obj);
}
