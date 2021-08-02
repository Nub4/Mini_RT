/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:18:27 by minummin          #+#    #+#             */
/*   Updated: 2021/03/04 20:53:55 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

unsigned char	*ft_fileheader(t_values *val, int stride)
{
	int file_size;
	int i;

	file_size = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * val->height);
	if (!(val->file_header = (unsigned char *)malloc(sizeof(unsigned char) *
					FILE_HEADER_SIZE)))
		ft_bmp_error(val);
	i = 0;
	while (i < FILE_HEADER_SIZE)
	{
		val->file_header[i] = 0;
		i++;
	}
	val->file_header[0] = (unsigned char)('B');
	val->file_header[1] = (unsigned char)('M');
	val->file_header[2] = (unsigned char)(file_size);
	val->file_header[3] = (unsigned char)(file_size >> 8);
	val->file_header[4] = (unsigned char)(file_size >> 16);
	val->file_header[5] = (unsigned char)(file_size >> 24);
	val->file_header[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);
	return (val->file_header);
}

unsigned char	*ft_infoheader(t_values *val)
{
	int i;

	if (!(val->info_header = (unsigned char *)malloc(sizeof(unsigned char) *
					INFO_HEADER_SIZE)))
		ft_bmp_error(val);
	i = 0;
	while (i < INFO_HEADER_SIZE)
	{
		val->info_header[i] = 0;
		i++;
	}
	val->info_header[0] = (unsigned char)(INFO_HEADER_SIZE);
	val->info_header[4] = (unsigned char)(val->width);
	val->info_header[5] = (unsigned char)(val->width >> 8);
	val->info_header[6] = (unsigned char)(val->width >> 16);
	val->info_header[7] = (unsigned char)(val->width >> 24);
	val->info_header[8] = (unsigned char)(val->height);
	val->info_header[9] = (unsigned char)(val->height >> 8);
	val->info_header[10] = (unsigned char)(val->height >> 16);
	val->info_header[11] = (unsigned char)(val->height >> 24);
	val->info_header[12] = (unsigned char)(1);
	val->info_header[14] = (unsigned char)(3 * 8);
	return (val->info_header);
}

void			ft_bmp_values(t_values *val)
{
	val->argc_value++;
	free(val->file_header);
	free(val->info_header);
	close(val->fd);
}

void			ft_generate_bmp_image(t_values *val)
{
	unsigned char	padding[3];
	int				i;

	val->w_i_b = val->width * BYTES_PER_PIXEL;
	padding[0] = 0;
	padding[1] = 0;
	padding[2] = 0;
	val->padding_size = (4 - val->w_i_b % 4) % 4;
	val->stride = val->w_i_b + val->padding_size;
	if ((val->fd = open("bmi.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		ft_bmp_error(val);
	if (write(val->fd, ft_fileheader(val, val->stride), FILE_HEADER_SIZE) == -1)
		ft_bmp_error(val);
	if (write(val->fd, ft_infoheader(val), INFO_HEADER_SIZE) == -1)
		ft_bmp_error(val);
	i = val->height;
	while (i > 0)
	{
		i -= 1;
		if (write(val->fd, val->img + (i * val->w_i_b), val->w_i_b) == -1)
			ft_bmp_error(val);
		if (write(val->fd, padding, val->padding_size) == -1)
			ft_bmp_error(val);
	}
	ft_bmp_values(val);
}
