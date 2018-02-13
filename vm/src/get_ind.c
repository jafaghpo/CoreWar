/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:17:36 by niragne           #+#    #+#             */
/*   Updated: 2018/02/13 16:38:10 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_int32	get_ind(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal)
{
	t_uint8		i;
	t_int16		ret;

	i = 0;
	pc = (t_uint32)(pc + 1 + octal) % MEM_SIZE;
	while (i < index)
	{
		pc = (t_uint32)(pc + args[i].size) % MEM_SIZE;
		i++;
	}
	ret = get_uint16(pc);
	return ((t_int16)ret);
}
