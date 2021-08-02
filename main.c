/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:24:56 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 17:37:43 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	main(int argc, char **argv)
{
	int			a;
	t_values	val;

	a = 0;
	val.your_obj = 0;
	ft_start_checking(argc, &val, argv);
	val.mlx = mlx_init();
	val.win = mlx_new_window(val.mlx, val.width, val.height, "miniRT");
	val.image = mlx_new_image(val.mlx, val.width, val.height);
	val.addr = mlx_get_data_addr(val.image, &val.bits_per_pixel,
		&val.line_length, &val.endian);
	ft_build_image(&val, a);
	mlx_key_hook(val.win, key_hook, &val);
	mlx_hook(val.win, 2, 1L << 0, ft_close, &val);
	mlx_hook(val.win, 17, 0, exit_hook, &val);
	mlx_loop(val.mlx);
	ft_free(&val);
	return (0);
}
