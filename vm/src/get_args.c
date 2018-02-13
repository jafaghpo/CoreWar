/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:29:50 by niragne           #+#    #+#             */
/*   Updated: 2018/02/13 16:55:40 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	get_types(t_uint8 mem, t_inst *args, t_uint8 op)
{
	if (op_tab[(int)op].octal)
	{
		args[3].type = mem & 0b11;
		args[2].type = (mem & (0b11 << 2)) >> 2;
		args[1].type = (mem & (0b11 << 4)) >> 4;
		args[0].type = (mem & (0b11 << 6)) >> 6;
	}
	else
	{
		args[0].type = op_tab[op].args[0];
		args[1].type = op_tab[op].args[1];
		args[2].type = op_tab[op].args[2];
		args[3].type = op_tab[op].args[3];
	}
}

static void	get_sizes(t_uint8 op, t_inst *args)
{
	t_uint8	sizes[4];

	sizes[0] = 0;
	sizes[1] = 1;
	sizes[2] = 2 + 2 * !op_tab[op].size;
	sizes[3] = 2;
	args[0].size = sizes[args[0].type];
	args[1].size = sizes[args[1].type];
	args[2].size = sizes[args[2].type];
	args[3].size = sizes[args[3].type];
}

static void	get_values(t_uint32 pc, t_inst *args, t_int8 op)
{
	static t_int32	(*f[4])(t_uint32, t_inst*,
		t_int8, t_int8) = {get_void, get_reg, get_dir, get_ind};
	t_uint8			octal;

	octal = op_tab[(int)op].octal;
	args[0].value = f[args[0].type](pc, args, 0, octal);
	args[1].value = f[args[1].type](pc, args, 1, octal);
	args[2].value = f[args[2].type](pc, args, 2, octal);
	args[3].value = f[args[3].type](pc, args, 3, octal);
}

t_int32		get_args(t_uint32 pc, t_inst *args, t_uint8 op)
{
	int		i;
	int		size;

	get_types(g_mem[(pc + 1) % MEM_SIZE], args, op);
	get_sizes(op, args);
	size = 0;
	if (check_type(op, args))
	{
		get_values(pc, args, op);
		i = 0;
		while (i < op_tab[op].nb_args)
		{
			size += args[i].size;
			i++;
		}
		if (check_reg(args))
			return (size);
		return (-size);
	}
	return (-size);
}
