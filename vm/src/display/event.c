/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:29:58 by iburel            #+#    #+#             */
/*   Updated: 2017/11/17 16:29:59 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#define SPEED	64.f

void    event(t_mat4 *projection, t_mat4 *modelview)
{
    Uint8   *key;

    key = (Uint8 *)SDL_GetKeyboardState(NULL);
    if (key[SDL_SCANCODE_W])
        rotate(modelview, norme(1.f, 0.f, 0.f), M_PI / SPEED);
    if (key[SDL_SCANCODE_A])
        rotate(modelview, norme(0.f, 1.f, 0.f), M_PI / SPEED);
    if (key[SDL_SCANCODE_S])
        rotate(modelview, norme(-1.f, 0.f, 0.f), M_PI / SPEED);
    if (key[SDL_SCANCODE_D])
        rotate(modelview, norme(0.f, -1.f, 0.f), M_PI / SPEED);
    if (key[SDL_SCANCODE_Q])
        rotate(modelview, norme(0.f, 0.f, 1.f), M_PI / SPEED);
    if (key[SDL_SCANCODE_E])
        rotate(modelview, norme(0.f, 0.f, -1.f), M_PI / SPEED);
    if (key[SDL_SCANCODE_UP])
        translation(projection, (t_vec3){0.f, -0.03f, 0.f});
    if (key[SDL_SCANCODE_DOWN])
        translation(projection, (t_vec3){0.f, 0.03f, 0.f});
    if (key[SDL_SCANCODE_RIGHT])
        translation(projection, (t_vec3){-0.03f, 0.f, 0.f});
    if (key[SDL_SCANCODE_LEFT])
        translation(projection, (t_vec3){0.03f, 0.f, 0.f});
    if (key[SDL_SCANCODE_O])
        zoom(modelview, (t_vec3){0.95f, 0.95f, 0.95f});
    if (key[SDL_SCANCODE_P])
        zoom(modelview, (t_vec3){1.05f, 1.05f, 1.05f});
}