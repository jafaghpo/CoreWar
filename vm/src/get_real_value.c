/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:00:26 by niragne           #+#    #+#             */
/*   Updated: 2018/02/13 16:41:41 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_int32	get_void_value(t_int32 val, t_proc *p)
{
	(void)val;
	(void)p;
	return (0);
}

static t_int32	get_reg_value(t_int32 val, t_proc *p)
{
	return (p->reg[val - 1]);
}

static t_int32	get_dir_value(t_int32 dir, t_proc *p)
{
	(void)p;
	return (dir);
}

static t_int32	get_ind_value(t_int32 ind, t_proc *p, t_uint8 mod)
{
	t_int32 ret;
	t_int32 tmp;

	if (mod)
		ind %= IDX_MOD;
	tmp = p->pc + ind;
	ret = get_uint32_mem(tmp % MEM_SIZE + MEM_SIZE * (tmp < 0));
	return ((t_int32)ret);
}

t_int32			get_real_value(t_inst *args, t_proc *p, t_uint8 mod)
{
	static t_int32	(*f[4])() = {get_void_value, get_reg_value,
		get_dir_value, (t_int32 (*)())get_ind_value};

	return (f[args[0].type](args[0].value, p, mod));
}
