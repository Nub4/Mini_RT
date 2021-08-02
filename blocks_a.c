/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocks_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:04:47 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:16:08 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	ft_a(char *str, t_values *val)
{
	str++;
	str = ft_secondvalue_block_a(str, val);
	str = ft_fourth_block_a(str, val);
	if (*str != '\n' && *str != '\0')
		ft_malloc_error(val, 6);
	val->a_count++;
}

char	*ft_secondvalue_block_a(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_7(str, val);
	val->ambient.brightness = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	return (str);
}

char	*ft_fourth_block_a(char *str, t_values *val)
{
	if (*str != ' ')
		ft_malloc_error(val, 6);
	str = ft_magic_3(str, val);
	val->ambient.color.red = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_4(str, val);
	val->ambient.color.green = ft_atof(ft_strndup_2(str, val), val);
	str = ft_magic_4(str, val);
	val->ambient.color.blue = ft_atof(ft_strndup_2(str, val), val);
	free(val->str);
	while (*str <= '9' && *str >= '0')
		str++;
	return (str);
}
