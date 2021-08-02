/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:29:48 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:21:45 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

char	*ft_magic_5(char *str, t_values *val)
{
	while (*str && *str != '\n')
	{
		if (*str == '-' || (*str >= '0' && *str <= '1'))
			break ;
		if (*str != ' ')
			ft_malloc_error(val, 6);
		str++;
	}
	if (*str == '\0' || *str == '\n')
		ft_malloc_error(val, 6);
	return (str);
}

char	*ft_magic(char *str, t_values *val)
{
	while (*str && *str != '\n')
	{
		if (*str <= '9' && *str >= '1')
			break ;
		if (*str != ' ')
			ft_malloc_error(val, 6);
		str++;
	}
	if (*str == '\0' || *str == '\n')
		ft_malloc_error(val, 6);
	return (str);
}

char	*ft_magic_2(char *str, t_values *val)
{
	free(val->str);
	if ((*str <= '9' && *str >= '0') || *str == '-' || *str == '.')
		str++;
	while ((*str <= '9' && *str >= '0') || *str == '.')
		str++;
	if (*str != ',')
		ft_malloc_error(val, 6);
	return (str);
}

char	*ft_magic_3(char *str, t_values *val)
{
	while (*str && *str != '\n')
	{
		if (*str <= '9' && *str >= '0')
			break ;
		if (*str != ' ')
			ft_malloc_error(val, 6);
		str++;
	}
	if (*str == '\0' || *str == '\n')
		ft_malloc_error(val, 6);
	return (str);
}

char	*ft_magic_7(char *str, t_values *val)
{
	while (*str && *str != '\n')
	{
		if (*str <= '1' && *str >= '0')
			break ;
		if (*str != ' ')
			ft_malloc_error(val, 6);
		str++;
	}
	if (*str == '\0' || *str == '\n')
		ft_malloc_error(val, 6);
	return (str);
}
