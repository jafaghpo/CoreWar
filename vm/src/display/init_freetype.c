/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_freetype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 03:11:16 by iburel            #+#    #+#             */
/*   Updated: 2017/11/23 00:46:37 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static GLuint   g_prog;
static GLuint   g_vao;
static GLuint   g_vbo;
static GLuint   g_arial[128];
static float    g_size[2][128];

static int  prog_text(void)
{
    static float    coord_text[8] = {0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 1.f, 0.f};

    if (!(g_prog = create_prog(VERTEX_TEXT, FRAGMENT_TEXT)))
        return (0);
    glGenBuffers(1, &g_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, g_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 8 + sizeof(coord_text), 0, GL_DYNAMIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * 8, sizeof(coord_text), coord_text);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glGenVertexArrays(1, &g_vao);
    glBindVertexArray(g_vao);
        glBindBuffer(GL_ARRAY_BUFFER, g_vbo);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *)(sizeof(float) * 8));
            glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return (1);
}

static int  load_arial(FT_Face face)
{
    FT_GlyphSlot    slot;
    int             i;

    slot = face->glyph;
    glGenTextures(128, g_arial);
    i = 0;
    while (i < 128)
    {
        if (FT_Load_Char(face, i, FT_LOAD_RENDER))
        {
            ft_printf(ERROR_INIT_FONT"\n");
            return (0);
        }
        g_size[0][i] = (float)slot->bitmap.width / (float)WIN_X;
        g_size[1][i] = (float)slot->bitmap.rows / (float)WIN_Y;
        glBindTexture(GL_TEXTURE_2D, g_arial[i]);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, slot->bitmap.width, slot->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, slot->bitmap.buffer);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
        i++;
    }
    return (1);
}

int         init_freetype(void)
{
    FT_Library      lib;
    FT_Face         face;

    if (!prog_text())
    {
        ft_printf("error\n");
        return (0);
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    if (FT_Init_FreeType(&lib))
    {
        ft_printf(ERROR_INIT_FREETYPE"\n");
        return (0);
    }
    if (FT_New_Face(lib, "fonts/arial.ttf", 0, &face))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (0);
    }
    if (FT_Set_Char_Size(face, 0, 16 * 64, 300, 300))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (0);
    }
    if (!(load_arial(face)))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (0);
    }
    return (1);
}

void        put_text(char *str, float x, float y)
{
    float   offset;
    int     i;

    offset = 0;
    glUseProgram(g_prog);
        glBindVertexArray(g_vao);
            i = 0;
            while (str[i])
            {
                float vertices[8] = {x + offset, y,
                                    x + g_size[0][(int)str[i]] + offset, y,
                                    x + offset, y + g_size[1][(int)str[i]],
                                    x + g_size[0][(int)str[i]] + offset, y + g_size[1][(int)str[i]]};
                glBindBuffer(GL_ARRAY_BUFFER, g_vbo);
                    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindTexture(GL_TEXTURE_2D, g_arial[(int)str[i]]);
                    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                glBindTexture(GL_TEXTURE_2D, 0);
                offset += g_size[0][(int)str[i]] + 0.005f;
                i++;
            }
        glBindVertexArray(0);
    glUseProgram(0);
}