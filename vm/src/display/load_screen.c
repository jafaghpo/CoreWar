/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 01:02:31 by iburel            #+#    #+#             */
/*   Updated: 2018/02/04 18:47:09 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static GLuint   g_prog;
static GLuint   g_vao;

int     init_load_screen(void)
{
    static float    vertices[8] = {0.f, -0.217f, 0.0079f, -0.217f, 0.f, -0.275f, 0.0079f, -0.275f};
    GLuint          vbo;

    if (!(g_prog = create_prog(VERTEX_LOAD, FRAGMENT_LOAD)))
        return (0);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), 0, GL_STATIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glGenVertexArrays(1, &g_vao);
    glBindVertexArray(g_vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
            glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    return (1);
}

void    display_load(SDL_Window *win, float per)
{
    static float  save = -0.377f;

    glUseProgram(g_prog);
        glBindVertexArray(g_vao);
            glUniform1f(glGetUniformLocation(g_prog, "offset"), (float)save);
            glUniform1f(glGetUniformLocation(g_prog, "size"), (float)per * 100.f);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glBindVertexArray(0);
    glUseProgram(0);
    SDL_GL_SwapWindow(win);
    save += per * 0.79;
}