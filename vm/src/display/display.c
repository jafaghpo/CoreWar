/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:51:33 by iburel            #+#    #+#             */
/*   Updated: 2018/03/10 15:19:07 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void	display_the_frame2(t_loc *location, t_text *text)
{
	float	cursor;
	t_case	*color;
	int		i;

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, text->case_texture);
	i = 0;
	while (i < MEM_SIZE)
	{
		color = &g_champs[g_infos[i].player].color;
		cursor = -0.2f * g_infos[i].cursor + 0.2f * g_infos[i].new;
		glUniform3f(location->color, color->r + cursor,
			color->g + cursor, color->b + cursor);
		glUniform1i(location->first_number, (g_mem[i] >> 4) + 1);
		glUniform1i(location->second_number, (g_mem[i] & 0x0f) + 1);
		glDrawArrays(GL_TRIANGLE_STRIP, i * 4, 4);
		i++;
	}
	glBindVertexArray(0);
	glUseProgram(0);
	display_square((t_vec2){0.4f, -1.f}, (t_vec2){0.6f, 2.f},
		text->hud_background);
	display_square((t_vec2){0.4f, -1.f}, (t_vec2){0.6f, 2.f}, text->hud);
	put_chat();
}

static void	display_the_frame(t_loc *l, t_text *text, t_mats *mats, t_gl *gl)
{
	event(&mats->projection, &mats->modelview);
	display_square((t_vec2){-1.f, -1.f}, (t_vec2){2.f, 2.f},
		text->background);
	glUseProgram(gl->prog);
	glBindVertexArray(gl->vao);
	mats->all = mat4_mult(mats->projection, mats->modelview);
	glUniformMatrix4fv(l->model, 1, GL_FALSE, mats->all);
	free(mats->all);
	display_the_frame2(l, text);
	update_number(g_nb_cycle, 7, 1);
	update_number((int)(1000000 / g_sleep), 5, 2);
	put_numbers();
}

static void	put_fps(t_sdl *sdl)
{
	static Uint32	save = 0;
	Uint32			the_time;

	the_time = SDL_GetTicks();
	if (the_time - save > 1000)
	{
		save = the_time;
		update_number(sdl->frames, 3, 0);
		sdl->frames = 0;
	}
}

void		*display(void)
{
	t_sdl	sdl;
	t_gl	gl;
	t_text	text;
	t_loc	location;
	t_mats	mats;

	if (!init_libs(&sdl, &gl))
		return (NULL);
	if (!load_textures(&text))
		return (NULL);
	init_matrix(&mats.projection, &mats.modelview);
	init_location(&location, gl.prog);
	init_active_texture(&text);
	while (1)
	{
		if (check_events(&mats, sdl.mouse))
			break ;
		display_the_frame(&location, &text, &mats, &gl);
		SDL_GL_SwapWindow(sdl.win);
		put_fps(&sdl);
		sdl.frames++;
	}
	return (NULL);
}
