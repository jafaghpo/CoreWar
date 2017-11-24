/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_horizontal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:16:48 by iburel            #+#    #+#             */
/*   Updated: 2017/06/28 22:18:53 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_line_horizontal(t_image *img, t_point2d a, int size, t_uint color)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putpixel(img, a.x + i, a.y, color);
		i++;
	}
}
