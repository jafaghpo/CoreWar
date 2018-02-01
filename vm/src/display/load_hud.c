/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:02:16 by iburel            #+#    #+#             */
/*   Updated: 2018/02/01 23:26:20 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static int      check_format(SDL_Surface *image, GLenum *form, GLenum *form_int)
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

static Uint8    *add_infos(SDL_Surface *image)
{
    Uint8   *buf;
    int     i;
    int     size;

    size = image->w * image->h;
    if (!(buf = malloc(size * 4)))
        return (NULL);
    i = 0;
    while (i < size)
    {
        buf[i * 4 + 0] = ((Uint8 *)image->pixels)[i * image->format->BytesPerPixel + 2];
        buf[i * 4 + 1] = ((Uint8 *)image->pixels)[i * image->format->BytesPerPixel + 1];
        buf[i * 4 + 2] = ((Uint8 *)image->pixels)[i * image->format->BytesPerPixel + 0];
        if (image->format->BytesPerPixel == 4)
            buf[i * 4 + 3] = ((Uint8 *)image->pixels)[i * image->format->BytesPerPixel + 3];
        else
            buf[i * 4 + 3] = 0xff;
        i++;
    }
 //   add_text("CYCLE:", 100, 100);
    return (buf);
}

GLuint          load_hud(char *file)
{
    SDL_Surface *image;
    Uint8       *buf;
    GLenum      form_int;
    GLenum      form;
    GLuint      id;
    
    if (!(image = IMG_Load(file)))
    {
        ft_printf(ERROR_LOAD_IMAGE"\n");
        return (UINT_MAX);
    }
    if (!check_format(image, &form, &form_int))
        return (UINT_MAX);
    if (!(buf = add_infos(image)))
        return (UINT_MAX);
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image->w, image->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    SDL_FreeSurface(image);
    free(buf);
    return (id);
}