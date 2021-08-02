/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:58:35 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 19:53:09 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int		ft_find_intersect(t_values *val)
{
	int a;

	a = 0;
	ft_intersect(val, a);
	a = 0;
	ft_plane(val, a);
	a = 0;
	ft_square(val, a);
	a = 0;
	ft_triangle(val, a);
	a = 0;
	ft_cylinder(val, a);
	a = 0;
	ft_cylinder_2(val, a);
	a = 0;
	ft_cylinder_3(val, a);
	if (val->obj == 0 || val->obj == 1 || val->obj == 2 || val->obj == 3
	|| val->obj == 4 || val->obj == 5 || val->obj == 6)
		val->mark = 1;
	val->newstart = ft_vector_add(val->ray.start,
	ft_vector_scalar(val->ray.direction, val->t));
	return (val->obj);
}

void	ft_image_values(t_values *val)
{
	val->sq_i = 0;
	val->sp_i = 0;
	val->cy_i = 0;
	val->pl_i = 0;
	val->tr_i = 0;
	val->i = 0;
	val->t = 20000.0f;
	val->obj = -1;
}

void	ft_find_new_setup(t_values *val)
{
	val->coef = val->coef * val->reflect;
	val->ray.start = val->newstart;
	val->reflect = 2.0f * ft_vector_dot(val->ray.direction, val->n);
	val->ray.direction = ft_vector_sub(val->ray.direction,
		ft_vector_scalar(val->n, val->reflect));
}

void	ft_build_image(t_values *val, int a)
{
	val->y = 0;
	while (val->y < val->height)
	{
		val->x = 0;
		while (val->x < val->width)
		{
			ft_ray_values(val);
			while (val->coef > 0 && val->level < 1)
			{
				ft_image_values(val);
				if (ft_find_intersect(val) == -1)
					break ;
				ft_find_intersect_normal(val);
				ft_find_light_value(val, a);
				ft_find_new_setup(val);
				val->level++;
			}
			ft_color(val);
			val->x++;
		}
		val->y++;
	}
	if (val->argc_value == 3)
		ft_generate_bmp_image(val);
	mlx_put_image_to_window(val->mlx, val->win, val->image, 0, 0);
}
