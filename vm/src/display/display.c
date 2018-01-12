/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:51:33 by iburel            #+#    #+#             */
/*   Updated: 2018/01/12 15:19:43 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

t_uint8		g_line_chat = CHAT_SIZE - 1;
char		g_chat[CHAT_SIZE][CHAT_LINE_SIZE];

void	*display(void)
{
	t_sdl		sdl;
	t_gl		gl;
	t_mat4		projection;
	t_mat4		modelview;
	int			done;
	GLuint		hud;
	GLuint		police_text[64];
	GLuint		fond;
	GLuint		image_load;
	GLint		model_location;
	GLint		proj_location;
	Uint32		i;
	Uint32		nb_frames;
	Uint32		fps;
	char		put_fps[4] = "000";
	Uint32		tmp;

	if (!init_sdl(&sdl))
		return (NULL);
	if (!init_gl(&gl))
		return (NULL);
	if (!init_load_screen())
		return (NULL);
	if (!init_square_texture())
		return (NULL);
	if (!(init_freetype(police_text)))
		return (NULL);
	if ((image_load = load_image("texture/load.jpg")) == UINT_MAX)
		return (NULL);
	display_square((t_vec2){-1.f, -1.f}, (t_vec2){2.f, 2.f}, image_load);
	SDL_GL_SwapWindow(sdl.win);
	if ((fond = load_image("texture/fond.jpg")) == UINT_MAX)
		return (NULL);
	if ((hud = load_image("texture/blanc.jpg")) == UINT_MAX)
		return (NULL);
	projection = mat4_unit();
	projection[0] = ((float)WIN_Y / (float)WIN_X);
	projection[5] = 1.f;
	projection[10] = 1.f;
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
	GLint number_one[16];
	i = 0;
	while (i < 16)
	{
		number_one[i] = i + 1;
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
			if (sdl.event.window.event == SDL_WINDOWEVENT_CLOSE)
				done = 1;
			else if (sdl.event.key.keysym.sym == SDLK_ESCAPE && sdl.event.type == SDL_KEYDOWN)
				done = 1;
			else if (sdl.event.key.keysym.sym == SDLK_j)
				add_line_chat("t'as appuye sur J, t'es vraiment tres fort");
			if (sdl.event.key.type == SDL_KEYDOWN)
				g_key = sdl.event.key.keysym.sym;
			while (g_key)
				;
		}
		event(&projection, &modelview);

		display_square((t_vec2){-1.f, -1.f}, (t_vec2){2.f, 2.f}, fond);
		glUseProgram(gl.prog);
			glBindVertexArray(gl.vao);
				glUniformMatrix4fv(model_location, 1, GL_FALSE, modelview);
				glUniformMatrix4fv(proj_location, 1, GL_FALSE, projection);
				i = 0;
				while (i < MEM_SIZE)
				{
					glUniform3f(color_location, g_color[i].r, g_color[i].g, g_color[i].b);
					glUniform1i(first_number_location, (g_mem[i] >> 4) + 1);
					glUniform1i(second_number_location, (g_mem[i] & 0x0f) + 1);
					glDrawArrays(GL_TRIANGLE_STRIP, i * 4, 4);
					i++;
				};
			glBindVertexArray(0);
		glUseProgram(0);
		display_square((t_vec2){0.4f, -1.f}, (t_vec2){0.6f, 2.f}, hud);
		put_chat();
		put_text(put_fps, 0.9, 0.9);
		SDL_GL_SwapWindow(sdl.win);
		sdl.time_end = SDL_GetTicks();
		tmp = sdl.time_end - fps;
		if (tmp > 1000)
		{
			fps = sdl.time_end;
			put_fps[0] = nb_frames / 100 + '0';
			put_fps[1] = (nb_frames % 100) / 10 + '0';
			put_fps[2] = nb_frames % 10 + '0';
			nb_frames = 0;
		}
//		if (sdl.time_end < sdl.time_start + (1000.f / 60.f))
//			SDL_Delay((1000.f / 60.f) - (sdl.time_end - sdl.time_start));
		nb_frames++;
	}
	return (NULL);
}
