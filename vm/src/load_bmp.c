/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:47:10 by iburel            #+#    #+#             */
/*   Updated: 2017/11/16 16:47:11 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

SDL_Surface     *load_bmp(char *file)
{
    SDL_Surface *image;
    int         fd;

    if ((fd = open(file, O_RDONLY)) == -1)
    {
        ft_printf(ERROR_OPEN"\n");
        return (NULL);
    }
    close(fd);
    return (image);
}