/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 17:50:56 by iburel            #+#    #+#             */
/*   Updated: 2018/01/09 23:46:43 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <OpenGL/gl3.h>
# include <CoreFoundation/CoreFoundation.h>
# define GL3_PROTOTYPE 1
# include "op.h"
# include "libmat.h"
# include "libft.h"
# include <limits.h>
# include <ft2build.h>
# include FT_FREETYPE_H

typedef unsigned char t_uchar;
typedef unsigned int  t_uint;

# define ERROR_INIT_SDL         "error: initialisation of sdl failed"
# define ERROR_CREAT_WIN        "error: creation of the window failed"
# define ERROR_CREAT_CONTEXT_GL "error: creation of the context gl failed"
# define ERROR_MALLOC           "error: malloc failed"
# define ERROR_OPEN             "error: open failed"
# define ERROR_READ             "error: read failed"
# define ERROR_TYPE_SHADER      "error: bad type shader"
# define ERROR_BAD_FORMAT       "error: bad format for the image"
# define ERROR_LOAD_IMAGE       "error: load image failed"
# define ERROR_CREAT_IMAGE      "error: creation of the image failed"
# define ERROR_INIT_FREETYPE    "error: initialisation of freetype failed"
# define ERROR_INIT_FONT        "error: initialisation of the font failed"

# define WIN_X  1920
# define WIN_Y  1080

# define VERTEX_DISPLAY         "shader/display.vert"
# define FRAGMENT_DISPLAY       "shader/display.frag"
# define VERTEX_LOAD            "shader/load.vert"
# define FRAGMENT_LOAD			"shader/load.frag"
# define VERTEX_SQUARE          "shader/square.vert"
# define FRAGMENT_SQUARE        "shader/square.frag"
# define VERTEX_TEXT            "shader/text.vert"
# define FRAGMENT_TEXT          "shader/text.frag"

# define CHAT_SIZE				100
# define CHAT_LINE_SIZE			100
# define POLICE_SIZE            16

typedef struct s_case   t_case;

struct s_case
{
    float   r;
    float   g;
    float   b;
};

extern Uint8    g_mem[MEM_SIZE];
extern char     g_chat[CHAT_SIZE][CHAT_LINE_SIZE];
extern Uint8    g_line_chat;
extern t_uint32 g_pause;
extern t_uint32 g_key;
extern float    g_sleep;
extern t_case   g_color[MEM_SIZE];

typedef struct s_sdl    t_sdl;
typedef struct s_gl     t_gl;


struct s_sdl
{
    SDL_GLContext   glc;
    SDL_Window      *win;
    SDL_Event       event;
    Uint32          time_start;
    Uint32          time_end;
};

struct s_gl
{
    GLuint  vbo;
    GLuint  vao;
    t_mat4  projection;
    t_mat4  modelview;
    GLuint  prog;
};

int             init_sdl(t_sdl *sdl);
int             init_gl(t_gl *gl);
int             shader_build(GLuint *shader, GLenum type, char *file);
GLuint          load_image(char *file);
int             load_police_text(GLuint *police_text, SDL_Window *win);
SDL_Surface		*get_alpha(SDL_Surface *image, Uint32 rgb);
void            event(t_mat4 *projection, t_mat4 *modelview);
GLuint			create_prog(char *vertex_shader, char *fragment_shader);
int             init_load_screen(void);
void            display_load(SDL_Window *win, float per);
int             init_square_texture(void);
void            display_square(t_vec2 offset, t_vec2 size, GLuint text);
void            *display(void);
int		        init_freetype(GLuint *police_text);
void            put_text(char *str, float x, float y);
void            put_chat(void);
void            add_line_chat(char *str);

#endif
