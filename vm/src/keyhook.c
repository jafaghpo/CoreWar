/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:03:53 by niragne           #+#    #+#             */
/*   Updated: 2018/03/13 16:48:49 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	check_breakpoints(void)
{
	static int	i = 0;
	char		str[CHAT_LINE_SIZE];

	if (g_flags.breakpoints[i] == g_nb_cycle && g_nb_cycle)
	{
		ft_sprintf(str, "[%6d] Game paused (breakpoint %d / %d)",
					g_nb_cycle, i + 1, g_flags.nb_breakpoints);
		g_flags.breakpoints[i] = 0;
		g_pause = 1;
		add_line_chat(str);
		i++;
	}
}

static void	loop_hook(t_uint8 *key)
{
	while (!g_key)
	{
		if (key[SDL_SCANCODE_X] && g_sleep <= 900000.f)
			g_sleep *= 1.000005;
		if (key[SDL_SCANCODE_Z])
		{
			if (g_sleep > 50.f)
				g_sleep *= 0.999995;
			else
				g_sleep = 50.f;
		}
		check_breakpoints();
		usleep(1);
	}
	if (g_key == SDLK_c)
		g_sleep = 2000;
	if (g_key == SDLK_n)
	{
		g_step = !g_step;
		g_pause = 0;
	}
}

static void	manage_pause(int *start, char str[CHAT_LINE_SIZE])
{
	if (!g_pause)
	{
		ft_sprintf(str, "[%6d] Game paused by user.", g_nb_cycle);
		add_line_chat(str);
	}
	else
	{
		if (*start == 0)
			ft_sprintf(str, "[%6d] Game unpaused by user.", g_nb_cycle);
		else
		{
			ft_sprintf(str, "[%6d] Game started by user.", g_nb_cycle);
			start_music();
			*start = 0;
		}
		add_line_chat(str);
	}
	g_pause = !g_pause;
}

void		*keyhook(void *av)
{
	t_uint8 *key;
	char	str[CHAT_LINE_SIZE];
	int		start;

	start = 1;
	(void)av;
	key = (Uint8 *)SDL_GetKeyboardState(NULL);
	while (1)
	{
		loop_hook(key);
		if (g_key == SDLK_SPACE)
		{
			manage_pause(&start, str);
		}
		g_key = 0;
	}
	return (NULL);
}
