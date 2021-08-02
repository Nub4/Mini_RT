/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minummin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:36:22 by minummin          #+#    #+#             */
/*   Updated: 2021/02/15 19:20:17 by minummin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int		ft_strchr(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_get_line(t_values *val)
{
	char	*str;
	int		len;

	len = 0;
	if (!val->s)
		return (NULL);
	while (val->s[len] && val->s[len] != '\n')
		len++;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
		str[len] = val->s[len];
	return (str);
}

char	*ft_get_rest(t_values *val)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (val->s[i] && val->s[i] != '\n')
		i++;
	if (!val->s[i])
	{
		if (val->s)
			free(val->s);
		return (NULL);
	}
	if (!(str = malloc(sizeof(char) * ((ft_strlen(val->s) - i) + 1))))
		return (NULL);
	i++;
	while (val->s[i])
		str[j++] = val->s[i++];
	str[j] = '\0';
	if (val->s)
		free(val->s);
	return (str);
}

int		get_next_line(int fd, char **line, t_values *val)
{
	char		buff[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	ret = 1;
	while (ret > 0 && !ft_strchr(val->s))
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			if (val->s)
				free(val->s);
			return (-1);
		}
		buff[ret] = '\0';
		if ((val->s = ft_strjoin(val, buff)) == NULL)
			return (-1);
	}
	*line = ft_get_line(val);
	val->s = ft_get_rest(val);
	if (ret == 0)
		return (0);
	return (1);
}
