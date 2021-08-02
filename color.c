/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:57:28 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:19:03 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	my_mlx_pixel_put(t_values *val, int x, int y, int color)
{
	char *dst;

	dst = val->addr + (y * val->line_length + x * (val->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_color(t_values *val)
{
	val->green = val->green * 255.0f;
	val->blue = val->blue * 255.0f;
	val->red = val->red * 255.0f;
	if (val->mark == 1)
	{
		val->green += (val->ambient.brightness * val->ambient.color.green);
		if (val->green > 255.0f)
			val->green = 255.0f;
		val->blue += (val->ambient.brightness * val->ambient.color.blue);
		if (val->blue > 255.0f)
			val->blue = 255.0f;
		val->red += (val->ambient.brightness * val->ambient.color.red);
		if (val->red > 255.0f)
			val->red = 255.0f;
	}
	val->red = (int)val->red;
	val->blue = (int)val->blue;
	val->green = (int)val->green;
	val->img[(val->x + val->y * val->width) * 3 + 2] = (unsigned char)val->red;
	val->img[(val->x + val->y * val->width) * 3 + 1] =
		(unsigned char)val->green;
	val->img[(val->x + val->y * val->width) * 3 + 0] = (unsigned char)val->blue;
	val->red = val->red * 65536 + val->green * 256 + val->blue;
	my_mlx_pixel_put(val, val->x, val->y, val->red);
}
