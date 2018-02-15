/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:50:56 by iburel            #+#    #+#             */
/*   Updated: 2018/02/15 18:38:10 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <SDL2/SDL.h>
# include <OpenGL/gl3.h>
# include <CoreFoundation/CoreFoundation.h>
# define GL3_PROTOTYPE 1
# include "op.h"
# include "libmat.h"
# include "libft.h"
# include <limits.h>
# include <ft2build.h>
# include FT_FREETYPE_H
# include <SDL2/SDL_image.h>

# define ERROR_INIT_SDL			"error: initialisation of sdl failed"
# define ERROR_CREAT_WIN		"error: creation of the window failed"
# define ERROR_CREAT_CONTEXT_GL	"error: creation of the context gl failed"
# define ERROR_MALLOC			"error: malloc failed"
# define ERROR_OPEN				"error: open failed"
# define ERROR_READ				"error: read failed"
# define ERROR_TYPE_SHADER		"error: bad type shader"
# define ERROR_BAD_FORMAT		"error: bad format for the image"
# define ERROR_LOAD_IMAGE		"error: load image failed"
# define ERROR_CREAT_IMAGE		"error: creation of the image failed"
# define ERROR_INIT_FREETYPE	"error: initialisation of freetype failed"
# define ERROR_INIT_FONT		"error: initialisation of the font failed"

# define WIN_X					2560
# define WIN_Y					1440

# define VERTEX_DISPLAY			PATH"/shader/display.vert"
# define FRAGMENT_DISPLAY		PATH"/shader/display.frag"
# define VERTEX_LOAD			PATH"/shader/load.vert"
# define FRAGMENT_LOAD			PATH"/shader/load.frag"
# define VERTEX_SQUARE			PATH"/shader/square.vert"
# define FRAGMENT_SQUARE		PATH"/shader/square.frag"
# define VERTEX_TEXT			PATH"/shader/text.vert"
# define FRAGMENT_TEXT			PATH"/shader/text.frag"
# define VERTEX_CHAT			PATH"/shader/chat.vert"
# define FRAGMENT_CHAT			PATH"/shader/chat.frag"
# define VERTEX_NUMBERS			PATH"/shader/numbers.vert"
# define FRAGMENT_NUMBERS		PATH"/shader/numbers.frag"

# define CHAT_SIZE				50
# define CHAT_LINE_SIZE			100
# define POLICE_SIZE			16

typedef struct s_case	t_case;
typedef struct s_infos	t_infos;
typedef struct s_champ	t_champ;
typedef struct s_theme	t_theme;
typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;
typedef struct s_sdl	t_sdl;
typedef struct s_gl		t_gl;
typedef struct s_text	t_text;
typedef struct s_loc	t_loc;
typedef struct s_mats	t_mats;

struct			s_case
{
	float	r;
	float	g;
	float	b;
};

struct			s_infos
{
	t_int32	player;
	t_uint8	cursor : 1;
	t_uint8	new : 1;
};

struct			s_champ
{
	char		*name;
	t_uint32	id;
	t_uint32	number;
	t_uint32	live;
	t_case		color;
};

struct			s_sdl
{
	SDL_GLContext	glc;
	SDL_Window		*win;
	Uint32			frames;
	int				mouse[2];
};

struct			s_gl
{
	GLuint	vbo;
	GLuint	vao;
	t_mat4	projection;
	t_mat4	modelview;
	GLuint	prog;
};

struct			s_theme
{
	char	*background_file;
	char	*hud_file;
	char	*hud_background_file;
	char	*case_texture;
	char	*music_file;
	char	*police_file;
	t_case	color_empty;
	t_case	color_players[4];
	t_case	color_numbers;
	t_case	color_texture;
	t_case	color_chat;
	t_case	color_fps;
};

struct			s_text
{
	GLuint	hex_numbers[16];
	GLuint	background;
	GLuint	hud_background;
	GLuint	hud;
	GLuint	case_texture;
};

struct			s_loc
{
	GLint	model;
	GLint	first_number;
	GLint	second_number;
	GLint	color;
};

struct			s_mats
{
	t_mat4	projection;
	t_mat4	modelview;
	t_mat4	all;
};

extern Uint8	g_mem[MEM_SIZE];
extern GLuint	g_chat[CHAT_SIZE];
extern Uint8	g_line_chat;
extern Uint8	g_chat_buffer[128][30][16 * CHAT_LINE_SIZE];
extern t_uint32	g_pause;
extern t_uint32	g_key;
extern float	g_sleep;
extern t_infos	g_infos[MEM_SIZE];
extern Uint8	g_font[128][30][16];
extern int		g_font_size[128];
extern t_champ	*g_champs;
extern t_theme	g_theme;
extern t_uint32	g_nb_cycle;
extern t_uint32	g_nb_player;

int				init_sdl(t_sdl *sdl);
int				init_gl(t_gl *gl);
int				shader_build(GLuint *shader, GLenum type, char *file);
GLuint			load_image(char *file);
GLuint			load_hud(char *file);
GLuint			load_onebyte_image(char *file);
int				load_police_text(GLuint *police_text, SDL_Window *win);
SDL_Surface		*get_alpha(SDL_Surface *image, Uint32 rgb);
void			event(t_mat4 *projection, t_mat4 *modelview);
GLuint			create_prog(char *vertex_shader, char *fragment_shader);
int				init_load_screen(void);
void			display_load(SDL_Window *win, float per);
int				init_square_texture(void);
void			display_square(t_vec2 offset, t_vec2 size, GLuint text);
void			*display(void);
int				init_freetype(void);
void			put_text(char *str, float x, float y);
void			put_chat(void);
void			add_line_chat(char *str);
void			load_numbers(GLuint *police_text);
int				prog_chat(void);
int				prog_numbers(void);
void			put_numbers(void);
void			add_text(Uint8 *buf, char *str, int x, int y, t_case *color);
void			start_music(void);
void			update_number(int number, int size_max, int i);
void			init_numbers_coord_text(float *coord_text);
void			init_numbers_vertices(float *vertices);
int				init_libs(t_sdl *sdl, t_gl *gl);
int				load_textures(t_text *text);
void			init_matrix(t_mat4 *projection, t_mat4 *modelview);
void			init_location(t_loc *location, GLuint prog);
int				check_events(t_mats *mats, int *mouse);
void			init_active_texture(t_text *text);

#endif
