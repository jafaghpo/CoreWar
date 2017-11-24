/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:29:50 by niragne           #+#    #+#             */
/*   Updated: 2017/11/21 20:01:10 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_types(t_uchar mem, t_inst *args, t_uint8 op)
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

void    get_sizes(t_uint8 op, t_inst *args)
{
    t_uint8 sizes[4] = {0, 1, 2 + 2 * !op_tab[op].size, 2};
    args[0].size = sizes[args[0].type];
    args[1].size = sizes[args[1].type];
    args[2].size = sizes[args[2].type];
    args[3].size = sizes[args[3].type];
}

void    get_values(t_uint pc, t_inst *args, t_int8 op)
{
    static t_int32      (*f[4])(t_uint32, t_inst*, t_int8, t_int8) = {get_void, get_reg, get_dir, get_ind};
    t_uint8             octal;

    octal = op_tab[(int)op].octal;
    args[0].value = f[args[0].type](pc, args, 0, octal);
    args[1].value = f[args[1].type](pc, args, 1, octal);
    args[2].value = f[args[2].type](pc, args, 2, octal);
    args[3].value = f[args[3].type](pc, args, 3, octal);
}

t_int32     get_args(t_uint32 pc, t_inst *args, t_uint8 op)
{   
    get_types(g_mem[pc + 1], args, op);
    get_sizes(g_mem[pc], args);
    if (check_type(g_mem[pc], args))
    {
        get_values(pc, args, op);
        return (args[0].size + args[1].size + args[2].size + args[3].size);
    }
    return (-(args[0].size + args[1].size + args[2].size + args[3].size));
}
