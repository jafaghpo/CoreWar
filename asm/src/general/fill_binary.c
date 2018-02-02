/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:03:45 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/02 17:27:18 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		store_prog_size(int fd)
{
	g_bin.data[PROG_NAME_LENGTH + 8] = (t_uint8)((g_bin.i - HEADER_LEN) >> 24);
	g_bin.data[PROG_NAME_LENGTH + 9] = (t_uint8)((g_bin.i - HEADER_LEN) >> 16);
	g_bin.data[PROG_NAME_LENGTH + 10] = (t_uint8)((g_bin.i - HEADER_LEN) >> 8);
	g_bin.data[PROG_NAME_LENGTH + 11] = (t_uint8)((g_bin.i - HEADER_LEN) >> 0);
	write(fd, g_bin.data, g_bin.i);
}

int				fill_binary(char *name)
{
	int		fd;

	if ((fd = open(name, O_TRUNC | O_CREAT | O_WRONLY, 0644)) == -1)
		return (print_error(UNKNOWN_FILE, name, strerror(errno)));
	store_prog_size(fd);
	if ((g_option & SIZE_FLAG) && !(g_option & VISUAL_FLAG))
	{
		ft_printf("Program size is %d bytes\n", g_bin.i - HEADER_LEN);
		if (g_bin.i - HEADER_LEN > CHAMP_MAX_SIZE)
			ft_printf(MAX_SIZE, RED, RES, CHAMP_MAX_SIZE);
	}
	ft_bzero((void*)g_bin.data, (size_t)g_bin.i);
	g_bin.i = 0;
	close(fd);
	if (!(g_option & VISUAL_FLAG))
		ft_printf("Compilation done in %s\n", name);
	return (1);
}
