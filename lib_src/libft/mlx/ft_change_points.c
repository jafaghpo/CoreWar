/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:47:06 by iburel            #+#    #+#             */
/*   Updated: 2017/06/28 15:49:10 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_left(t_line *l, t_cart *k, int h)
{
	int		tmp;

	tmp = k->c / k->b * -1;
	if (tmp >= 0 && tmp < h)
	{
		if (l->a.x < 0)
		{
			l->a.x = 0;
			l->a.y = tmp;
		}
		else
		{
			l->b.x = 0;
			l->b.y = tmp;
		}
		return (1);
	}
	return (0);
}

static int	ft_up(t_line *l, t_cart *k, int w)
{
	int		tmp;

	tmp = k->c / k->a * -1;
	if (tmp >= 0 && tmp < w)
	{
		if (l->a.y < 0)
		{
			l->a.y = 0;
			l->a.x = tmp;
		}
		else
		{
			l->b.y = 0;
			l->b.x = tmp;
		}
		return (1);
	}
	return (0);
}

static int	ft_right(t_line *l, t_cart *k, int h, int w)
{
	int		tmp;

	tmp = (k->c + k->a * w) / k->b * -1;
	if (tmp >= 0 && tmp < h)
	{
		if (l->a.x >= w)
		{
			l->a.x = w - 1;
			l->a.y = tmp;
		}
		else
		{
			l->b.x = w - 1;
			l->b.y = tmp;
		}
		return (1);
	}
	return (0);
}

static int	ft_down(t_line *l, t_cart *k, int w, int h)
{
	int		tmp;

	tmp = (k->c + k->b * h) / k->a * -1;
	if (tmp >= 0 && tmp < w)
	{
		if (l->a.y >= h)
		{
			l->a.y = h - 1;
			l->a.x = tmp;
		}
		else
		{
			l->b.y = h - 1;
			l->b.x = tmp;
		}
		return (1);
	}
	return (0);
}

int			ft_change_points(t_image *img, t_line *l)
{
	t_cart	k;
	int		count;

	if ((l->a.x < 0 && l->b.x < 0) || (l->a.x >= img->w && l->b.x >= img->w) ||
		(l->a.y < 0 && l->b.y < 0) || (l->a.y >= img->h && l->b.y >= img->h))
		return (0);
	count = 0;
	k.a = l->a.y - l->b.y;
	k.b = l->b.x - l->a.x;
	k.c = -k.a * l->a.x - k.b * l->b.x;
	if (l->a.x < 0 || l->b.x < 0)
		count += ft_left(l, &k, img->h);
	if (l->a.y < 0 || l->b.y < 0)
		if ((count += ft_up(l, &k, img->w)) == 2)
			return (1);
	if (l->a.x >= img->w || l->b.x >= img->w)
		if ((count += ft_right(l, &k, img->h, img->w)) == 2)
			return (1);
	if (l->a.y >= img->h || l->b.y >= img->h)
		count += ft_down(l, &k, img->w, img->h);
	return (count);
}
