/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:00:37 by iburel            #+#    #+#             */
/*   Updated: 2018/02/18 18:21:20 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static int	check_format(SDL_Surface *image, GLenum *form, GLenum *form_int)
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

GLuint		load_image(char *file)
{
	SDL_Surface *image;
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
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, form_int, image->w, image->h,
		0, form, GL_UNSIGNED_BYTE, image->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	SDL_FreeSurface(image);
	return (id);
}
