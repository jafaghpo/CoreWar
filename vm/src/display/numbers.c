/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 21:49:59 by iburel            #+#    #+#             */
/*   Updated: 2018/01/19 23:58:17 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static GLuint   g_prog;
static GLuint   g_vao;
static GLuint   text[1];

static void init_array(float *vertices, float *coord_text)
{
    vertices[0] = 0.9f;
    vertices[1] = 0.9f;
    vertices[2] = 0.9f + 16.f / (float)WIN_X * 3.f;
    vertices[3] = 0.9f;
    vertices[4] = 0.9f;
    vertices[5] = 0.9f + 17.f / (float)WIN_Y;
    vertices[6] = 0.9f + 16.f / (float)WIN_X * 3.f;
    vertices[7] = 0.9f + 17.f / (float)WIN_Y;
    coord_text[0] = 0.f;
    coord_text[1] = 1.f;
    coord_text[2] = 1.f;
    coord_text[3] = 1.f;
    coord_text[4] = 0.f;
    coord_text[5] = 0.f;
    coord_text[6] = 1.f;
    coord_text[7] = 0.f;
}

int         prog_numbers(void)
{
    static float    vertices[8];
    static float    coord_text[8];
    GLuint          vbo;

    init_array(vertices, coord_text);
    glGenTextures(1, text);
    if (!(g_prog = create_prog(VERTEX_NUMBERS, FRAGMENT_NUMBERS)))
        return (0);
    glUniform1i(glGetUniformLocation(g_prog, "text"), 0);
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

void        put_numbers(void)
{
    glUseProgram(g_prog);
        glBindVertexArray(g_vao);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, text[0]);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glBindVertexArray(0);
    glUseProgram(0);
}

void        update_numbers(int *numbers)
{
    Uint8   buf[17][16 * 3];
    int     y;
    int     i;
    int     div;

    ft_bzero(buf, sizeof(buf));
    div = 100;
    i = 0;
    while (i < 3)
    {
        y = 0;
        while (y < 17)
        {
            ft_memcpy(buf[y] + i * 16, g_font[numbers[0] / div + '0'][y + 4], 16);
            y++;
        }
        numbers[0] %= div;
        div /= 10;
        i++;
    }
    glBindTexture(GL_TEXTURE_2D, text[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 16 * 3, 17, 0, GL_RED, GL_UNSIGNED_BYTE, buf);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    i++;
}