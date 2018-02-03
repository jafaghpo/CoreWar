/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:01:27 by iburel            #+#    #+#             */
/*   Updated: 2018/02/03 15:20:00 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void    add_text(Uint8 *buf, char *str, int x, int y, t_case *color)
{
    int     offset;
    int     i;
    int     j;
    int     tmp;
    int     trans;

    offset = 0;
    while (*str)
    {
        if (*str < 0)
        {
            str++;
            continue ;
        }
        i = 0;
        while (i < 30)
        {
            j = 0;
            while (j < 16)
            {
                tmp = ((i + y) * (WIN_X * 6 / 20) + x + offset + j) * 4;
                buf[tmp + 0] = (Uint8)((float)buf[tmp + 0] * ((float)(0xff - g_font[(int)*str][i][j]) / 255.f) + color->r * (float)g_font[(int)*str][i][j]);
                buf[tmp + 1] = (Uint8)((float)buf[tmp + 1] * ((float)(0xff - g_font[(int)*str][i][j]) / 255.f) + color->g * (float)g_font[(int)*str][i][j]);
                buf[tmp + 2] = (Uint8)((float)buf[tmp + 2] * ((float)(0xff - g_font[(int)*str][i][j]) / 255.f) + color->b * (float)g_font[(int)*str][i][j]);
                trans = buf[tmp + 3] + g_font[(int)*str][i][j];
                if (trans >= 0xff)
                    buf[tmp + 3] = 0xff;
                else
                    buf[tmp + 3] = trans;
                j++;
            }
            i++;
        }
        offset += g_font_size[(int)*str];
        str++;
    }
}