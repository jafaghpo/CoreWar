/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:02:16 by iburel            #+#    #+#             */
/*   Updated: 2018/02/03 13:52:05 by iburel           ###   ########.fr       */
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
    char    str[50];
    int     i;
    int     j;

    if (!(buf = malloc((WIN_X * 6 / 20) * WIN_Y * 4)))
        return (NULL);
    i = 0;
    while (i < WIN_Y)
    {
        j = 0;
        while (j < (WIN_X * 6 / 20))
        {
            buf[i * (WIN_X * 6 / 20) * 4 + j * 4 + 0] = ((Uint8 *)image->pixels)[i * image->h / WIN_Y * image->w * image->format->BytesPerPixel + j * image->w / (WIN_X * 6 / 20) * image->format->BytesPerPixel + 2];
            buf[i * (WIN_X * 6 / 20) * 4 + j * 4 + 1] = ((Uint8 *)image->pixels)[i * image->h / WIN_Y * image->w * image->format->BytesPerPixel + j * image->w / (WIN_X * 6 / 20) * image->format->BytesPerPixel + 1];
            buf[i * (WIN_X * 6 / 20) * 4 + j * 4 + 2] = ((Uint8 *)image->pixels)[i * image->h / WIN_Y * image->w * image->format->BytesPerPixel + j * image->w / (WIN_X * 6 / 20) * image->format->BytesPerPixel + 0];
            if (image->format->BytesPerPixel == 4)
                buf[i * (WIN_X * 6 / 20) * 4 + j * 4 + 3] = ((Uint8 *)image->pixels)[i * image->h / WIN_Y * image->w * image->format->BytesPerPixel + j * image->w / (WIN_X * 6 / 20) * image->format->BytesPerPixel + 3];
            else
                buf[i * (WIN_X * 6 / 20) * 4 + j * 4 + 3] = 0xff;
            j++;
        }
        i++;
    }
    add_text(buf, "FPS:", 570, 51, &g_theme.color_fps);
    add_text(buf, "CYCLE:", 60, 195, &g_theme.color_fps);
    add_text(buf, "CYCLE/S:", 400, 195, &g_theme.color_fps);
    i = 0;
    while (i < (int)g_nb_player)
    {
        ft_sprintf(str, "player%d : %.30s", i + 1, g_champs[i + 1].name);
        add_text(buf, str, 100, 300 + 40 * i, &g_theme.color_players[i % 4]);
        i++;
    }
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
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WIN_X * 6 / 20, WIN_Y, 0, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    SDL_FreeSurface(image);
    free(buf);
    return (id);
}