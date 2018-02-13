/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:17:41 by root              #+#    #+#             */
/*   Updated: 2018/02/13 14:38:43 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_zjmp(t_proc *p, t_inst *args)
{
	if (p->carry == 1)
	{
		g_infos[p->pc].cursor = 0;
		p->pc += args[0].value % IDX_MOD;
		g_infos[p->pc % MEM_SIZE + MEM_SIZE * (p->pc > INT_MAX / 2)].cursor = 1;
		p->pc -= 3;
	}
}
