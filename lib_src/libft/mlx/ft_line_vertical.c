/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_vertical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 21:53:33 by iburel            #+#    #+#             */
/*   Updated: 2017/06/28 22:06:51 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_line_vertical(t_image *img, t_point2d a, int size, t_uint color)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putpixel(img, a.x, a.y + i, color);
		i++;
	}
}
