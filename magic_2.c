/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:25:47 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:22:04 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

char	*ft_magic_4(char *str, t_values *val)
{
	free(val->str);
	while (*str <= '9' && *str >= '0')
		str++;
	if (*str != ',')
		ft_malloc_error(val, 6);
	str++;
	return (str);
}

char	*ft_magic_6(char *str, t_values *val)
{
	free(val->str);
	if (*str == '-' || *str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	while (*str == '.' || (*str <= '9' && *str >= '0'))
		str++;
	if (*str != ',')
		ft_malloc_error(val, 6);
	str++;
	return (str);
}
