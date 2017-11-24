/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:11:25 by iburel            #+#    #+#             */
/*   Updated: 2017/11/16 14:31:55 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    insert_proc(t_proc **cycle, t_proc *proc, t_uint32 pos)
{
    t_proc  *tmp;

    tmp = cycle[pos];
    proc->next = cycle[pos];
    cycle[pos] = proc;
}