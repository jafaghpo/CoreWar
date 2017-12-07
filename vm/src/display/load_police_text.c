/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_police_text.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:00:45 by iburel            #+#    #+#             */
/*   Updated: 2017/12/02 01:55:48 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int         load_police_text(GLuint *text, SDL_Window *win)
{
	static char chs[] = {"0123456789ABCDEF"};
	static char big_right[] = "texture/01.png";
	static char big_left[] = "texture/02.png";
	static char small_right[] = "texture/01.png";
	static char small_left[] = "texture/02.png";
	int         i;

	i = 0;
	while (i < 16)
	{
		big_right[8] = chs[i];
		big_left[8] = chs[i];
		small_right[8] = chs[i];
		small_left[8] = chs[i];
//		if (!(text[i] = load_image(big_right)))
//			return (0);
		display_load(win, 1.f / 64.f);
//		if (!(text[i + 16] = load_image(big_left)))
//			return (0);
		display_load(win, 1.f / 64.f);
		if (!(text[i + 32] = load_image(small_right)))
			return (0);
		display_load(win, 1.f / 64.f);
		if (!(text[i + 48] = load_image(small_left)))
			return (0);
		display_load(win, 1.f / 64.f);
		i++;
	}
	return (1);
}
