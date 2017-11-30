/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_chat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 02:28:24 by iburel            #+#    #+#             */
/*   Updated: 2017/11/30 00:36:59 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

# define DIFF_Y (((float)POLICE_SIZE / (float)WIN_Y) * 1.5f)

void    put_chat(void)
{
    int     i;
    int     tmp;
    float   y;

    tmp = g_line_chat;
    y = 0;
    i = tmp;
    while (i >= 0)
    {
        put_text(g_chat[i], 0.43f, -0.95f + y * DIFF_Y);
        i--;
        y++;
    }
    i = CHAT_SIZE - 1;
    while (i > tmp)
    {
        put_text(g_chat[i], 0.43f, -0.95f + y * DIFF_Y);
        i--;
        y++;
    }
}