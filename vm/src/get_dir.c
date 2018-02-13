/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:17:06 by niragne           #+#    #+#             */
/*   Updated: 2018/02/13 16:38:01 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_int32	get_dir(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal)
{
	t_uint8		i;
	t_int32		ret;

	i = 0;
	pc = (pc + 1 + octal) % MEM_SIZE;
	while (i < index)
	{
		pc = (pc + args[i].size) % MEM_SIZE;
		i++;
	}
	if (args[i].size == 4)
		ret = (t_int32)get_uint32_mem(pc);
	else
		ret = (t_int16)get_uint16(pc);
	return (ret);
}
