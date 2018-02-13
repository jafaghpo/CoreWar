/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 18:51:02 by iburel            #+#    #+#             */
/*   Updated: 2018/02/13 17:02:01 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static GLuint	g_prog;
static GLuint	g_vao;
static GLuint	g_offset_location;
static GLuint	g_size_location;
static GLuint	g_text_location;

int		init_square_texture(void)
{
	static float	vertices[8] = {0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 1.f, 1.f};
	static float	coord_text[8] = {0.f, 1.f, 1.f, 1.f, 0.f, 0.f, 1.f, 0.f};
	GLuint			vbo;

	if (!(g_prog = create_prog(VERTEX_SQUARE, FRAGMENT_SQUARE)))
		return (0);
	g_offset_location = glGetUniformLocation(g_prog, "offset");
	g_size_location = glGetUniformLocation(g_prog, "size");
	g_text_location = glGetUniformLocation(g_prog, "text");
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) + sizeof(coord_text),
		0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices),
		sizeof(coord_text), coord_text);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenVertexArrays(1, &g_vao);
	glBindVertexArray(g_vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
		0, (GLvoid *)sizeof(vertices));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return (1);
}

void	display_square(t_vec2 offset, t_vec2 size, GLuint text)
{
	glUseProgram(g_prog);
	glBindVertexArray(g_vao);
	glUniform2f(g_offset_location, offset.x, offset.y);
	glUniform2f(g_size_location, size.x, size.y);
	glUniform1i(g_text_location, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, text);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	glBindVertexArray(0);
	glUseProgram(0);
}
