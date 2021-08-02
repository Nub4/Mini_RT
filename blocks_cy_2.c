/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_cy_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:04:30 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:16:54 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

char	*ft_fourth_block_cy(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_3(str, val);
	val->cylinder[val->cy_x].color.red = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_4(str, val);
	val->cylinder[val->cy_x].color.green = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_4(str, val);
	val->cylinder[val->cy_x].color.blue = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	while (*str <= '9' && *str >= '0')
		str++;
	return (str);
}
