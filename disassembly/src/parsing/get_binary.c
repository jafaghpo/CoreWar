/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 17:19:59 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 14:27:10 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

static int		check_prog_size(void)
{
	int			size;
	int			real_size;

	size = 0;
	size |= g_bin.data[PROG_NAME_LENGTH + 8] << 24;
	size |= g_bin.data[PROG_NAME_LENGTH + 9] << 16;
	size |= g_bin.data[PROG_NAME_LENGTH + 10] << 8;
	size |= g_bin.data[PROG_NAME_LENGTH + 11] << 0;
	real_size = g_bin.size - (PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
	if (size != real_size)
		return (print_error(PROG_SIZE, size, real_size));
	return (1);
}

static int		check_magic_number(void)
{
	int			magic;

	magic = 0;
	magic |= g_bin.data[0] << 24;
	magic |= g_bin.data[1] << 16;
	magic |= g_bin.data[2] << 8;
	magic |= g_bin.data[3] << 0;
	g_bin.i += MAGIC_LEN;
	if (magic != COREWAR_EXEC_MAGIC)
		return (print_error(MAGIC_NUMBER, magic, COREWAR_EXEC_MAGIC));
	return (1);
}

int				get_binary(char *path)
{
	t_uint8		tmp[BUFF_SIZE + 1];
	int			fd;

	if (!(g_option & VISUAL_FLAG))
		ft_printf(COMPILATION_START, path);
	else
		ft_bzero((void*)g_error, ERROR_LEN);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (print_error(strerror(errno)));
	if ((g_bin.size = read(fd, tmp, BUFF_SIZE)) < 0)
		return (print_error(strerror(errno)));
	if (g_bin.size == BUFF_SIZE)
		return ((print_error(BINARY_SIZE, g_bin.size)));
	if (!g_bin.size)
		return (print_error(EMPTY_FILE));
	if (!(g_bin.data = malloc(sizeof(*g_bin.data) * (g_bin.size + 1))))
		return (print_error(strerror(errno)));
	tmp[g_bin.size] = 0;
	ft_memcpy(g_bin.data, tmp, g_bin.size);
	close(fd);
	if (!check_magic_number() || !check_prog_size())
		return (0);
	return (1);
}
