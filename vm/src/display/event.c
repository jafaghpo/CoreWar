/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:29:58 by iburel            #+#    #+#             */
/*   Updated: 2018/02/14 16:26:14 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void	event2(t_mat4 *projection, t_mat4 *modelview, Uint8 *key)
{
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

void		event(t_mat4 *projection, t_mat4 *modelview)
{
	Uint8	*key;

	key = (Uint8 *)SDL_GetKeyboardState(NULL);
	if (key[SDL_SCANCODE_W])
		rotate(modelview, norme(1.f, 0.f, 0.f), M_PI / 64.f);
	if (key[SDL_SCANCODE_A])
		rotate(modelview, norme(0.f, 1.f, 0.f), M_PI / 64.f);
	if (key[SDL_SCANCODE_S])
		rotate(modelview, norme(-1.f, 0.f, 0.f), M_PI / 64.f);
	if (key[SDL_SCANCODE_D])
		rotate(modelview, norme(0.f, -1.f, 0.f), M_PI / 64.f);
	if (key[SDL_SCANCODE_Q])
		rotate(modelview, norme(0.f, 0.f, 1.f), M_PI / 64.f);
	if (key[SDL_SCANCODE_E])
		rotate(modelview, norme(0.f, 0.f, -1.f), M_PI / 64.f);
	event2(projection, modelview, key);
}

static void	check_events2(t_mats *mats, int *mouse, SDL_Event *event)
{
	if (event->type == SDL_MOUSEBUTTONUP)
	{
		if (event->button.button == SDL_BUTTON_LEFT)
			mouse[0] = 0;
		else if (event->button.button == SDL_BUTTON_RIGHT)
			mouse[1] = 0;
	}
	else if (event->type == SDL_MOUSEMOTION)
	{
		if (mouse[0])
			rotate(&mats->modelview, norme((float)event->motion.yrel,
			(float)event->motion.xrel, 0.f),
			(M_PI / 512.f) * sqrt(event->motion.yrel * event->motion.yrel +
			event->motion.xrel * event->motion.xrel));
		if (mouse[1])
			translation(&mats->projection,
			(t_vec3){(float)event->motion.xrel / (float)WIN_X * 2.f,
			-(float)event->motion.yrel / (float)WIN_Y * 2.f, 0.f});
	}
}

int			check_events(t_mats *mats, int *mouse)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			return (1);
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				return (1);
			while (g_key)
				;
			g_key = event.key.keysym.sym;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
				mouse[0] = 1;
			else if (event.button.button == SDL_BUTTON_RIGHT)
				mouse[1] = 1;
		}
		else
			check_events2(mats, mouse, &event);
	}
	return (0);
}
