/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:16:53 by iburel            #+#    #+#             */
/*   Updated: 2018/02/12 14:34:52 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static GLuint	g_prog;
static GLuint	g_vao;

static void	init_array(float *vertices, float *coord_text)
{
	int		i;

	i = 0;
	while (i < 8 * CHAT_SIZE)
	{
		vertices[i + 0] = 0.43f;
		vertices[i + 1] = -0.9f + (float)30 / (float)WIN_Y * (float)(i / 8 + 1);
		vertices[i + 2] = 0.43f + (float)(16 * CHAT_LINE_SIZE) / (float)WIN_Y;
		vertices[i + 3] = -0.9f + (float)30 / (float)WIN_Y * (float)(i / 8 + 1);
		vertices[i + 4] = 0.43f;
		vertices[i + 5] = -0.9f + (float)30 / (float)WIN_Y * (float)(i / 8);
		vertices[i + 6] = 0.43f + (float)(16 * CHAT_LINE_SIZE) / (float)WIN_Y;
		vertices[i + 7] = -0.9f + (float)30 / (float)WIN_Y * (float)(i / 8);
		coord_text[i + 0] = 0.f;
		coord_text[i + 1] = 0.f;
		coord_text[i + 2] = 1.f;
		coord_text[i + 3] = 0.f;
		coord_text[i + 4] = 0.f;
		coord_text[i + 5] = 1.f;
		coord_text[i + 6] = 1.f;
		coord_text[i + 7] = 1.f;
		i += 8;
	}
}

int			prog_chat(void)
{
	static float	vertices[8 * CHAT_SIZE];
	static float	coord_text[8 * CHAT_SIZE];
	GLuint			vbo;

	init_array(vertices, coord_text);
	if (!(g_prog = create_prog(VERTEX_CHAT, FRAGMENT_CHAT)))
		return (0);
	glUseProgram(g_prog);
	glUniform3f(glGetUniformLocation(g_prog, "color_font"), g_theme.color_chat.r, g_theme.color_chat.g, g_theme.color_chat.b);
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

void		put_chat(void)
{
	int		i;
	int		tmp;
	int		y;

	glUseProgram(g_prog);
	glBindVertexArray(g_vao);
	tmp = g_line_chat;
	y = tmp;
	i = 0;
	while (i < CHAT_SIZE)
	{
		glActiveTexture(GL_TEXTURE0);
		if (g_chat[i] == 0)
		{
			glGenTextures(1, g_chat + i);
			glBindTexture(GL_TEXTURE_2D, g_chat[i]);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 16 * CHAT_LINE_SIZE, 30, 0, GL_RED, GL_UNSIGNED_BYTE, g_chat_buffer[i]);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBindTexture(GL_TEXTURE_2D, 0);
		}
		glBindTexture(GL_TEXTURE_2D, g_chat[i]);
		glDrawArrays(GL_TRIANGLE_STRIP, y * 4, 4);
		i++;
		y--;
		if (y == -1)
			y = CHAT_SIZE - 1;
	}
	glBindVertexArray(0);
	glUseProgram(0);
}
