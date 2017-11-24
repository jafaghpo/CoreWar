/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uint32.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:44:41 by niragne           #+#    #+#             */
/*   Updated: 2017/11/23 17:20:09 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void    put_uint32(t_uint32 x, t_uint32 i)
{
    g_mem[(i + 0) % MEM_SIZE] = (x & 0xff000000) >> 24;
    g_mem[(i + 1) % MEM_SIZE] = (x & 0x00ff0000) >> 16;
    g_mem[(i + 2) % MEM_SIZE] = (x & 0x0000ff00) >> 8;
    g_mem[(i + 3) % MEM_SIZE] = (x & 0x000000ff) >> 0;
}