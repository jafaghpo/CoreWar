/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:38:13 by iburel            #+#    #+#             */
/*   Updated: 2018/03/11 14:53:25 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "op.h"
# include "eval_expr.h"
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
**	-- Header flag masks --
*/
# define NAME_DONE			0x01
# define COMMENT_DONE		0x02
# define NEXT_LINE			0x04
# define ALL_DONE			0x08

/*
**	-- Flag masks --
*/
# define VISUAL_FLAG		0x01
# define SIZE_FLAG			0x02

/*
**	-- Length macros --
*/
# define BSIZE				1 << 16
# define ERROR_SIZE			4096
# define NAME_LEN			PROG_NAME_LENGTH
# define COM_LEN			COMMENT_LENGTH
# define HEADER_LEN			(NAME_LEN + COM_LEN + 16)

/*
**	-- Compilation messages --
*/

# define COMPILATION_START	"Compiling %s\n"
# define COMPILATION_END	"Compilation done in %s\n"

/*
**	-- Error messages --
*/
# define NO_PARAMETER		"missing parameters"
# define USAGE				"usage: %s [-wv] file ..."
# define EXTENSION			"invalid file extension: \"%s\""
# define OPTION				"illegal option -- %c"
# define UNKNOWN_FILE		"%s: %s"
# define NO_NAME			"missing name in champion header"
# define NO_COMMENT			"missing comment in champion header"
# define NO_HEADER			"missing header"
# define SYNTAX				"invalid syntax in header: \"%s\""
# define HEADER_LINE		"invalid line in champion header: \"%s\""
# define LABEL_SYNTAX		"invalid label syntax: \"%s\""
# define UNKNOWN_INST		"unknown instruction: \"%s\""
# define REGISTER_ARG		"invalid register: \"%s\""
# define DIRECT_ARG			"invalid direct argument: \"%s\""
# define INDIRECT_ARG		"invalid indirect argument: \"%s\""
# define ARG_NUMBER			"invalid number of argument: \"%s\""
# define NO_SEPARATOR		"missing separator: \"%s\""
# define UNDEF_LABEL		"undefined label: \"%s\""
# define DUPLICATE_LABEL	"duplicate label name: \"%s\""

/*
**	-- Size flag messages --
*/
# define PROG_SIZE_MSG		"Program size is \033[31m%d\033[0m bytes\n"
# define PROG_SIZE_WARNING	"%sWarning:%s too large size [max: %d bytes]\n"

/*
**	-- Typedefs --
*/
typedef unsigned char	t_uint8;
typedef struct s_tab	t_tab;
typedef struct s_buf	t_buf;
typedef struct s_tmplb	t_tmplb;
typedef struct s_lstlb	t_lstlb;
typedef struct s_label	t_label;
typedef struct s_inst	t_inst;
typedef struct s_visual	t_visual;

struct		s_tab
{
	char	*line;
	t_uint8	*ptr;
	int		size;
};

struct		s_buf
{
	t_uint8	*data;
	int		size;
	int		i;
};

struct		s_tmplb
{
	char	*name;
	int		cursor;
	int		size;
	int		rel;
	t_tmplb	*next;
};

struct		s_lstlb
{
	char	*name;
	int		addr;
	t_lstlb	*next;
};

struct		s_label
{
	t_tmplb	*tmp;
	t_lstlb	*lst;
};

struct		s_inst
{
	char	data[20];
	int		size;
	int		args;
};

struct		s_error
{
	char	data[ERROR_SIZE];
	va_list	ap;
};

/*
**	-- Global variables --
*/
extern	int		g_state;
extern	int		g_lines;
extern	int		g_option;
extern	t_op	g_op[OP_NB];
extern	t_buf	g_bin;
extern	char	g_error[ERROR_SIZE];

/*
**	-- General --
*/
int			print_error(const char *msg, ...);
char		*get_path(char *file);
int			fill_binary(char *name);
int			check_argv(char **av, t_visual *win, t_tab **tab);
void		reset_buffer(void);

/*
**	-- Parsing --
*/
int			parse_file(char *name, t_visual *win, t_tab *tab);
int			get_header(t_tab *tab, t_file *file, t_visual *win);
int			parse_name(char *line, t_file *file, t_tab *tab, t_visual *win);
int			parse_comment(char *line, t_file *file, t_tab *tab, t_visual *win);
int			check_syntax(t_uint8 *dest, char *line);
int			get_inst(t_tab *tab, t_label *label, t_file *file, t_visual *win);
int			store_line(t_tab *tab, t_tab *current, t_visual *win);
int			parse_arguments(char *line, t_label *label, t_inst *inst);
void		store_argument(t_inst *inst, int n, int size);
int			get_opcode(char *line, int *op);
int			add_instruction(t_inst *inst);
void		get_next_arg(char **str);
int			word_equal(char *s1, char *s2);

/*
**	-- Labels --
*/
int			valid_label(char *str);
int			check_labels(t_label *label);
t_lstlb		*add_label(t_lstlb *label, char *name, int size);
t_tmplb		*add_tmp_label(t_tmplb *label, t_tmplb tmp);
void		delete_label(t_label *label);

#endif
