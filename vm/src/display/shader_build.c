/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 22:25:25 by iburel            #+#    #+#             */
/*   Updated: 2018/02/02 17:31:30 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static char *file_to_str(char *file)
{
    char    *buf;
    int     fd;
    int     ret;

    if (!(buf = malloc(sizeof(*buf) * BUFF_SIZE)))
    {
        ft_printf(ERROR_MALLOC"\n");
        return (NULL);
    }
    if ((fd = open(file, O_RDONLY)) == -1)
    {
        ft_printf(ERROR_OPEN"\n");
        return (NULL);
    }
    if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
    {
        ft_printf(ERROR_READ"\n");
        return (NULL);
    }
    if (ret == BUFF_SIZE)
        return (NULL);
    close(fd);
    buf[ret] = 0;
    return (buf);
}

static int  check_shader(GLuint shader)
{
    GLint   error;
    GLint   size;
    char    *str;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &error);
    if (!error)
    {
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &size);
        if (!(str = malloc(sizeof(*str) * (size + 1))))
        {
            ft_printf(ERROR_MALLOC"\n");
            return (0);
        }
        glGetShaderInfoLog(shader, size, &size, str);
        str[size] = 0;
        ft_printf("%s\n", str);
        free(str);
        return (0);
    }
    return (1);
}

int         shader_build(GLuint *shader, GLenum type, char *file)
{
    char    *buf;

    if (!(*shader = glCreateShader(type)))
    {
        ft_printf(ERROR_TYPE_SHADER"\n");
        return (0);
    }
    if (!(buf = file_to_str(file)))
        return (0);
    glShaderSource(*shader, 1, (const char **)&buf, 0);
    glCompileShader(*shader);
    free(buf);
    if (!check_shader(*shader))
        return (0);
    return (1);
}