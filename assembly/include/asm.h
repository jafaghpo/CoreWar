/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:38:13 by iburel            #+#    #+#             */
/*   Updated: 2018/02/28 17:20:56 by jafaghpo         ###   ########.fr       */
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
# include "msg.h"

# define VISUAL_FLAG	0x01
# define SIZE_FLAG		0x02

# define TAB_SIZE		1000
# define BSIZE			1 << 16
# define ERROR_SIZE		1000
# define NAME_LEN		PROG_NAME_LENGTH
# define COM_LEN		COMMENT_LENGTH
# define HEADER_LEN		(NAME_LEN + COM_LEN + 16)

/*
**	-- Colors --
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

typedef unsigned char	t_uint8;
typedef struct s_tab	t_tab;
typedef struct s_buf	t_buf;
typedef struct s_tmplb	t_tmplb;
typedef struct s_lstlb	t_lstlb;
typedef struct s_label	t_label;
typedef struct s_inst	t_inst;
typedef struct s_visual	t_visual;
typedef struct s_error	t_error;

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

extern	int		g_lines;
extern	int		g_option;
extern	t_op	g_op[OP_NB];
extern	t_buf	g_bin;
extern	char	g_error[ERROR_SIZE];

void		debug_inst(t_inst *inst);
void		debug_label(t_lstlb *label);
void		debug_tmplb(t_tmplb *label);
void		debug_tab(t_tab *tab);

int			print_error(const char *msg, ...);
char		*get_name(char *file);
int			fill_binary(char *name);
void		get_options(char **av, t_visual *win, t_tab **tab);
void		reset_bin_buffer(void);

int			parse_file(char *name, t_visual *win, t_tab *tab);
int			get_header(t_tab *tab, t_file *file, t_visual *win);
int			get_inst(t_tab *tab, t_label *label, t_file *file, t_visual *win);
int			store_line(t_tab *tab, t_tab *current, t_visual *win);
int			parse_arguments(char *line, t_label *label, t_inst *inst);
void		store_argument(t_inst *inst, int n, int size);
int			get_opcode(char *line, int *op);
int			add_instruction(t_inst *inst);
void		get_next_arg(char **str);
int			word_equal(char *s1, char *s2);

int			valid_label(char *str);
int			check_labels(t_label *label);
t_lstlb		*add_label(t_lstlb *label, char *name, int size);
t_tmplb		*add_tmp_label(t_tmplb *label, t_tmplb tmp);
void		delete_label(t_label *label);

#endif
