/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:11:26 by iburel            #+#    #+#             */
/*   Updated: 2017/06/28 14:10:42 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clear_image(t_image *img, t_uint color)
{
	int		i;
	int		size;

	size = img->w * img->h;
	i = 0;
	while (i < size)
	{
		img->data[i] = color;
		i++;
	}
}
