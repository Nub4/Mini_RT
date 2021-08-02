/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:37:58 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 17:38:03 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	move_square_2(int keycode, t_values *val, int i)
{
	if (keycode == 123)
		while (i-- > 0)
			val->square[i].normal.x -= 0.1;
	else if (keycode == 124)
		while (i-- > 0)
			val->square[i].normal.x += 0.1;
	else if (keycode == 126)
		while (i-- > 0)
			val->square[i].normal.y += 0.1;
	else if (keycode == 125)
		while (i-- > 0)
			val->square[i].normal.y -= 0.1;
	else if (keycode == 7)
		while (i-- > 0)
			val->square[i].normal.z += 0.1;
	else if (keycode == 6)
		while (i-- > 0)
			val->square[i].normal.z -= 0.1;
	move_square_3(val, val->sq_count);
}

void	move_square(int keycode, t_values *val, int i)
{
	if (keycode == 32)
		while (i-- > 0)
			val->square[i].center.z += 4;
	else if (keycode == 38)
		while (i-- > 0)
			val->square[i].center.z -= 4;
	else if (keycode == 4)
		while (i-- > 0)
			val->square[i].center.x -= 4;
	else if (keycode == 40)
		while (i-- > 0)
			val->square[i].center.x += 4;
	else if (keycode == 34)
		while (i-- > 0)
			val->square[i].center.y += 4;
	else if (keycode == 16)
		while (i-- > 0)
			val->square[i].center.y -= 4;
	else if (keycode == 11)
		while (i-- > 0)
			val->square[i].size -= 4;
	else if (keycode == 45)
		while (i-- > 0)
			val->square[i].size += 4;
	move_square_2(keycode, val, i);
}

void	move_cylinder(int keycode, t_values *val, int i)
{
	if (keycode == 32)
		while (i-- > 0)
			val->cylinder[i].point.z += 4;
	else if (keycode == 38)
		while (i-- > 0)
			val->cylinder[i].point.z -= 4;
	else if (keycode == 4)
		while (i-- > 0)
			val->cylinder[i].point.x -= 4;
	else if (keycode == 40)
		while (i-- > 0)
			val->cylinder[i].point.x += 4;
	else if (keycode == 34)
		while (i-- > 0)
			val->cylinder[i].point.y += 4;
	else if (keycode == 16)
		while (i-- > 0)
			val->cylinder[i].point.y -= 4;
	else if (keycode == 11)
		while (i-- > 0)
			val->cylinder[i].height -= 4;
	move_cylinder_2(keycode, val, i);
}

void	move_cylinder_3(int keycode, t_values *val, int i)
{
	if (keycode == 6)
		while (i-- > 0)
			val->cylinder[i].normal.z -= 0.1;
	i = val->cy_count;
	while (i-- > 0)
	{
		val->cylinder[i].normal.x < -1.0f ? val->cylinder[i].normal.x = -1 : 0;
		val->cylinder[i].normal.x > 1.0f ? val->cylinder[i].normal.x = 1 : 0;
		val->cylinder[i].normal.y < -1.0f ? val->cylinder[i].normal.y = -1 : 0;
		val->cylinder[i].normal.y > 1.0f ? val->cylinder[i].normal.y = 1 : 0;
		val->cylinder[i].normal.z < -1.0f ? val->cylinder[i].normal.z = -1 : 0;
		val->cylinder[i].normal.z > 1.0f ? val->cylinder[i].normal.z = 1 : 0;
		val->cylinder[i].diameter < 0 ? val->cylinder[i].diameter = 0 : 0;
		val->cylinder[i].height < 0 ? val->cylinder[i].height = 0 : 0;
	}
}

void	move_cylinder_2(int keycode, t_values *val, int i)
{
	if (keycode == 45)
		while (i-- > 0)
			val->cylinder[i].height += 4;
	else if (keycode == 47)
		while (i-- > 0)
			val->cylinder[i].diameter += 4;
	else if (keycode == 43)
		while (i-- > 0)
			val->cylinder[i].diameter -= 4;
	else if (keycode == 123)
		while (i-- > 0)
			val->cylinder[i].normal.x -= 0.1;
	else if (keycode == 124)
		while (i-- > 0)
			val->cylinder[i].normal.x += 0.1;
	else if (keycode == 126)
		while (i-- > 0)
			val->cylinder[i].normal.y += 0.1;
	else if (keycode == 125)
		while (i-- > 0)
			val->cylinder[i].normal.y -= 0.1;
	else if (keycode == 7)
		while (i-- > 0)
			val->cylinder[i].normal.z += 0.1;
	move_cylinder_3(keycode, val, i);
}
