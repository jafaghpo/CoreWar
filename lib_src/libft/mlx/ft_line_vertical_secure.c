/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_vertical_secure.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:07:32 by iburel            #+#    #+#             */
/*   Updated: 2017/06/28 22:14:46 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_line_vertical_secure(t_image *img, t_point2d a, int s, t_uint color)
{
	int		i;

	if (a.x < 0 || a.x >= img->w || a.y + s <= 0 || a.y >= img->h || s <= 0)
		return ;
	if (a.y < 0)
	{
		a.y = 0;
		s += a.y;
	}
	i = 0;
	while (i < s)
	{
		ft_putpixel(img, a.x, a.y + i, color);
		i++;
	}
}
