/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_onebyte_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 01:55:00 by iburel            #+#    #+#             */
/*   Updated: 2018/01/27 02:29:38 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static int  check_format(SDL_Surface *image, GLenum *form, GLenum *form_int)
{
    if (image->format->BytesPerPixel == 3)
    {
        *form_int = GL_RGB;
        if (image->format->Rmask == 0xff)
            *form = GL_RGB;
        else
            *form = GL_BGR;
    } 
    else if (image->format->BytesPerPixel == 4)
    {
        *form_int = GL_RGBA;
        if (image->format->Rmask == 0xff)
            *form = GL_RGBA;
        else
            *form = GL_BGRA;
    }
    else
    {
        ft_printf(ERROR_BAD_FORMAT"\n");
        return (0);
    }
    return (1);
}

GLuint      load_onebyte_image(char *file)
{
    SDL_Surface *image;
    GLenum      form_int;
    GLenum      form;
    GLuint      id;
    t_uint8     *buf;
    int         i;
    
    if (!(image = IMG_Load(file)))
    {
        ft_printf(ERROR_LOAD_IMAGE"\n");
        return (UINT_MAX);
    }
    if (!check_format(image, &form, &form_int))
        return (UINT_MAX);
    ft_printf("%d   %d\n", image->w, image->h);
    if (!(buf = malloc(image->w * image->h)))
        return (UINT_MAX);
    i = 0;
    while (i < image->w * image->h)
    {
        buf[i] = 0xff - ((t_uint8 *)image->pixels)[i * image->format->BytesPerPixel];
        i++;
    }
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, image->w, image->h, 0, GL_RED, GL_UNSIGNED_BYTE, buf);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    SDL_FreeSurface(image);
    return (id);
}