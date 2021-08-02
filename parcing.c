/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:57:18 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 17:34:22 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_count_objects_2(t_values *val, char *line)
{
	if (line[0] == 's' && line[1] == 'p')
		val->sp_count++;
	else if (line[0] == 's' && line[1] == 'q')
		val->sq_count++;
	else if (line[0] == 't' && line[1] == 'r')
		val->tr_count++;
	else if (line[0] == 'p' && line[1] == 'l')
		val->pl_count++;
	else if (line[0] == 'c' && line[1] == 'y')
		val->cy_count++;
	else if (line[0] == 'c' && line[1] != 'y')
		val->c_count++;
	else if (line[0] == 'l')
		val->l_count++;
}

void	ft_count_objects(t_values *val, char *str)
{
	int		ret;
	char	*line;
	int		i;

	i = 0;
	val->s = NULL;
	if ((val->fd = open(str, O_RDONLY)) == -1)
		ft_malloc_error(val, 4);
	while ((ret = get_next_line(val->fd, &line, val)) > 0)
	{
		if (ret == -1)
			ft_malloc_error(val, 5);
		if (line)
			ft_count_objects_2(val, line);
		if (line)
			free(line);
	}
	if (line)
		free(line);
	close(val->fd);
	val->fd = -1;
}

void	ft_start_checking(int argc, t_values *val, char **argv)
{
	ft_zero(val);
	val->fd = -1;
	val->img = NULL;
	if (argc > 3 || argc == 1)
		ft_malloc_error(val, 2);
	if (ft_check_scene(argv[1]) == 0)
		ft_malloc_error(val, 3);
	ft_count_objects(val, argv[1]);
	ft_malloc(val);
	val->s = NULL;
	ft_check_scene_values(val, argv[1]);
	close(val->fd);
	val->fd = -1;
	if (argc == 3)
	{
		if (ft_strcmp(argv[2]) == 0)
			ft_malloc_error(val, 1);
	}
	if (!(val->img = (unsigned char *)malloc(sizeof(unsigned char) *
					(val->width * val->height * 3))))
		ft_malloc_error(val, 0);
	ft_val_values(val, argc);
	ft_check_scene_rules(val);
	ft_check_right_values(val);
}

void	ft_check_scene_values(t_values *val, char *str)
{
	int		ret;
	char	*line;
	int		i;

	i = 0;
	if ((val->fd = open(str, O_RDONLY)) == -1)
		ft_malloc_error(val, 4);
	while ((ret = get_next_line(val->fd, &line, val)) > 0)
	{
		if (ret == -1)
			ft_malloc_error(val, 5);
		if (line)
		{
			if (line[0] == 'R' || (line[0] == 's' && line[1] == 'p') ||
					(line[0] == 'c' && line[1] != 'y') || (line[0] == 'p'
					&& line[1] == 'l') || line[0] == 'l' || line[0] == 'A'
					|| (line[0] == 'c' && line[1] == 'y') || (line[0] == 's'
					&& line[1] == 'q') || (line[0] == 't' && line[1] == 'r'))
				ft_check_lines(line, val);
			else if (line[0] != '\0')
                        	ft_malloc_error(val, 6);
		}
		if (line)
			free(line);
	}
	if (val->a_count > 1 || val->r_count > 1)
		ft_malloc_error(val, 6);
	if (line)
		free(line);
}

void	ft_check_lines(char *str, t_values *val)
{
	if (*str == 'R')
		ft_identifier(str, val);
	else if (str[0] == 's' && str[1] == 'p')
		ft_sp(str, val);
	else if (str[0] == 'c' && str[1] != 'y')
		ft_c(str, val);
	else if (str[0] == 'p' && str[1] == 'l')
		ft_pl(str, val);
	else if (str[0] == 'l')
		ft_l(str, val);
	else if (str[0] == 'A')
		ft_a(str, val);
	else if (str[0] == 's' && str[1] == 'q')
		ft_sq(str, val);
	else if (str[0] == 't' && str[1] == 'r')
		ft_tr(str, val);
	else if (str[0] == 'c' && str[1] == 'y')
		ft_cy(str, val);
}
