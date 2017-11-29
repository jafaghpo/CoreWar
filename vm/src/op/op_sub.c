/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:16:12 by root              #+#    #+#             */
/*   Updated: 2017/11/25 12:05:11 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_sub(t_proc *p, t_inst *args)
{
    p->reg[args[2].value - 1] = get_real_value(args, p) - get_real_value(args + 1, p);
    p->carry = !p->reg[args[2].value - 1];
}