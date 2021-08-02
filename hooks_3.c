/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:02:22 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 18:03:32 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	move_sphere_2(t_values *val, int i)
{
	while (i-- > 0)
		val->sphere[i].radius < 0 ? val->sphere[i].radius = 0 : 0;
}

void	move_sphere(int keycode, t_values *val, int i)
{
	if (keycode == 32)
		while (i-- > 0)
			val->sphere[i].position.z += 4;
	else if (keycode == 38)
		while (i-- > 0)
			val->sphere[i].position.z -= 4;
	else if (keycode == 4)
		while (i-- > 0)
			val->sphere[i].position.x -= 4;
	else if (keycode == 40)
		while (i-- > 0)
			val->sphere[i].position.x += 4;
	else if (keycode == 34)
		while (i-- > 0)
			val->sphere[i].position.y += 4;
	else if (keycode == 16)
		while (i-- > 0)
			val->sphere[i].position.y -= 4;
	else if (keycode == 11)
		while (i-- > 0)
			val->sphere[i].radius -= 4;
	else if (keycode == 45)
		while (i-- > 0)
			val->sphere[i].radius += 4;
	move_sphere_2(val, val->sp_count);
}

void	move_triangle_2(int keycode, t_values *val, int i)
{
	if (keycode == 4)
	{
		while (i-- > 0)
		{
			val->triangle[i].a.x -= 4;
			val->triangle[i].b.x -= 4;
			val->triangle[i].c.x -= 4;
		}
	}
	else if (keycode == 40)
	{
		while (i-- > 0)
		{
			val->triangle[i].a.x += 4;
			val->triangle[i].b.x += 4;
			val->triangle[i].c.x += 4;
		}
	}
}

void	move_triangle_3(int keycode, t_values *val, int i)
{
	if (keycode == 34)
	{
		while (i-- > 0)
		{
			val->triangle[i].a.y += 4;
			val->triangle[i].b.y += 4;
			val->triangle[i].c.y += 4;
		}
	}
	else if (keycode == 16)
	{
		while (i-- > 0)
		{
			val->triangle[i].a.y -= 4;
			val->triangle[i].b.y -= 4;
			val->triangle[i].c.y -= 4;
		}
	}
}

void	move_triangle(int keycode, t_values *val, int i)
{
	if (keycode == 32)
	{
		while (i-- > 0)
		{
			val->triangle[i].a.z += 4;
			val->triangle[i].b.z += 4;
			val->triangle[i].c.z += 4;
		}
	}
	else if (keycode == 38)
	{
		while (i-- > 0)
		{
			val->triangle[i].a.z -= 4;
			val->triangle[i].b.z -= 4;
			val->triangle[i].c.z -= 4;
		}
	}
	else if (keycode == 4 || keycode == 40)
		move_triangle_2(keycode, val, i);
	else if (keycode == 34 || keycode == 16)
		move_triangle_3(keycode, val, i);
}
