/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_init_freetype.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 03:11:16 by iburel            #+#    #+#             */
/*   Updated: 2018/01/16 22:32:15 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static GLuint   g_prog;
static GLuint   g_vao;
static GLuint   g_vbo;
static GLuint   g_arial[128];
static float    g_size[5][128];
static GLuint   text_location;
static GLuint   pos_location;

#define OUAIS ((float)POLICE_SIZE / (float)WIN_Y)
#define SIZE_X g_size[0][(int)str[i]]
#define SIZE_Y g_size[1][(int)str[i]]
#define CORR_X g_size[2][(int)str[i]]
#define CORR_Y (-g_size[3][(int)str[i]])
#define ADVANCE g_size[4][(int)str[i]]

static int  prog_text(void)
{
    static float    vertices[8] = {0.f, 0.f, OUAIS, 0.f, 0.f, OUAIS, OUAIS, OUAIS};
    static float    coord_text[8] = {0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 1.f, 0.f};

    if (!(g_prog = create_prog(VERTEX_TEXT, FRAGMENT_TEXT)))
        return (0);
    text_location = glGetUniformLocation(g_prog, "text");
    pos_location = glGetUniformLocation(g_prog, "pos");
    glGenBuffers(1, &g_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, g_vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(coord_text), 0, GL_STATIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(coord_text), coord_text);
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
        g_size[2][i] = (float)slot->bitmap_left / (float)WIN_X;
        g_size[3][i] = (float)slot->bitmap_top / (float)WIN_Y;
        g_size[4][i] = (float)(slot->advance.x >> 6) / (float)WIN_X;
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

static void redim_text(Uint8 data[50][50], FT_GlyphSlot slot, Uint32 x, Uint32 y)
{
    Uint32      i;

    ft_bzero(data, 50 * 50);
    i = 0;
    while (i < slot->bitmap.rows)
    {
        ft_memcpy(data[y + i] + x, slot->bitmap.buffer + i * slot->bitmap.width, slot->bitmap.width);
        i++;
    }
}

static int  fill_police_text(FT_Face face, GLuint *police_text)
{
    static Uint8    data[50][50];
    int             i;

    glGenTextures(32, police_text);
    i = 0;
    while (i < 16)
    {
        if (FT_Load_Char(face, (i + '0') + ((i >= 10) * ('A' - '0' - 10)), FT_LOAD_RENDER))
        {
            ft_printf(ERROR_INIT_FONT"\n");
            return (0);
        }
        redim_text(data, face->glyph, 10, 15);
        glBindTexture(GL_TEXTURE_2D, police_text[i]);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 50, 50, 0, GL_RED, GL_UNSIGNED_BYTE, data);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
        redim_text(data, face->glyph, 30, 15);
        glBindTexture(GL_TEXTURE_2D, police_text[i + 16]);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 50, 50, 0, GL_RED, GL_UNSIGNED_BYTE, data);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
        i++;
    }
    return (1);
}

int         init_freetype(GLuint *police_text)
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
    if (!(load_arial(face)))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (0);
    }
    if (!(fill_police_text(face, police_text)))
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
            glUniform1i(text_location, 0);
            i = 0;
            while (str[i])
            {
                if (str[i] < 0)
                {
                    i++;
                    continue ;
                }
                glUniform2f(pos_location, x + offset, y);
			    glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, g_arial[(int)str[i]]);
                    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                offset += OUAIS;
                i++;
            }
        glBindVertexArray(0);
    glUseProgram(0);
}