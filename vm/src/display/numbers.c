/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 21:49:59 by iburel            #+#    #+#             */
/*   Updated: 2018/02/14 14:49:06 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static GLuint	g_prog;
static GLuint	g_vao;
static GLuint	g_text[3];

static int	init_uniform_and_vbo(GLuint vbo, float *vertices, float *coord)
{
	glGenTextures(3, g_text);
	if (!(g_prog = create_prog(VERTEX_NUMBERS, FRAGMENT_NUMBERS)))
		return (0);
	glUseProgram(g_prog);
	glUniform3f(glGetUniformLocation(g_prog, "color_font"),
		g_theme.color_fps.r, g_theme.color_fps.g, g_theme.color_fps.b);
	glUniform1i(glGetUniformLocation(g_prog, "text"), 0);
	glUseProgram(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 48, 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * 24, vertices);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * 24,
		sizeof(float) * 24, coord);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return (1);
}

int			prog_numbers(void)
{
	float	vertices[24];
	float	coord_text[24];
	GLuint	vbo;

	init_numbers_vertices(vertices);
	init_numbers_coord_text(coord_text);
	glGenBuffers(1, &vbo);
	if (!(init_uniform_and_vbo(vbo, vertices, coord_text)))
		return (0);
	glGenVertexArrays(1, &g_vao);
	glBindVertexArray(g_vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0,
		(GLvoid *)(sizeof(vertices)));
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	return (1);
}

void		put_numbers(void)
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

static int	init_update_number(int number, int *nb)
{
	int		div;

	*nb = 1;
	div = 1;
	while (div * 10 <= number)
	{
		div *= 10;
		(*nb)++;
	}
	return (div);
}

void		update_number(int number, int size_max, int j)
{
	Uint8	buf[17][16 * size_max];
	int		y;
	int		i;
	int		div;
	int		nb;

	ft_bzero(buf, sizeof(buf));
	div = init_update_number(number, &nb);
	i = size_max - nb - 1;
	while (++i < size_max)
	{
		y = -1;
		while (++y < 17)
			ft_memcpy(buf[y] + i * 16,
				g_font[number / div + '0'][y + 4], 16);
		number %= div;
		div /= 10;
	}
	glBindTexture(GL_TEXTURE_2D, g_text[j]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, 16 * size_max, 17, 0,
		GL_RED, GL_UNSIGNED_BYTE, buf);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	i++;
}
