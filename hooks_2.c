/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:31:47 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:21:00 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	ft_close(int keycode, t_values *val)
{
	if (keycode == 53)
	{
		mlx_destroy_window(val->mlx, val->win);
		ft_free(val);
		exit(0);
	}
	return (0);
}

int	exit_hook(t_values *val)
{
	mlx_destroy_window(val->mlx, val->win);
	ft_free(val);
	exit(0);
}
