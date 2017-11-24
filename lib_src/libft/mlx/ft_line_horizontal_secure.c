/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_vertical_secure.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:07:32 by iburel            #+#    #+#             */
/*   Updated: 2017/06/28 22:20:21 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_line_horizontal_secure(t_image *img, t_point2d a, int s, t_uint col)
{
	int		i;

	if (a.y < 0 || a.y >= img->h || a.x + s <= 0 || a.x >= img->w || s <= 0)
		return ;
	if (a.x < 0)
	{
		a.x = 0;
		s += a.x;
	}
	i = 0;
	while (i < s)
	{
		ft_putpixel(img, a.x + i, a.y, col);
		i++;
	}
}
