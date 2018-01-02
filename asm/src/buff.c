/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:22:49 by niragne           #+#    #+#             */
/*   Updated: 2017/12/03 18:30:20 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>

static t_buf g_buf = {0, BUFF_SIZE, COMMENT_LENGTH + PROG_NAME_LENGTH + 16};

void		buff(char *str, int len)
{
	if (g_buf.i + len > g_buf.size)
	{
		g_buf.size += BUFF_SIZE;
		if (!(g_buf.buf = realloc(g_buf.buf, g_buf.size)))
			ft_afferror(ERROR_MALLOC);
	}
	ft_memcpy(g_buf.buf + g_buf.i, str, len);
	g_buf.i += len;
}

void		buff_atcursor(int addr, int i, int len)
{
	if (len == 1)
	{
		g_buf.buf[i + 0] = (t_uchar)(addr >> 8);
		g_buf.buf[i + 1] = (t_uchar)(addr >> 0);
	}
	else
	{
		g_buf.buf[i + 0] = (t_uchar)(addr >> 24);
		g_buf.buf[i + 1] = (t_uchar)(addr >> 16);
		g_buf.buf[i + 2] = (t_uchar)(addr >> 8);
		g_buf.buf[i + 3] = (t_uchar)(addr >> 0);
	}
}

void		buff_header(header_t *header, int name_len, int comment_len)
{
	g_buf.buf[0] = (t_uchar)(COREWAR_EXEC_MAGIC >> 24);
	g_buf.buf[1] = (t_uchar)(COREWAR_EXEC_MAGIC >> 16);
	g_buf.buf[2] = (t_uchar)(COREWAR_EXEC_MAGIC >> 8);
	g_buf.buf[3] = (t_uchar)(COREWAR_EXEC_MAGIC >> 0);
	ft_memcpy(g_buf.buf + 4, header->prog_name, name_len);
	g_buf.buf[PROG_NAME_LENGTH + 8] = (t_uchar)(header->prog_size >> 24);
	g_buf.buf[PROG_NAME_LENGTH + 9] = (t_uchar)(header->prog_size >> 16);
	g_buf.buf[PROG_NAME_LENGTH + 10] = (t_uchar)(header->prog_size >> 8);
	g_buf.buf[PROG_NAME_LENGTH + 11] = (t_uchar)(header->prog_size >> 0);
	ft_memcpy(g_buf.buf + PROG_NAME_LENGTH + 12, header->comment, comment_len);
}

void		buff_init(void)
{
	g_buf.size = BUFF_SIZE;
	if (!(g_buf.buf = malloc(sizeof(*g_buf.buf) * g_buf.size)))
		ft_afferror(ERROR_MALLOC);
	ft_bzero(g_buf.buf, COMMENT_LENGTH + PROG_NAME_LENGTH + 16);
	g_buf.i = COMMENT_LENGTH + PROG_NAME_LENGTH + 16;
}

int			buff_getcursor(void)
{
	return (g_buf.i);
}

void		buff_put(int fd)
{
	write(fd, g_buf.buf, g_buf.i);
	free(g_buf.buf);
}
