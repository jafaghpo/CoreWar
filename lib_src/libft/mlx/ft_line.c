/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 15:55:25 by iburel            #+#    #+#             */
/*   Updated: 2017/06/28 15:55:59 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_dx(t_image *img, t_line *l, t_point2d d, t_uint color)
{
	int		xincr;
	int		yincr;
	int		error;
	int		i;

	xincr = l->a.x < l->b.x ? 1 : -1;
	yincr = l->a.y < l->b.y ? 1 : -1;
	error = d.x / 2;
	i = 0;
	while (i <= d.x)
	{
		ft_putpixel(img, l->a.x, l->a.y, color);
		l->a.x += xincr;
		error += d.y;
		if (error > d.x)
		{
			error -= d.x;
			l->a.y += yincr;
		}
		i++;
	}
}

static void	ft_dy(t_image *img, t_line *l, t_point2d d, t_uint color)
{
	int		xincr;
	int		yincr;
	int		error;
	int		i;

	xincr = l->a.x < l->b.x ? 1 : -1;
	yincr = l->a.y < l->b.y ? 1 : -1;
	error = d.x / 2;
	i = 0;
	while (i <= d.y)
	{
		ft_putpixel(img, l->a.x, l->a.y, color);
		l->a.y += yincr;
		error += d.x;
		if (error > d.y)
		{
			error -= d.y;
			l->a.x += xincr;
		}
		i++;
	}
}

void		ft_line(t_image *img, t_line l, t_uint color)
{
	t_point2d	d;

	d.x = abs(l.b.x - l.a.x);
	d.y = abs(l.b.y - l.a.y);
	if (d.x > d.y)
		ft_dx(img, &l, d, color);
	else
		ft_dy(img, &l, d, color);
}
