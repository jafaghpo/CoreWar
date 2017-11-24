/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:15:11 by root              #+#    #+#             */
/*   Updated: 2017/11/23 13:26:29 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_add(t_proc *p, t_inst *args)
{
    p->reg[args[2].value - 1] = p->reg[args[0].value - 1] + p->reg[args[1].value - 1];
    if (p->reg[args[2].value - 1])
        p->carry = 0;
    else
        p->carry = 1;
}