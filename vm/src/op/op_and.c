/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:16:37 by root              #+#    #+#             */
/*   Updated: 2018/02/13 16:57:46 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_and(t_proc *p, t_inst *args)
{
	t_int32 a;
	t_int32 b;

	a = get_real_value(args, p, 1);
	b = get_real_value(args + 1, p, 1);
	p->reg[args[2].value - 1] = a & b;
	p->carry = !p->reg[args[2].value - 1];
}
