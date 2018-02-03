/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_freetype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 03:11:16 by iburel            #+#    #+#             */
/*   Updated: 2018/02/03 15:18:03 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

Uint8    g_font[128][30][16];
int      g_font_size[128];

static void resize(int i, FT_GlyphSlot slot)
{
    Uint32     y;

    y = 0;
    while (y < slot->bitmap.rows && y < 30)
    {
        if (slot->bitmap_top <= 20)
        {
            ft_memcpy(g_font[i][20 - slot->bitmap_top + y] + slot->bitmap_left,
                    slot->bitmap.buffer + y * slot->bitmap.width,
                    slot->bitmap.width);
        }
        y++;
    }
}

static int  load_font(FT_Face face)
{
    FT_GlyphSlot    slot;
    int             i;

    slot = face->glyph;
    i = 0;
    while (i < 128)
    {       
        if (FT_Load_Char(face, i, FT_LOAD_RENDER))
        {
            ft_printf(ERROR_INIT_FONT"\n");
            return (0);
        }
        g_font_size[i] = slot->advance.x >> 6;
        resize(i, slot);
        i++;
    }
    return (1);
}

int         init_freetype(void)
{
    FT_Library      lib;
    FT_Face         face;

    if (FT_Init_FreeType(&lib))
    {
        ft_printf(ERROR_INIT_FREETYPE"\n");
        return (0);
    }
    if (FT_New_Face(lib, g_theme.police_file, 0, &face))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (0);
    }
    if (FT_Set_Char_Size(face, 0, POLICE_SIZE * 64, 100, 100))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (0);
    }
    if (!load_font(face))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (0);
    }
    if (!prog_chat())
    {
        ft_printf("error\n");
        return (0);
    }
    if (!prog_numbers())
    {
        ft_printf("error\n");
        return (0);
    }
    return (1);
}

void        add_line_chat(char *str)
{
    int     tmp;
    int     x;
    int     y;

    tmp = (g_line_chat + 1) % CHAT_SIZE;
    ft_bzero(g_chat_buffer[tmp], 30 * 16 * CHAT_LINE_SIZE);    
    x = 0;
    while (*str)
    {
        if (*str < 0)
        {
            str++;
            continue ;
        }
        y = 0;
        while (y < 30)
        {
            ft_memcpy(g_chat_buffer[tmp][y] + x, g_font[(int)*str][y], 16);
            y++;
        }
        x += (int)g_font_size[(int)*str];
        str++;
    }
    g_chat[tmp] = 0;
    g_line_chat = tmp;
}

void        load_numbers(GLuint *police_text)
{
    Uint8   buf[51][51];
    int     i;
    int     y;

    glGenTextures(16, police_text);
    i = 0;
    while (i < 16)
    {
        ft_bzero(buf, sizeof(buf));
        y = 0;
        while (y < 30)
        {
            ft_memcpy(buf[y + 12] + 20 + y, g_font[i + '0' + ('A' - '0' - 10) * (i >= 10)][y], 16);
            y++;
        }
        glBindTexture(GL_TEXTURE_2D, police_text[i]);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 50, 50, 0, GL_RED, GL_UNSIGNED_BYTE, buf);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
        i++;
    }
}