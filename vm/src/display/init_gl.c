/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 21:49:39 by iburel            #+#    #+#             */
/*   Updated: 2018/02/12 14:43:49 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void		init_tab(float *tab)
{
	int		i;

	i = 0;
	while (i < 12 * MEM_SIZE)
	{
		tab[i + 0] = -1.f + (float)((i / 12) % 64) * (2.0f / 64.f);
		tab[i + 1] = -1.f + (float)((i / 12) / 64) * (2.0f / (MEM_SIZE / 64.f));
		tab[i + 2] = 0.f;

		tab[i + 3] = -1.f + ((float)((i / 12) % 64) + 0.95) * (2.0f / 64.f);
		tab[i + 4] = -1.f + (float)((i / 12) / 64) * (2.0f / (MEM_SIZE / 64.f));
		tab[i + 5] = 0.f;

		tab[i + 6] = -1.f + (float)((i / 12) % 64) * (2.0f / 64.f);
		tab[i + 7] = -1.f + ((float)((i / 12) / 64) + 0.95) * (2.0f / (MEM_SIZE / 64.f));
		tab[i + 8] = 0.f;

		tab[i + 9] = -1.f + ((float)((i / 12) % 64) + 0.95) * (2.0f / 64.f);
		tab[i + 10] = -1.f + ((float)((i / 12) / 64) + 0.95) * (2.0f / (MEM_SIZE / 64.f));
		tab[i + 11] = 0.f;

		i += 12;
	}
}

static void		init_coord(float *coord)
{
	int		i;

	i = 0;
	while (i < 8 * MEM_SIZE)
	{
		coord[i + 0] = 0.f;
		coord[i + 1] = 0.f;

		coord[i + 2] = 1.f;
		coord[i + 3] = 0.f;

		coord[i + 4] = 0.f;
		coord[i + 5] = 1.f;

		coord[i + 6] = 1.f;
		coord[i + 7] = 1.f;
		i += 8;
	}
}

static void		init_vram(t_gl *gl)
{
	float	tab[12 * MEM_SIZE];
	float	coord[8 * MEM_SIZE];

	init_tab(tab);
	init_coord(coord);
	glGenBuffers(1, &gl->vbo);
	glBindBuffer(GL_ARRAY_BUFFER, gl->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(tab) + sizeof(coord), 0, GL_STATIC_DRAW);
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
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

int				init_gl(t_gl *gl)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);
	if ((gl->prog = create_prog(VERTEX_DISPLAY, FRAGMENT_DISPLAY)) == UINT_MAX)
		return (0);
	glUseProgram(gl->prog);
	glUniform3f(glGetUniformLocation(gl->prog, "color_text"), g_theme.color_texture.r, g_theme.color_texture.g, g_theme.color_texture.b);
	glUniform3f(glGetUniformLocation(gl->prog, "color_font"), g_theme.color_numbers.r, g_theme.color_numbers.g, g_theme.color_numbers.b);
	glUniform1i(glGetUniformLocation(gl->prog, "text"), 0);
	glUseProgram(0);
	init_vram(gl);
	return (1);
}
