/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:03:45 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/15 17:59:05 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			fill_binary(char *name)
{
	int		fd;

	if ((fd = open(name, O_TRUNC | O_CREAT | O_WRONLY, 0644)) == -1)
		return (print_error(UNKNOWN_FILE, name, strerror(errno)));
	g_bin.data[PROG_NAME_LENGTH + 8] = (t_uint8)((g_bin.i - HEADER_LEN) >> 24);
	g_bin.data[PROG_NAME_LENGTH + 9] = (t_uint8)((g_bin.i - HEADER_LEN) >> 16);
	g_bin.data[PROG_NAME_LENGTH + 10] = (t_uint8)((g_bin.i - HEADER_LEN) >> 8);
	g_bin.data[PROG_NAME_LENGTH + 11] = (t_uint8)((g_bin.i - HEADER_LEN) >> 0);
	write(fd, g_bin.data, g_bin.i);
	free(g_bin.data);
	close(fd);
	return (1);
}
