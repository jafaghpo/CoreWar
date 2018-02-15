/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_buff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:47:29 by root              #+#    #+#             */
/*   Updated: 2018/02/10 15:30:27 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static char	g_buf[PF_BUFF_SIZE];
static int	g_fd = 0;
static int	g_i = 0;

void	fpf_init_buff(int in_fd)
{
	if (g_fd != 0 && g_fd != in_fd)
		fpf_putbuff();
	g_fd = in_fd;
	g_i = 0;
}

void	fpf_buff(char *str, int len)
{
	if (g_i + len > PF_BUFF_SIZE)
	{
		write(g_fd, g_buf, g_i);
		g_i = 0;
	}
	ft_memcpy(g_buf + g_i, str, len);
	g_i += len;
}

void	fpf_putbuff(void)
{
	write(g_fd, g_buf, g_i);
	g_i = 0;
}
