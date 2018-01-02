/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:03:53 by niragne           #+#    #+#             */
/*   Updated: 2018/01/02 16:42:44 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_uint32    g_pause = 1;
t_uint32    g_key = 0;

void    *keyhook(void *av)
{
    t_uint8 *keys;
    (void)av;
    (void)keys;
    while (1)
    {
        while (!g_key)
            ;
        if (g_key == SDLK_SPACE)
           g_pause = !g_pause;
        g_key = 0;
    }
    return (NULL);
}