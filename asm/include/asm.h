/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:38:13 by iburel            #+#    #+#             */
/*   Updated: 2018/02/14 22:18:06 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

/*
**	-- Includes --
*/
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "op.h"
# include "eval_expr.h"
# include "visual.h"

/*
**	-- Error messages --
*/
# define NO_PARAMETER	"missing parameters\n%s"
# define USAGE			"usage: ./asm [-wv] file ..."
# define EXTENSION		"invalid file extension: \033[31m%s"
# define OPTION			"illegal option -- \033[31m%c\033[0m\n%s"
# define UNKNOWN_FILE	"\033[31m%s: \033[0m%s"
# define NO_NAME		"missing champion name"
# define NO_COMMENT		"missing champion comment"
# define SYNTAX			"invalid syntax: \033[31m\"%s\"\033[0m"
# define HEADER_LINE	"invalid line in champion header: \033[31m\"%s\"\033[0m"
# define LABEL_SYNTAX	"invalid label syntax: \033[31m\"%s\"\033[0m"
# define UNKNOWN_INST	"unknown instruction: \033[31m\"%s\"\033[0m"
# define REGISTER_ARG	"invalid register: \033[31m\"%s\"\033[0m"
# define DIRECT_ARG		"invalid direct argument: \033[31m\"%s\"\033[0m"
# define INDIRECT_ARG	"invalid indirect argument: \033[31m\"%s\"\033[0m"
# define ARG_NUMBER		"invalid number of argument: \033[31m\"%s\"\033[0m"
# define NO_SEPARATOR	"missing separator between args: \033[31m\"%s\"\033[0m"
# define UNDEF_LABEL	"undefined label: \033[31m\"%s\"\033[0m"
# define MAX_SIZE		"%sWarning:%s too large size [max: %d bytes]\n"

/*
**	-- Option masks --
*/
# define VISUAL_FLAG	0x01
# define SIZE_FLAG		0x02

/*
**	-- Length macros --
*/
# define TAB_SIZE		1000
# define NAME_LEN		PROG_NAME_LENGTH
# define COM_LEN		COMMENT_LENGTH
# define HEADER_LEN		(NAME_LEN + COM_LEN + 16)

/*
** -- Color --
*/
# define BLK "\x1B[30m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"
# define RES "\x1B[0m"
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
/*
**	-- Structures --
*/
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
/*
**	-- Global variables --
*/
extern	int		g_lines;
extern	int		g_option;
extern	t_buf	g_bin;
extern	t_op	g_op[17];
/*
**	-- Debug --
*/
void		debug_inst(t_inst *inst);
void		debug_label(t_label *label);
void		debug_tmplb(t_label *label);
void		debug_tab(t_tab *tab);
/*
**	-- General --
*/
int			print_error(const char *msg, ...);
int			free_error(void *elem);
char		*get_name(char *file);
int			fill_binary(char *name);
int			word_equal(char *s1, char *s2);
int			word_len(char *str);
/*
**	-- Parsing --
*/
int			parse_file(char *name, t_visual *win, t_tab *tab);
int			get_header(t_tab *tab, int fd, t_visual *win);
int			get_instructions(t_tab *tab, t_label *label, int fd, t_visual *win);
int			store_line(t_tab *tab, t_tab *current, t_visual *win);
int			parse_arguments(char *line, t_label *label, t_inst *inst);
void		store_argument(t_inst *inst, int n, int size);
int			get_opcode(char *line, int *op);
int			add_instruction(t_inst *inst);
int			get_next_arg(char **str);
/*
**	-- Labels --
*/
int			valid_label(char *str);
int			check_labels(t_label *label);
char		*duplicate_label(char *name, int size);
t_lstlb		*add_label(t_lstlb *label, char *name, int size);
t_tmplb		*add_tmp_label(t_tmplb *label, t_tmplb tmp);

#endif
