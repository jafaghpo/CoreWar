/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:10:50 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/16 18:20:32 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			add_instruction(t_inst *inst)
{
	int		i;

	if (g_bin.i + inst->size > g_bin.size)
	{
		g_bin.size += BUFF_SIZE;
		if (!(g_bin.data = realloc(g_bin.data, g_bin.size)))
			return (print_error(strerror(errno)));
	}
	ft_memcpy(g_bin.data + g_bin.i, inst->data, inst->size);
	g_bin.i += inst->size;
	return (1);
}
