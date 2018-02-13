/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:11:38 by iburel            #+#    #+#             */
/*   Updated: 2018/02/13 15:38:36 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

SDL_Surface		*get_alpha(SDL_Surface *image, Uint32 rgb)
{
	SDL_Surface *alpha;
	Uint32		*tmp1;
	Uint32		*tmp2;
	Uint32		size;
	Uint32		i;

	(void)rgb;
	if (!(alpha = SDL_CreateRGBSurface(0, image->w, image->h, 32, 0, 0, 0, 0)))
	{
		ft_printf(ERROR_CREAT_IMAGE"\n");
		return (NULL);
	}
	tmp1 = image->pixels;
	tmp2 = alpha->pixels;
	size = image->w * image->h;
	i = -1;
	while (++i < size)
	{
		if ((tmp1[i] & 0xffffff) == rgb)
			tmp2[i] = 0;
		else
			tmp2[i] = tmp1[i];
	}
	return (alpha);
}
