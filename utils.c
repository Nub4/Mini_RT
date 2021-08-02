/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:08:32 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:23:33 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	ft_strcmp(char *str)
{
	char	*cmp;
	int		i;

	i = 0;
	cmp = "--save";
	while (str[i] || cmp[i])
	{
		if (str[i] != cmp[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	else
		return (0);
}

int	ft_check_scene(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] != 't')
		return (0);
	i--;
	if (str[i] != 'r')
		return (0);
	i--;
	if (str[i] != '.')
		return (0);
	i--;
	if (ft_isalnum(str[i]) == 0)
		return (0);
	return (1);
}
