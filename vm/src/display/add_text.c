/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:01:27 by iburel            #+#    #+#             */
/*   Updated: 2018/02/02 19:29:41 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void    add_text(Uint8 *buf, char *str, int x, int y)
{
    int     offset;
    int     i;
    int     j;
    int     tmp;

    offset = 0;
    while (*str)
    {
        i = 0;
        while (i < 30)
        {
            j = 0;
            while (j < 16)
            {
                tmp = ((i + y) * (WIN_X * 6 / 20) + x + offset + j) * 4;
                buf[tmp + 0] = (Uint8)((float)buf[tmp + 0] * ((float)(0xff - g_font[(int)*str][i][j]) / 255.f));
                buf[tmp + 1] = (Uint8)((float)buf[tmp + 1] * ((float)(0xff - g_font[(int)*str][i][j]) / 255.f));
                buf[tmp + 2] = (Uint8)((float)buf[tmp + 2] * ((float)(0xff - g_font[(int)*str][i][j]) / 255.f));
                buf[tmp + 3] = 0xff;
                j++;
            }
            i++;
        }
        offset += g_font_size[(int)*str];
        str++;
    }
}