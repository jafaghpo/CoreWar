/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:17:36 by niragne           #+#    #+#             */
/*   Updated: 2017/10/25 12:01:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc		*add_proc(t_proc *proc, t_uint32 id, t_uint32 pc)
{
	t_proc		*new;

	if (!(new = malloc(sizeof(*new))))
		ft_afferror(ERROR_MALLOC);
	new->pc = pc;
	new->carry = proc->carry;
	ft_memcpy(new->reg, proc->reg, REG_NUMBER * 4);
	new->player = proc->player;
	new->live = 0;
	new->id = id;
	if (!proc)
	{
		new->next = NULL;
		return (new);
	}
	new->next = proc;
	return (new);
}
