/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:11:25 by niragne           #+#    #+#             */
/*   Updated: 2017/11/29 17:10:36 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    insert_proc(t_proc **cycle, t_proc *proc, t_uint32 pos)
{
    t_proc *tmp;
    t_proc *tmp2;
    
    tmp2 = cycle[pos];
    if (!tmp2)
    {
        proc->next = cycle[pos];
        cycle[pos] = proc;    
        return ;  
    }
    tmp = tmp2->next;
    while (tmp && tmp->id > proc->id)
    {
        tmp2 = tmp;
        tmp = tmp->next;
    }
    /*
    ft_printf("TMP %l#x\n", tmp);
    ft_printf("TMP 2 %l#x\n", tmp2);
    ft_printf("TMP2 NEXT %p\n", tmp2->next);
      */  
    tmp2->next = proc;  
    proc->next = tmp;
}