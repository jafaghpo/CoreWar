/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:03:53 by niragne           #+#    #+#             */
/*   Updated: 2018/01/02 18:24:17 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_uint32    g_pause = 1;
t_uint32    g_key = 0;

void    check_breakpoints()

void    *keyhook(void *av)
{
    t_uint8 *key;
    (void)av;

    key = (Uint8 *)SDL_GetKeyboardState(NULL);
    while (1)
    {
        while (!g_key)
        {
            if (key[SDL_SCANCODE_X])
                g_sleep *= 1.000001;
            if (key[SDL_SCANCODE_Z])
                g_sleep *= 0.999999;
            usleep(3);
        }
        if (g_key == SDLK_SPACE)
           g_pause = !g_pause;
        if (g_key == SDLK_c)
            g_sleep = 500;
        g_key = 0;
    }
    return (NULL);
}