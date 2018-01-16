/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_freetype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 03:11:16 by iburel            #+#    #+#             */
/*   Updated: 2018/01/16 01:20:11 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static Uint8    g_font[128][30][16];
static int      g_font_size[128];
static GLuint   g_prog;
static GLuint   g_vao;
static GLuint   text_location;
static GLuint   pos_location;

static void resize(int i, FT_GlyphSlot slot)
{
    Uint32     y;

    y = 0;
    while (y < slot->bitmap.rows)
    {
        ft_memcpy(g_font[i][20 - slot->bitmap_top + y] + slot->bitmap_left,
                  slot->bitmap.buffer + y * slot->bitmap.width,
                  slot->bitmap.width);
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
        g_font_size[i] = slot->bitmap.width + (slot->advance.x >> 6);
        resize(i, slot);
        i++;
    }
    return (1);
}

static void init_array(float *vertices, float *coord_text)
{
    int     i;

    i = 0;
    while (i < 8 * CHAT_SIZE)
    {
        vertices[i + 0] = 0.41f;
        vertices[i + 1] = -0.9f + (float)30 / (float)WIN_Y * (float)(i / 8 + 1);
        vertices[i + 2] = 0.41f + (float)(16 * CHAT_LINE_SIZE) / (float)WIN_Y;
        vertices[i + 3] = -0.9f + (float)30 / (float)WIN_Y * (float)(i / 8 + 1);
        vertices[i + 4] = 0.41f;
        vertices[i + 5] = -0.9f + (float)30 / (float)WIN_Y * (float)(i / 8);
        vertices[i + 6] = 0.41f + (float)(16 * CHAT_LINE_SIZE) / (float)WIN_Y;
        vertices[i + 7] = -0.9f + (float)30 / (float)WIN_Y * (float)(i / 8);
        coord_text[i + 0] = 0.f;
        coord_text[i + 1] = 0.f;
        coord_text[i + 2] = 1.f;
        coord_text[i + 3] = 0.f;
        coord_text[i + 4] = 0.f;
        coord_text[i + 5] = 1.f;
        coord_text[i + 6] = 1.f;
        coord_text[i + 7] = 1.f;
        i += 8;
    }
}

static int  prog_chat(void)
{
    static float    vertices[8 * CHAT_SIZE];
    static float    coord_text[8 * CHAT_SIZE];
    GLuint          vbo;

    init_array(vertices, coord_text);
    if (!(g_prog = create_prog(VERTEX_CHAT, FRAGMENT_CHAT)))
        return (0);
    text_location = glGetUniformLocation(g_prog, "text");
    pos_location = glGetUniformLocation(g_prog, "pos");
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(coord_text), 0, GL_STATIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(coord_text), coord_text);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glGenVertexArrays(1, &g_vao);
    glBindVertexArray(g_vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *)(sizeof(vertices)));
            glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return (1);
}

void        put_chat(void)
{
    int     i;

    glUseProgram(g_prog);
        glBindVertexArray(g_vao);
            glUniform1i(text_location, 0);
            i = 0;
            while (i < CHAT_SIZE)
            {
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, g_chat[i]);
                    glDrawArrays(GL_TRIANGLE_STRIP, i * 4, 4);
                i++;
            }
        glBindVertexArray(0);
    glUseProgram(0);
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
    if (FT_New_Face(lib, "fonts/monaco.ttf", 0, &face))
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
    glGenTextures(CHAT_SIZE, g_chat);
    if (!prog_chat())
    {
        ft_printf("error\n");
        return (0);
    }
    return (1);
}

void        add_line_chat(char *str)
{
    static Uint8   buf[30][16 * CHAT_LINE_SIZE];
    int     tmp;
    int     x;
    int     y;

    ft_bzero(buf, sizeof(buf));
    tmp = (g_line_chat + 1) % CHAT_SIZE;
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
            ft_memcpy(buf[y] + x, g_font[(int)*str][y], 16);
            y++;
        }
        x += 13;
//        x += (int)g_font_size[(int)*str];
        str++;
    }
    glBindTexture(GL_TEXTURE_2D, g_chat[tmp]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 16 * CHAT_LINE_SIZE, 30, 0, GL_RED, GL_UNSIGNED_BYTE, buf);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    g_line_chat = tmp;
}