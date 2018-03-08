/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:19:15 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 18:22:51 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int			get_register(char *line, int size, int opcode)
{
	int		i;

	(void)opcode;
	i = ft_sprintf(line + size, "r%d", g_bin.data[g_bin.i]);
	g_bin.i += 1;
	return (i);
}

int			get_direct(char *line, int size, int opcode)
{
	int		arg;
	int		i;

	arg = 0;
	if (g_op[opcode].size)
	{
		arg |= g_bin.data[g_bin.i + 0] << 8;
		arg |= g_bin.data[g_bin.i + 1];
		g_bin.i += 2;
	}
	else
	{
		arg |= g_bin.data[g_bin.i + 0] << 24;
		arg |= g_bin.data[g_bin.i + 1] << 16;
		arg |= g_bin.data[g_bin.i + 2] << 8;
		arg |= g_bin.data[g_bin.i + 3];
		g_bin.i += 4;
	}
	i = ft_sprintf(line + size, "%%%d", arg);
	return (i);
}

int			get_indirect(char *line, int size, int opcode)
{
	int		arg;
	int		i;

	(void)opcode;
	arg = 0;
	arg |= g_bin.data[g_bin.i + 0] << 8;
	arg |= g_bin.data[g_bin.i + 1];
	g_bin.i += 2;
	i = ft_sprintf(line + size, "%d", arg);
	return (i);
}
