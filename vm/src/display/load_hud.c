/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:02:16 by iburel            #+#    #+#             */
/*   Updated: 2018/02/18 18:21:11 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#define WINX WIN_X
#define WINY WIN_Y

static int		check_format(SDL_Surface *image, GLenum *form, GLenum *form_int)
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
		ft_dprintf(2, ERROR_BAD_FORMAT"\n");
		return (0);
	}
	return (1);
}

static void		fill_buff(SDL_Surface *image, Uint8 *buf, int i, int j)
{
	buf[i * (WINX * 6 / 20) * 4 + j * 4 + 0] =
		((Uint8 *)image->pixels)[i * image->h / WINY * image->w *
		image->format->BytesPerPixel + j *
		image->w / (WINX * 6 / 20) * image->format->BytesPerPixel + 2];
	buf[i * (WINX * 6 / 20) * 4 + j * 4 + 1] =
		((Uint8 *)image->pixels)[i * image->h / WINY * image->w *
		image->format->BytesPerPixel + j * image->w / (WINX * 6 / 20) *
		image->format->BytesPerPixel + 1];
	buf[i * (WINX * 6 / 20) * 4 + j * 4 + 2] =
		((Uint8 *)image->pixels)[i * image->h / WINY * image->w *
		image->format->BytesPerPixel + j * image->w / (WINX * 6 / 20) *
		image->format->BytesPerPixel + 0];
	if (image->format->BytesPerPixel == 4)
		buf[i * (WINX * 6 / 20) * 4 + j * 4 + 3] =
			((Uint8 *)image->pixels)[i * image->h / WINY * image->w *
			image->format->BytesPerPixel + j * image->w /
			(WINX * 6 / 20) * image->format->BytesPerPixel + 3];
	else
		buf[i * (WINX * 6 / 20) * 4 + j * 4 + 3] = 0xff;
}

static Uint8	*add_infos(SDL_Surface *image)
{
	Uint8	*buf;
	char	str[50];
	int		i;
	int		j;

	if (!(buf = malloc((WINX * 6 / 20) * WINY * 4)))
		return (NULL);
	i = -1;
	while (++i < WINY)
	{
		j = -1;
		while (++j < (WINX * 6 / 20))
			fill_buff(image, buf, i, j);
	}
	add_text(buf, "FPS:", (t_ivec2){570, 51}, &g_theme.color_fps);
	add_text(buf, "CYCLE:", (t_ivec2){60, 195}, &g_theme.color_fps);
	add_text(buf, "CYCLE/S:", (t_ivec2){400, 195}, &g_theme.color_fps);
	i = -1;
	while (++i < (int)g_nb_player)
	{
		ft_sprintf(str, "player%d : %.30s", i + 1, g_champs[i + 1].name);
		add_text(buf, str, (t_ivec2){100, 300 + 40 * i},
			&g_theme.color_players[i % 4]);
	}
	return (buf);
}

GLuint			load_hud(char *file)
{
	SDL_Surface	*image;
	Uint8		*buf;
	GLenum		form_int;
	GLenum		form;
	GLuint		id;

	if (!(image = IMG_Load(file)))
	{
		ft_dprintf(2, ERROR_LOAD_IMAGE" : %s\n", file);
		return (UINT_MAX);
	}
	if (!check_format(image, &form, &form_int))
		return (UINT_MAX);
	if (!(buf = add_infos(image)))
		return (UINT_MAX);
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WINX * 6 / 20, WINY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, buf);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	SDL_FreeSurface(image);
	free(buf);
	return (id);
}

#undef WINX
#undef WINY
