/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disas.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 15:16:57 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 21:45:36 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISAS_H
# define DISAS_H

# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "op.h"
# include "visual.h"

/*
**	-- Colors --
*/
# define BLK 	"\x1B[30m"
# define RED 	"\x1B[31m"
# define GRN 	"\x1B[32m"
# define YEL 	"\x1B[33m"
# define BLU 	"\x1B[34m"
# define MAG 	"\x1B[35m"
# define CYN 	"\x1B[36m"
# define WHT 	"\x1B[37m"
# define RES 	"\x1B[0m"

/*
**	-- Flag masks --
*/
# define VISUAL_FLAG		0x01

/*
**	-- Length macros --
*/
# define ERROR_LEN			1000
# define LINE_LEN			100
# define MAGIC_LEN			4

/*
**	-- Error messages--
*/
# define NO_PARAMETER		"missing parameters"
# define USAGE				"usage: ./asm [-w] file ..."
# define OPTION				"illegal option -- %c"
# define BAD_EXTENSION		"invalid file extension: \"%s\""
# define UNKNOWN_FILE		"%s: %s"
# define BINARY_SIZE		"invalid size for binary file: over %d bytes"
# define EMPTY_FILE			"empty binary file"
# define MAGIC_NUMBER		"invalid magic number: %d [real = %d]"
# define PROG_SIZE			"invalid program size: %d [real = %d]"
# define ERROR_MSG			"Failed to compile %s"
# define COMPILATION_START	"Compiling %s\n"
# define COMPILATION_END	"Compilation done in %s\n"
# define UNKNOWN_INST		"invalid opcode %x at position %d in binary"
# define BAD_ARGUMENT		"invalid argument %.2X at position %d in binary"

/*
**	-- Typedefs --
*/
typedef struct s_buf	t_buf;
typedef struct s_tab	t_tab;
typedef struct s_visual	t_visual;

struct		s_buf
{
	t_uint8	*data;
	int		size;
	int		i;
};

struct		s_tab
{
	char	*line;
	int		pos;
	int		size;
};

/*
**	-- Global variables --
*/
extern int		g_lines;
extern int		g_option;
extern t_op		g_op[OP_NB];
extern t_buf	g_bin;
extern t_buf	g_asm;
extern char		g_error[ERROR_LEN];

/*
**	-- General --
*/
int			print_error(const char *msg, ...);
char		*get_path(char *file);
int			buf_to_file(char *path);
int			check_argv(char **av, t_visual *win, t_tab **tab);
void		reset_buffer(void);
char		*get_path(char *file);
char		*line_dup(t_uint8 *line, size_t n);

/*
**	-- Parsing --
*/
int			get_binary(char *path);
int			parse_binary(char *path, t_visual *win, t_tab *tab);
int			get_name(t_visual *win, t_tab *tab);
int			get_comment(t_visual *win, t_tab *tab);
int			get_inst(t_visual *win, t_tab *tab);
int			store_instruction(char *line, int opcode);
int			get_register(char *line, int size, int opcode);
int			get_direct(char *line, int size, int opcode);
int			get_indirect(char *line, int size, int opcode);

#endif
