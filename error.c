/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:49:48 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 16:52:25 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_free(t_values *val)
{
	if (val->img)
		free(val->img);
	if (val->sphere)
		free(val->sphere);
	if (val->plane)
		free(val->plane);
	if (val->square)
		free(val->square);
	if (val->camera)
		free(val->camera);
	if (val->light)
		free(val->light);
	if (val->triangle)
		free(val->triangle);
	if (val->cylinder)
		free(val->cylinder);
}

void	ft_print_errors(int a)
{
	if (a == 0)
		printf("Error\nMalloc failed\n");
	else if (a == 1)
		printf("Error\nWrong argument for saving\n");
	else if (a == 2)
		printf("Error\nWrong number of arguments\n");
	else if (a == 3)
		printf("Error\nWrong name for the scene\n");
	else if (a == 4)
		printf("Error\nOpening scene file failed\n");
	else if (a == 5)
		printf("Error\nGet_next_line failed\n");
	else if (a == 6)
		printf("Error\nScene values are wrong\n");
}

void	ft_malloc_error(t_values *val, int a)
{
	if (val->fd != -1)
		close(val->fd);
	if (val->img)
		free(val->img);
	if (val->sphere)
		free(val->sphere);
	if (val->plane)
		free(val->plane);
	if (val->camera)
		free(val->camera);
	if (val->square)
		free(val->square);
	if (val->light)
		free(val->light);
	if (val->triangle)
		free(val->triangle);
	if (val->cylinder)
		free(val->cylinder);
	ft_print_errors(a);
	exit(0);
}

void	ft_bmp_error(t_values *val)
{
	if (val->fd != -1)
		close(val->fd);
	if (val->img)
		free(val->img);
	if (val->sphere)
		free(val->sphere);
	if (val->plane)
		free(val->plane);
	if (val->camera)
		free(val->camera);
	if (val->square)
		free(val->square);
	if (val->light)
		free(val->light);
	if (val->triangle)
		free(val->triangle);
	if (val->cylinder)
		free(val->cylinder);
	if (val->file_header)
		free(val->file_header);
	printf("Error\nCreating BMP file failed\n");
	exit(0);
}

void	ft_malloc(t_values *val)
{
	if (val->sp_count != 0)
		if (!(val->sphere = malloc(sizeof(t_sphere) * (val->sp_count))))
			ft_malloc_error(val, 0);
	if (val->pl_count != 0)
		if (!(val->plane = malloc(sizeof(t_plane) * (val->pl_count))))
			ft_malloc_error(val, 0);
	if (val->sq_count != 0)
		if (!(val->square = malloc(sizeof(t_square) * (val->sq_count))))
			ft_malloc_error(val, 0);
	if (val->c_count != 0)
		if (!(val->camera = malloc(sizeof(t_camera) * (val->c_count))))
			ft_malloc_error(val, 0);
	if (val->l_count != 0)
		if (!(val->light = malloc(sizeof(t_light) * (val->l_count))))
			ft_malloc_error(val, 0);
	if (val->tr_count != 0)
		if (!(val->triangle = malloc(sizeof(t_triangle) * (val->tr_count))))
			ft_malloc_error(val, 0);
	if (val->cy_count != 0)
		if (!(val->cylinder = malloc(sizeof(t_cylinder) * (val->cy_count))))
			ft_malloc_error(val, 0);
}
