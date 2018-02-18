/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:24:54 by niragne           #+#    #+#             */
/*   Updated: 2018/02/18 18:19:36 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_uint32 g_id;

void			init_gid(t_uint32 id)
{
	g_id = id;
}

t_proc			*create_proc(t_proc *p, t_int32 pc)
{
	t_proc		*ret;
	int			i;

	if (!(ret = malloc(sizeof(*ret))))
	{
		ft_dprintf(2, "error malloc in create_proc.c\n");
		exit(1);
	}
	ret->pc = pc;
	ret->op = 0;
	ret->carry = p->carry;
	ret->player = p->player;
	ret->live = p->live;
	i = 0;
	while (i < REG_NUMBER)
	{
		ret->reg[i] = p->reg[i];
		i++;
	}
	ret->next = NULL;
	g_nb_process++;
	g_id++;
	ret->id = g_id;
	return (ret);
}
