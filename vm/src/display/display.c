/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:51:33 by iburel            #+#    #+#             */
/*   Updated: 2018/01/29 17:57:36 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	*display(void)
{
	t_sdl		sdl;
	t_gl		gl;
	t_mat4		projection;
	t_mat4		modelview;
	t_mat4		all_trans;
	int			done;
	GLuint		hud;
	GLuint		police_text[16];
	GLuint		fond;
	GLuint		image_load;
	GLuint		case_texture;
	GLint		model_location;
	GLint		proj_location;
	Uint32		i;
	Uint32		nb_frames;
	Uint32		fps;
	int			put_fps = 60;
	Uint32		tmp;
	int			right_mouse = 0;
	int			left_mouse = 0;
	t_case		*color;
	float		cursor;
	float		new;

	if (!init_sdl(&sdl))
		return (NULL);
	if (!init_gl(&gl))
		return (NULL);
	if (!init_load_screen())
		return (NULL);
	if (!init_square_texture())
		return (NULL);
	if ((image_load = load_image("texture/load.jpg")) == UINT_MAX)
		return (NULL);
	display_square((t_vec2){-1.f, -1.f}, (t_vec2){2.f, 2.f}, image_load);
	SDL_GL_SwapWindow(sdl.win);
	if (!(init_freetype()))
		return (NULL);
	load_numbers(police_text);
	if ((fond = load_image(g_theme.background_file)) == UINT_MAX)
		return (NULL);
	if ((hud = load_image(g_theme.hud_file)) == UINT_MAX)
		return (NULL);
	if ((case_texture = load_image(g_theme.case_texture)) == UINT_MAX)
		return (NULL);
	projection = mat4_unit();
	projection[0] = ((float)WIN_Y / (float)WIN_X);
	projection[5] = 1.f;
	projection[10] = 0.1f;
	projection[12] = -0.4f;
	modelview = mat4_unit();
	rotate(&modelview, norme(1.f, 0.f, 0.f), M_PI);
	model_location = glGetUniformLocation(gl.prog, "modelview");
	proj_location = glGetUniformLocation(gl.prog, "projection");
	done = 0;
	fps = 0;
	nb_frames = 0;
	GLint back_ground_location = glGetUniformLocation(gl.prog, "back_ground");
	GLint first_number_location = glGetUniformLocation(gl.prog, "first_number");
	GLint second_number_location = glGetUniformLocation(gl.prog, "second_number");
	GLint color_location = glGetUniformLocation(gl.prog, "color");
	i = 0;
	while (i < 16)
	{
		glActiveTexture(GL_TEXTURE0 + i + 1);
		glBindTexture(GL_TEXTURE_2D, police_text[i]);
		i++;
	}
	glUseProgram(gl.prog);
		glUniform1i(back_ground_location, 0);
	glUseProgram(0);
	while (!done)
	{
		sdl.time_start = SDL_GetTicks();
		while (SDL_PollEvent(&sdl.event))
		{
			if (sdl.event.type == SDL_QUIT)
				done = 1;
			else if (sdl.event.type == SDL_KEYDOWN)
			{
				if (sdl.event.key.keysym.sym == SDLK_ESCAPE)
					done = 1;
				else if (sdl.event.key.keysym.sym == SDLK_j)
					add_line_chat("t'as appuye sur J, t'es vraiment tres fort");
				else if (sdl.event.key.keysym.sym == SDLK_k)
					add_line_chat("t'as appuye sur K, t'es vraiment tres fort");
				g_key = sdl.event.key.keysym.sym;
				while (g_key)
					;
			}
			else if (sdl.event.type == SDL_MOUSEBUTTONDOWN)
			{
    			if (sdl.event.button.button == SDL_BUTTON_LEFT)
					left_mouse = 1;
    			else if (sdl.event.button.button == SDL_BUTTON_RIGHT)
					right_mouse = 1;
			}
			else if (sdl.event.type == SDL_MOUSEBUTTONUP)
			{
    			if (sdl.event.button.button == SDL_BUTTON_LEFT)
					left_mouse = 0;
    			else if (sdl.event.button.button == SDL_BUTTON_RIGHT)
					right_mouse = 0;
			}
			else if (sdl.event.type == SDL_MOUSEMOTION)
			{
				if (left_mouse)
        			rotate(&modelview, norme((float)sdl.event.motion.yrel, (float)sdl.event.motion.xrel, 0.f), (M_PI / 512.f) * sqrt(sdl.event.motion.yrel * sdl.event.motion.yrel + sdl.event.motion.xrel * sdl.event.motion.xrel));
				if (right_mouse)
        			translation(&projection, (t_vec3){(float)sdl.event.motion.xrel / (float)WIN_X, -(float)sdl.event.motion.yrel / (float)WIN_Y, 0.f});
			}
		}
		event(&projection, &modelview);

		display_square((t_vec2){-1.f, -1.f}, (t_vec2){2.f, 2.f}, fond);
		glUseProgram(gl.prog);
			glBindVertexArray(gl.vao);
				all_trans = mat4_mult(projection, modelview);
				glUniformMatrix4fv(model_location, 1, GL_FALSE, all_trans);
                glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, case_texture);
				free(all_trans);
				i = 0;
				while (i < MEM_SIZE)
				{
					color = &g_champs[g_infos[i].player].color;
					cursor = -0.2f * g_infos[i].cursor;
					new = 0.2f * g_infos[i].new;
					glUniform3f(color_location, color->r + cursor + new, color->g + cursor + new, color->b + cursor + new);
					glUniform1i(first_number_location, (g_mem[i] >> 4) + 1);
					glUniform1i(second_number_location, (g_mem[i] & 0x0f) + 1);
					glDrawArrays(GL_TRIANGLE_STRIP, i * 4, 4);
					i++;
				};
			glBindVertexArray(0);
		glUseProgram(0);
		display_square((t_vec2){0.4f, -1.f}, (t_vec2){0.6f, 2.f}, hud);
		put_chat();
		put_numbers();
		SDL_GL_SwapWindow(sdl.win);
		sdl.time_end = SDL_GetTicks();
		tmp = sdl.time_end - fps;
		if (tmp > 1000)
		{
			fps = sdl.time_end;
			put_fps = nb_frames;
			update_numbers(&put_fps);
			nb_frames = 0;
		}
//		if (sdl.time_end < sdl.time_start + (1000.f / 60.f))
//			SDL_Delay((1000.f / 60.f) - (sdl.time_end - sdl.time_start));
		nb_frames++;
	}
	return (NULL);
}
