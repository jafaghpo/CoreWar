/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:12:19 by root              #+#    #+#             */
/*   Updated: 2017/11/29 23:09:56 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void 		op_live(t_proc *p, t_inst *args, t_uint32 nb_cycle)
{
    char    str[CHAT_LINE_SIZE];

    live(args[0].value, p->player);
    p->live = nb_cycle;
    ft_memcpy(str, "ID:", 3);
    str[3] = p->id % 10 + '0';
    ft_memcpy(str + 4, " a fait un live! WOW", 21);
    add_line_chat(str);
}