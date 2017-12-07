/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:49:39 by iburel            #+#    #+#             */
/*   Updated: 2017/12/07 03:42:47 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void     init_tab(float *tab)
{
    int     i;

    i = 0;
    while (i < 18 * MEM_SIZE)
    {
        tab[i + 0] = -1.f + (float)((i / 18) % 64) * (2.f / 64.f);
        tab[i + 1] = -1.f + (float)((i / 18) / 64) * (2.f / (MEM_SIZE / 64.f));
        tab[i + 2] = 0.f;
        tab[i + 3] = -1.f + (float)((i / 18) % 64 + 1) * (2.f / 64.f);
        tab[i + 4] = -1.f + (float)((i / 18) / 64) * (2.f / (MEM_SIZE / 64.f));
        tab[i + 5] = 0.f;
        tab[i + 6] = -1.f + (float)((i / 18) % 64) * (2.f / 64.f);
        tab[i + 7] = -1.f + (float)((i / 18) / 64 + 1) * (2.f / (MEM_SIZE / 64.f));
        tab[i + 8] = 0.f;
        tab[i + 9] = tab[i + 3];
        tab[i + 10] = tab[i + 4];
        tab[i + 11] = 0.f;
        tab[i + 12] = tab[i + 6];
        tab[i + 13] = tab[i + 7];
        tab[i + 14] = 0.f;
        tab[i + 15] = -1.f + (float)((i / 18) % 64 + 1) * (2.f / 64.f);
        tab[i + 16] = -1.f + (float)((i / 18) / 64 + 1) * (2.f / (MEM_SIZE / 64.f));
        tab[i + 17] = 0.f;
        i += 18;
    }
}

static void     init_coord(float *coord)
{
    int     i;

    i = 0;
    while (i < 12 * MEM_SIZE)
    {
        coord[i + 0] = 0.f;
        coord[i + 1] = 0.f;
        coord[i + 2] = 1.f;
        coord[i + 3] = 0.f;
        coord[i + 4] = 0.f;
        coord[i + 5] = 1.f;
        coord[i + 6] = 1.f;
        coord[i + 7] = 0.f;
        coord[i + 8] = 0.f;
        coord[i + 9] = 1.f;
        coord[i + 10] = 1.f;
        coord[i + 11] = 1.f;
        i += 12;
    }
}

static void     init_vram(t_gl *gl)
{
    float   tab[18 * MEM_SIZE];
    float   coord[12 * MEM_SIZE];

    init_tab(tab);
    init_coord(coord);
    glGenBuffers(1, &gl->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(tab) + sizeof(coord) + sizeof(g_mem), 0, GL_DYNAMIC_DRAW);
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(tab), tab);
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(tab), sizeof(coord), coord);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glGenVertexArrays(1, &gl->vao);
    glBindVertexArray(gl->vao);
        glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *)sizeof(tab));
            glEnableVertexAttribArray(1);
            glVertexAttribPointer(2, 1, GL_UNSIGNED_BYTE, GL_FALSE, 0, (GLvoid *)(sizeof(tab) + sizeof(coord)));
            glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

int             init_gl(t_gl *gl)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_CULL_FACE);
    if ((gl->prog = create_prog(VERTEX_DISPLAY, FRAGMENT_DISPLAY)) == UINT_MAX)
        return (0);
    glBindAttribLocation(gl->prog, 2, "in_Mem");
    init_vram(gl);
    return (1);
}