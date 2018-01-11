/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:17:41 by root              #+#    #+#             */
/*   Updated: 2018/01/11 12:01:33 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_zjmp(t_proc *p, t_inst *args)
{
    if (p->carry == 1)
    {
        p->pc += args[0].value % IDX_MOD;
        p->pc -= 3;
    }
}