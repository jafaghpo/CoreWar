/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:03:45 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/13 18:02:09 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				fill_binary(char *name)
{
	int		fd;

	if ((fd = open(name, O_TRUNC | O_CREAT | O_WRONLY, 0644)) == -1)
		return (print_error(UNKNOWN_FILE, name, strerror(errno)));
	g_bin.data[NAME_LEN + 8] = (t_uint8)((g_bin.i - HEADER_LEN) >> 24);
	g_bin.data[NAME_LEN + 9] = (t_uint8)((g_bin.i - HEADER_LEN) >> 16);
	g_bin.data[NAME_LEN + 10] = (t_uint8)((g_bin.i - HEADER_LEN) >> 8);
	g_bin.data[NAME_LEN + 11] = (t_uint8)((g_bin.i - HEADER_LEN) >> 0);
	write(fd, g_bin.data, g_bin.i);
	if ((g_option & SIZE_FLAG) && !(g_option & VISUAL_FLAG))
	{
		ft_printf(PROG_SIZE_MSG, g_bin.i - HEADER_LEN);
		if (g_bin.i - HEADER_LEN > CHAMP_MAX_SIZE)
			ft_printf(PROG_SIZE_WARNING, MAG, RES, CHAMP_MAX_SIZE);
	}
	close(fd);
	if (!(g_option & VISUAL_FLAG))
		ft_printf(COMPILATION_END, name);
	return (1);
}
