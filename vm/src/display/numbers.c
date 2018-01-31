/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 21:49:59 by iburel            #+#    #+#             */
/*   Updated: 2018/01/31 00:17:32 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static GLuint   g_prog;
static GLuint   g_vao;
static GLuint   g_text[3];

static void init_vertices(float *vertices)
{
    vertices[0] = 0.9f;
    vertices[1] = 0.9f;
    vertices[2] = 0.9f + 16.f / (float)WIN_X * 3.f * 2.f;
    vertices[3] = 0.9f;
    vertices[4] = 0.9f;
    vertices[5] = 0.9f + 17.f / (float)WIN_Y * 2.f;
    vertices[6] = 0.9f + 16.f / (float)WIN_X * 3.f * 2.f;
    vertices[7] = 0.9f + 17.f / (float)WIN_Y * 2.f;
    vertices[8] = 0.5f;
    vertices[9] = 0.7f;
    vertices[10] = 0.5f + 16.f / (float)WIN_X * 7.f * 2.f;
    vertices[11] = 0.7f;
    vertices[12] = 0.5f;
    vertices[13] = 0.7f + 17.f / (float)WIN_Y * 2.f;
    vertices[14] = 0.5f + 16.f / (float)WIN_X * 7.f * 2.f;
    vertices[15] = 0.7f + 17.f / (float)WIN_Y * 2.f;
    vertices[16] = 0.8f;
    vertices[17] = 0.7f;
    vertices[18] = 0.8f + 16.f / (float)WIN_X * 5.f * 2.f;
    vertices[19] = 0.7f;
    vertices[20] = 0.8f;
    vertices[21] = 0.7f + 17.f / (float)WIN_Y * 2.f;
    vertices[22] = 0.8f + 16.f / (float)WIN_X * 5.f * 2.f;
    vertices[23] = 0.7f + 17.f / (float)WIN_Y * 2.f;
}

static void init_coord_text(float *coord_text)
{
    coord_text[0] = 0.f;
    coord_text[1] = 1.f;
    coord_text[2] = 1.f;
    coord_text[3] = 1.f;
    coord_text[4] = 0.f;
    coord_text[5] = 0.f;
    coord_text[6] = 1.f;
    coord_text[7] = 0.f;
    coord_text[8] = 0.f;
    coord_text[9] = 1.f;
    coord_text[10] = 1.f;
    coord_text[11] = 1.f;
    coord_text[12] = 0.f;
    coord_text[13] = 0.f;
    coord_text[14] = 1.f;
    coord_text[15] = 0.f;
    coord_text[16] = 0.f;
    coord_text[17] = 1.f;
    coord_text[18] = 1.f;
    coord_text[19] = 1.f;
    coord_text[20] = 0.f;
    coord_text[21] = 0.f;
    coord_text[22] = 1.f;
    coord_text[23] = 0.f;
}

int         prog_numbers(void)
{
    float    vertices[24];
    float    coord_text[24];
    GLuint   vbo;

    init_vertices(vertices);
    init_coord_text(coord_text);
    glGenTextures(3, g_text);
    if (!(g_prog = create_prog(VERTEX_NUMBERS, FRAGMENT_NUMBERS)))
        return (0);
    glUseProgram(g_prog);
        glUniform3f(glGetUniformLocation(g_prog, "color_font"), g_theme.color_fps.r, g_theme.color_fps.g, g_theme.color_fps.b);
        glUniform1i(glGetUniformLocation(g_prog, "text"), 0);
    glUseProgram(0);
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
            glBindTexture(GL_TEXTURE_2D, g_text[0]);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
            glBindTexture(GL_TEXTURE_2D, g_text[1]);
            glDrawArrays(GL_TRIANGLE_STRIP, 4, 4);
            glBindTexture(GL_TEXTURE_2D, g_text[2]);
            glDrawArrays(GL_TRIANGLE_STRIP, 8, 4);
        glBindVertexArray(0);
    glUseProgram(0);
}

void        update_fps(int fps)
{
    Uint8   buf[17][16 * 3];
    int     y;
    int     i;
    int     div;
    int     nb;

    ft_bzero(buf, sizeof(buf));
    nb = 1;
    div = 1;
    while (div * 10 <= fps)
    {
        div *= 10;
        nb++;
    }
    i = 3 - nb;
    while (i < 3)
    {
        y = 0;
        while (y < 17)
        {
            ft_memcpy(buf[y] + i * 16, g_font[fps / div + '0'][y + 4], 16);
            y++;
        }
        fps %= div;
        div /= 10;
        i++;
    }
    glBindTexture(GL_TEXTURE_2D, g_text[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 16 * 3, 17, 0, GL_RED, GL_UNSIGNED_BYTE, buf);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    i++;
}

void        update_nb_cycle(int nb_cycle)
{
    Uint8   buf[17][16 * 7];
    int     y;
    int     i;
    int     div;
    int     nb;

    ft_bzero(buf, sizeof(buf));
    nb = 1;
    div = 1;
    while (div * 10 <= nb_cycle)
    {
        div *= 10;
        nb++;
    }
    i = 7 - nb;
    while (i < 7)
    {
        y = 0;
        while (y < 17)
        {
            ft_memcpy(buf[y] + i * 16, g_font[nb_cycle / div + '0'][y + 4], 16);
            y++;
        }
        nb_cycle %= div;
        div /= 10;
        i++;
    }
    glBindTexture(GL_TEXTURE_2D, g_text[1]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 16 * 7, 17, 0, GL_RED, GL_UNSIGNED_BYTE, buf);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    i++;
}

void        update_speed(int number)
{
    static int  save = 0;
    Uint8       buf[17][16 * 5];
    int         y;
    int         i;
    int         div;
    int         nb;

    if (number == save)
        return ;
    save = number;
    number = 1000000 / number;
    ft_bzero(buf, sizeof(buf));
    nb = 1;
    div = 1;
    while (div * 10 <= number)
    {
        div *= 10;
        nb++;
    }
    i = 5 - nb;
    while (i < 5)
    {
        y = 0;
        while (y < 17)
        {
            ft_memcpy(buf[y] + i * 16, g_font[number / div + '0'][y + 4], 16);
            y++;
        }
        number %= div;
        div /= 10;
        i++;
    }
    glBindTexture(GL_TEXTURE_2D, g_text[2]);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 16 * 5, 17, 0, GL_RED, GL_UNSIGNED_BYTE, buf);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    i++;
}