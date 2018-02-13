/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:30:41 by iburel            #+#    #+#             */
/*   Updated: 2018/02/13 16:24:10 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

SDL_Window	*load_sdl(void)
{
	SDL_Window		*win;

	if (SDL_Init(SDL_INIT_VIDEO))
		ft_afferror(ERROR_INIT_SDL);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
		SDL_GL_CONTEXT_PROFILE_CORE);
	if (!(win = SDL_CreateWindow("corewar", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)))
		ft_afferror(ERROR_CREAT_WINDOW);
	return (win);
}
