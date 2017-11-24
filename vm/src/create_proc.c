/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:24:54 by niragne           #+#    #+#             */
/*   Updated: 2017/11/16 15:02:30 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc      *create_proc(t_proc *p, t_int32 pc)
{
    t_proc *ret;
    
    if (!(ret = malloc(sizeof(*ret))))
        ft_afferror("error_malloc");
    ret->pc = pc;
    ret->carry = p->carry;
    ret->player = p->player;
    ret->live = 0;
    ft_memcpy(ret->reg, p->reg, REG_NUMBER);
    ret->carry = p->carry;
    ret->next = NULL;
    return (ret);
}
