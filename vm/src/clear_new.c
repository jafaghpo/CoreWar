/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:41:46 by iburel            #+#    #+#             */
/*   Updated: 2018/01/26 01:13:28 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    clear_new(t_proc *p)
{
    g_infos[(p->pc + 0) % MEM_SIZE].new = 0;
    g_infos[(p->pc + 1) % MEM_SIZE].new = 0;
    g_infos[(p->pc + 2) % MEM_SIZE].new = 0;
    g_infos[(p->pc + 3) % MEM_SIZE].new = 0;
}