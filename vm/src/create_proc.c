/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:24:54 by niragne           #+#    #+#             */
/*   Updated: 2017/11/24 17:44:00 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc      *create_proc(t_proc *p, t_int32 pc, t_int32 nb_cycle)
{
    t_proc *ret;
    
    if (!(ret = malloc(sizeof(*ret))))
        ft_afferror("error_malloc");
    ret->pc = pc;
    ret->carry = p->carry;
    ret->player = p->player;
    ret->live = nb_cycle;
    ft_memcpy(ret->reg, p->reg, REG_NUMBER);
    ret->carry = p->carry;
    ret->next = NULL;
    return (ret);
}
