/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:02:27 by iburel            #+#    #+#             */
/*   Updated: 2018/01/11 12:21:07 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    move_proc(t_proc **cycle, t_proc *tmp)
{
    tmp->op = g_mem[tmp->pc];
    if (tmp->op == 0 || tmp->op > 16)
        insert_proc(cycle, tmp, (g_nb_cycle + 1) % 1001);
    else
        insert_proc(cycle, tmp, (g_nb_cycle + op_tab[tmp->op].cycles) % 1001);
}