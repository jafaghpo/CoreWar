/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:22:49 by niragne           #+#    #+#             */
/*   Updated: 2017/09/20 17:54:13 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"
#include <stdlib.h>

static t_buf g_buf = {0, BUFF_SIZE, 0};

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

void		buff_init(void)
{
	g_buf.size = BUFF_SIZE;
	if (!(g_buf.buf = malloc(sizeof(*g_buf.buf) * g_buf.size)))
		ft_afferror(ERROR_MALLOC);
	g_buf.i = 0;
}

void		buff_put(int fd)
{
	write(fd, g_buf.buf, g_buf.i);
	free(g_buf.buf);
}
