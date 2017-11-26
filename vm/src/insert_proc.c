/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:11:25 by mpinson           #+#    #+#             */
/*   Updated: 2017/11/26 16:14:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    insert_proc(t_proc **cycle, t_proc *proc, t_uint32 pos)
{
    proc->next = cycle[pos];
    cycle[pos] = proc;
}