/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:49:53 by iburel            #+#    #+#             */
/*   Updated: 2018/02/14 16:35:30 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int		init_libs(t_sdl *sdl, t_gl *gl)
{
	start_music();
	if (!init_sdl(sdl))
		return (0);
	if (!init_gl(gl))
		return (0);
	if (!init_load_screen())
		return (0);
	if (!init_square_texture())
		return (0);
	if (!(init_freetype()))
		return (0);
	return (1);
}

int		load_textures(t_text *text)
{
	load_numbers(text->hex_numbers);
	if ((text->background = load_image(g_theme.background_file)) == UINT_MAX)
		return (0);
	if ((text->hud_background =
		load_image(g_theme.hud_background_file)) == UINT_MAX)
		return (0);
	if ((text->hud = load_hud(g_theme.hud_file)) == UINT_MAX)
		return (0);
	if ((text->case_texture = load_image(g_theme.case_texture)) == UINT_MAX)
		return (0);
	return (1);
}

void	init_matrix(t_mat4 *projection, t_mat4 *modelview)
{
	*projection = mat4_unit();
	(*projection)[0] = ((float)WIN_Y / (float)WIN_X);
	(*projection)[5] = 1.f;
	(*projection)[10] = 0.1f;
	(*projection)[12] = -0.4f;
	*modelview = mat4_unit();
	rotate(modelview, norme(1.f, 0.f, 0.f), M_PI);
}

void	init_location(t_loc *location, GLuint prog)
{
	location->model = glGetUniformLocation(prog, "modelview");
	location->first_number = glGetUniformLocation(prog, "first_number");
	location->second_number = glGetUniformLocation(prog, "second_number");
	location->color = glGetUniformLocation(prog, "color");
}

void	init_active_texture(t_text *text)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		glActiveTexture(GL_TEXTURE0 + i + 1);
		glBindTexture(GL_TEXTURE_2D, text->hex_numbers[i]);
		i++;
	}
}
