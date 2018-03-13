/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:49:37 by iburel            #+#    #+#             */
/*   Updated: 2018/03/13 20:57:00 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_uint8		g_mem[MEM_SIZE] = {0};
t_infos		g_infos[MEM_SIZE] = {{0, 0, 0}};
t_uint32	g_nb_player;
t_uint32	g_nb_process;
t_champ		*g_champs;
t_uint32	g_nb_live = 0;
t_int32		g_cycle_to_die = CYCLE_TO_DIE;
float		g_sleep = 2000;
t_uint32	g_nb_cycle = 0;
t_args		g_flags = {0, 0, 0, 0, {0}, 0};
t_uint8		g_line_chat = CHAT_SIZE - 1;
GLuint		g_chat[CHAT_SIZE] = {0};
t_uint8		g_chat_buffer[128][30][16 * CHAT_LINE_SIZE] = {{{0}}};
t_uint32	g_pause = 1;
t_uint32	g_step = 0;
t_uint32	g_key = 0;

t_theme		g_theme =
{
	PATH"/theme/default/black.jpg",
	PATH"/theme/default/frame.png",
	PATH"/theme/default/white.jpg",
	PATH"/theme/default/white.jpg",
	NULL,
	PATH"/theme/default/arial.ttf",
	{1.f, 1.f, 1.f},
	{
		{1.f / 255.f, 223.f / 255.f, 215.f / 255.f},
		{233.f / 255.f, 70.f / 255.f, 70.f / 255.f},
		{127.f / 255.f, 221.f / 255.f, 76.f / 255.f},
		{152.f / 255.f, 50.f / 255.f, 203.f / 255.f}
	},
	{0.f, 0.f, 0.f},
	{0.f, 0.f, 0.f},
	{0.f, 0.f, 0.f},
	{0.f, 0.f, 0.f}
};
