/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:01:27 by iburel            #+#    #+#             */
/*   Updated: 2018/03/10 16:51:56 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

#define WINX WIN_X

static void	fill_buf(Uint8 *buf, int c, t_ivec2 pos, t_case *color)
{
	buf[0] = (Uint8)((float)buf[0] *
		((float)(0xff - g_font[c][pos.y][pos.x]) / 255.f) + color->r *
		(float)g_font[c][pos.y][pos.x]);
	buf[1] = (Uint8)((float)buf[1] *
		((float)(0xff - g_font[c][pos.y][pos.x]) / 255.f) + color->g *
		(float)g_font[c][pos.y][pos.x]);
	buf[2] = (Uint8)((float)buf[2] *
		((float)(0xff - g_font[c][pos.y][pos.x]) / 255.f) + color->b *
		(float)g_font[c][pos.y][pos.x]);
}

static void	fill_trans(Uint8 *buf, int trans)
{
	if (trans >= 0xff)
		buf[3] = 0xff;
	else
		buf[3] = trans;
}

void		add_text(Uint8 *b, char *str, t_ivec2 v, t_case *color)
{
	int		offset;
	t_ivec2	p;
	int		t;

	if (v.y > WIN_Y - 900)
		return ;
	offset = 0;
	while (*str)
	{
		if (*str < 0 && ++str)
			continue ;
		p.y = -1;
		while (++p.y < 30)
		{
			p.x = -1;
			while (++p.x < 16)
			{
				t = ((p.y + v.y) * (WINX * 6 / 20) + v.x + offset + p.x) * 4;
				fill_buf(b + t, *str, p, color);
				fill_trans(b + t, b[t + 3] + g_font[(int)*str][p.y][p.x]);
			}
		}
		offset += g_font_size[(int)*str++];
	}
}

#undef WINX
