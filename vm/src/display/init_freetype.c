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

# define SIZE_X 76.f
# define SIZE_Y 80.f

int     prog_text(void)
{
    static float    vertices[8] = {0.f, 0.f, SIZE_X / 1920.f, 0.f, 0.f, SIZE_Y / 1080, SIZE_X / 1920.f, SIZE_Y / 1080.f};
    static float    coord_text[8] = {0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 1.f, 0.f};
    GLuint          vbo;

    if (!(g_prog = create_prog(VERTEX_TEXT, FRAGMENT_TEXT)))
        return (0);
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
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *)sizeof(vertices));
            glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return (1);
}

int     init_freetype(void)
{
    FT_GlyphSlot    slot;
    FT_Library      lib;
    FT_Face         face;
    GLuint          text;

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
    slot = face->glyph;
    if (FT_Set_Char_Size(face, 0, 16 * 64, 500, 500))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (0);
    }
    if (FT_Load_Char(face, 'A', FT_LOAD_RENDER))
    {
        ft_printf(ERROR_INIT_FONT"\n");
        return (0);
    }
    ft_printf("%d %d\n", slot->bitmap.width, slot->bitmap.rows);
    glGenTextures(1, &text);
    glBindTexture(GL_TEXTURE_2D, text);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, slot->bitmap.width, slot->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, slot->bitmap.buffer);
 //       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  //      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    glUseProgram(g_prog);
        glBindVertexArray(g_vao);
            glBindTexture(GL_TEXTURE_2D, text);
                glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
            glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0);
    glUseProgram(0);

    return (1);
}
