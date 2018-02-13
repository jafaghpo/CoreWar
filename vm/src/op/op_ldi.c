/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:18:01 by root              #+#    #+#             */
/*   Updated: 2018/02/13 17:00:08 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	op_ldi(t_proc *p, t_inst *args)
{
	int	add;

	add = get_real_value(args, p, 0) + get_real_value(args + 1, p, 0);
	add %= IDX_MOD;
	add += p->pc;
	add = add % MEM_SIZE + MEM_SIZE * (add < 0);
	p->reg[args[2].value - 1] = get_uint32_mem(add);
	p->carry = !p->reg[args[2].value - 1];
}
