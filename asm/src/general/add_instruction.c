/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:10:50 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/13 01:10:28 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			add_instruction(char *inst, int len)
{
	if (g_bin.i + len > g_bin.size)
	{
		g_bin.size += BUFF_SIZE;
		g_bin.data = ft_realloc(g_bin.data, g_bin.size);
	}
	ft_memcpy(g_bin.data, inst, len);
}
