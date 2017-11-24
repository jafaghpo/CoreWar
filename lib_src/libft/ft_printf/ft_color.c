/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:23:42 by iburel            #+#    #+#             */
/*   Updated: 2017/04/05 17:02:02 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_end(char **str, int fd, int test)
{
	if (test)
	{
		while (**str != '}')
			(*str)++;
		return (0);
	}
	else
	{
		(*str)--;
		ft_buf(fd, "{", 1);
	}
	return (1);
}

int			ft_color(char **str, int fd)
{
	int		i;

	i = 0;
	(*str)++;
	if (!ft_strncmp(*str, "black}", 6))
		i = ft_buf(fd, BLK, 6);
	else if (!ft_strncmp(*str, "red}", 4))
		i = ft_buf(fd, RED, 6);
	else if (!ft_strncmp(*str, "green}", 6))
		i = ft_buf(fd, GRN, 6);
	else if (!ft_strncmp(*str, "yellow}", 7))
		i = ft_buf(fd, YEL, 6);
	else if (!ft_strncmp(*str, "blue}", 5))
		i = ft_buf(fd, BLU, 6);
	else if (!ft_strncmp(*str, "magenta}", 8))
		i = ft_buf(fd, MAG, 6);
	else if (!ft_strncmp(*str, "cyan}", 5))
		i = ft_buf(fd, CYN, 6);
	else if (!ft_strncmp(*str, "white}", 6))
		i = ft_buf(fd, WHT, 6);
	else if (!ft_strncmp(*str, "eoc}", 4))
		i = ft_buf(fd, RES, 5);
	return (ft_end(str, fd, i));
}
