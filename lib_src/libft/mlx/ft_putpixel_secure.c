/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel_secure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:53:59 by iburel            #+#    #+#             */
/*   Updated: 2017/06/28 15:54:55 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpixel_secure(t_image *img, int x, int y, t_uint color)
{
	if (x >= 0 && x < img->w && y >= 0 && y < img->h)
		img->data[x + y * img->w] = color;
}
