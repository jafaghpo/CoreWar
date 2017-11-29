/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:24:54 by niragne           #+#    #+#             */
/*   Updated: 2017/11/29 15:29:20 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc      *create_proc(t_proc *p, t_int32 pc, t_int32 nb_cycle)
{
    t_proc          *ret;
    int             i;
    
    if (!(ret = malloc(sizeof(*ret))))
        ft_afferror(ERROR_MALLOC);
    ret->pc = pc;
    ret->carry = p->carry;
    ret->player = p->player;
    ret->live = nb_cycle;
    i = 0;
    while (i < REG_NUMBER)
    {
        ret->reg[i] = p->reg[i];
        i++;
    }
    ret->next = NULL;
    ret->id = g_id;
    g_id++;
    return (ret);
}
