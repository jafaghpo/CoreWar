/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_gl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:10:16 by iburel            #+#    #+#             */
/*   Updated: 2018/02/12 14:47:15 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void puterror(GLuint program)
{
	char	*error_str;
	GLint	size;

	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &size);
	if (!(error_str = malloc(size + 1)))
		ft_afferror(ERROR_MALLOC);
	glGetShaderInfoLog(program, size, &size, error_str);
	error_str[size] = 0;
	ft_printf("%s\n", error_str);
	free(error_str);
	glDeleteProgram(program);
	exit(0);
}

static void load_shaders(t_glenv *glenv, char *vert, char *frag)
{
	GLuint	vertex;
	GLuint	fragment
	GLint	error;

	if (!(shader_build(&vertex, GL_VERTEX_SHADER, vert)))
		ft_afferror(ERROR_SHADER_BUILD);
	if (!(shader_build(&fragment, GL_FRAGMENT_SHADER, frag)))
		ft_afferror(ERROR_SHADER_BUILD);
	glenv->program = glCreateProgram();
	glAttachShader(glenv->program, vertex);
	glAttachShader(glenv->program, fragment);
	glBindAttribLocation(glenv->program, 0, "in_Vertex");
	glBindAttribLocation(glenv->program, 1, "in_Color");
	glBindAttribLocation(glenv->program, 2, "in_Texture");
	glLinkProgram(glenv->program);
	glGetProgramiv(glenv->program, GL_LINK_STATUS, &error);
	if (!error)
		puterror(glenv->program);
}

static void load_vram(GLuint *vbo, GLuint *vao)
{
	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) + sizeof(colors) + sizeof(coord_text), 0, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertex), vertex);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertex), sizeof(colors), colors);
	//		glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertex) + sizeof(colors), sizeof(coord_text), coord_text);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenVertexArrays(1, vao);
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, *vbo);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid *)sizeof(vertex));
	glEnableVertexAttribArray(1);
	//			glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid *)(sizeof(vertex) + sizeof(colors)));
	//			glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void		load_gl(t_glenv *glenv, char *vert, char *frag)
{
	t_glenv		glenv;

	if (!(SDL_GL_CreateContext(win)))
		ft_afferror(ERROR_CREAT_CONTEXT);
	glEnable(GL_DEPTH_TEST);
	load_shaders(&glenv, vert, frag);
	load_vram(&glenv->vbo, &glenv->vao);
}
