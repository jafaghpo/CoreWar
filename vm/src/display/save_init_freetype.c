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

# define SIZE_X 76.f
# define SIZE_Y 80.f

int         prog_text(void)
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

FT_Library  init_freetype(void)
{
    FT_GlyphSlot    slot;
    FT_Library      lib;
    FT_Face         face;
    GLuint          text[128];
    float           size[2][128];
    int             i;

    if (!prog_text())
    {
        ft_printf("error\n");
        return (NULL);
    }
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    if (FT_Init_FreeType(&lib))
    {
        ft_printf(ERROR_INIT_FREETYPE"\n");
        return (NULL);
    }
    if (FT_New_Face(lib, "fonts/arial.ttf", 0, &face))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (NULL);
    }
    slot = face->glyph;
    if (FT_Set_Char_Size(face, 0, 16 * 64, 500, 500))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (NULL);
    }

    glGenTextures(128, text);

    i = 0;
    while (i < 128)
    {
        if (FT_Load_Char(face, i, FT_LOAD_RENDER))
        {
            ft_printf(ERROR_INIT_FONT"\n");
            return (0);
        }
        size[0][i] = (float)slot->bitmap.width / (float)WIN_X;
        size[1][i] = (float)slot->bitmap.rows / (float)WIN_Y;
        glBindTexture(GL_TEXTURE_2D, text[i]);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, slot->bitmap.width, slot->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, slot->bitmap.buffer);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
        i++;
    }

    char    tmp[] = "salut";
    float   offset = 0;
    int     j;

    glUseProgram(g_prog);
        glBindVertexArray(g_vao);
            j = 0;
            while (tmp[j])
            {
                float vertices[8] = {0.f + offset, 0.f, size[0][(int)tmp[j]] + offset, 0.f, 0.f + offset, size[1][(int)tmp[j]], size[0][(int)tmp[j]] + offset, size[1][(int)tmp[j]]};
                glBindBuffer(GL_ARRAY_BUFFER, g_vbo);
                    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindTexture(GL_TEXTURE_2D, text[(int)tmp[j]]);
                    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
                glBindTexture(GL_TEXTURE_2D, 0);
                offset += size[0][(int)tmp[j]] + 0.005;
                j++;
            }
        glBindVertexArray(0);
    glUseProgram(0);

    return ();
}
