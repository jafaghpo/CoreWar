/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_onebyte_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 01:55:00 by iburel            #+#    #+#             */
/*   Updated: 2018/02/12 14:50:40 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

GLuint		load_onebyte_image(char *file)
{
	SDL_Surface	*image;
	GLuint		id;
	t_uint8		*buf;
	int			i;

	if (!(image = IMG_Load(file)))
	{
		ft_printf(ERROR_LOAD_IMAGE"\n");
		return (UINT_MAX);
	}
	ft_printf("%d   %d\n", image->w, image->h);
	ft_printf("%d\n", image->format->BytesPerPixel);
	if (!(buf = malloc(image->w * image->h * 10)))
		return (UINT_MAX);
	i = 0;
	while (i < image->w * image->h)
	{
		buf[i] = 0xff - ((t_uint8 *)image->pixels)[i * 4/*image->format->BytesPerPixel*/];
		i++;
	}
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, image->w, image->h, 0, GL_RED, GL_UNSIGNED_BYTE, buf);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	SDL_FreeSurface(image);
	return (id);
}
