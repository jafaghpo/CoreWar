/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:15:15 by iburel            #+#    #+#             */
/*   Updated: 2018/01/19 21:37:05 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int     init_sdl(t_sdl *sdl)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        ft_printf(ERROR_INIT_SDL"\n");
        return (0);
    }
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);
    if (!(sdl->win = SDL_CreateWindow("corewar", SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP)))
    {
        ft_printf(ERROR_CREAT_WIN"\n");
        return (0);
    }
    if (!(sdl->glc = SDL_GL_CreateContext(sdl->win)))
    {
        ft_printf(ERROR_CREAT_CONTEXT_GL"\n");
        return (0);
    }
    SDL_GL_SetSwapInterval(0);
	SDL_GL_SwapWindow(sdl->win);
    return (1);
}
