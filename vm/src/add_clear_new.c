/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_clear_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:30:21 by iburel            #+#    #+#             */
/*   Updated: 2018/02/18 18:19:02 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		add_clear_new(t_proc **procs, t_int32 pc)
{
	t_proc	*p;
	int		pos;

	if (!(p = malloc(sizeof(*p))))
	{
		ft_dprintf(2, "error malloc in add_clear_new.c\n");
		exit(2);
	}
	p->op = 17;
	p->pc = pc;
	pos = (g_nb_cycle + 50) % NB_CYCLE_MAX;
	p->next = procs[pos];
	procs[pos] = p;
}
