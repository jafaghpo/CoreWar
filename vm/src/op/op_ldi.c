/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:18:01 by root              #+#    #+#             */
/*   Updated: 2017/11/16 17:04:06 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_ldi(t_proc *p, t_inst *args)
{
    p->reg[args[2].value - 1] = g_mem[(get_real_value(args, p) 
    + get_real_value(args + 1, p)) % MEM_SIZE];
}