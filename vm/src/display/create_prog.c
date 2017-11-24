/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 23:06:46 by iburel            #+#    #+#             */
/*   Updated: 2017/11/18 23:06:47 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static int	check_prog(GLuint prog)
{
    GLint   error;
    GLint   size;
    char    *str;

    glGetProgramiv(prog, GL_LINK_STATUS, &error);
    if (!error)
    {
        glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &size);
        if (!(str = malloc(sizeof(*str) * (size + 1))))
        {
            ft_printf(ERROR_MALLOC);
            return (0);
        }
        glGetShaderInfoLog(prog, size, &size, str);
        str[size] = 0;
        ft_printf("error: %s\n", str);
        free(str);
        glDeleteProgram(prog);
        return (0);
    }
    return (1);
}

GLuint		create_prog(char *vertex_shader, char *fragment_shader)
{
    GLuint  vert;
    GLuint  frag;
    GLuint  prog;

    if (!(shader_build(&vert, GL_VERTEX_SHADER, vertex_shader)))
        return (UINT_MAX);
    if (!(shader_build(&frag, GL_FRAGMENT_SHADER, fragment_shader)))
        return (UINT_MAX);
    prog = glCreateProgram();
    glAttachShader(prog, vert);
    glAttachShader(prog, frag);
    glBindAttribLocation(prog, 0, "in_Vertex");
    glBindAttribLocation(prog, 1, "in_Texture");
    glLinkProgram(prog);
    if (!check_prog(prog))
        return (UINT_MAX);
    return (prog);
}