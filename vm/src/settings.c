/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 17:49:37 by iburel            #+#    #+#             */
/*   Updated: 2018/01/25 21:44:47 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_uint8		g_mem[MEM_SIZE] = {};
t_infos		g_infos[MEM_SIZE] = {};
t_uint32	g_nb_player;
t_uint32	g_id;
t_champ		*g_champs;
t_uint32	g_nb_live = 0;
t_int32   	g_cycle_to_die = CYCLE_TO_DIE;
float		g_sleep = 500;
t_uint32    g_nb_cycle;
t_args		g_flags = {};
t_uint8		g_line_chat = CHAT_SIZE - 1;
GLuint		g_chat[CHAT_SIZE] = {};
t_uint8		g_chat_buffer[128][30][16 * CHAT_LINE_SIZE] = {};
t_uint32    g_pause = 1;
t_uint32    g_step = 0;
t_uint32    g_key = 0;