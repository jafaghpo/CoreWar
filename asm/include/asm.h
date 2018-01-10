/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:38:13 by iburel            #+#    #+#             */
/*   Updated: 2018/01/10 21:14:16 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <ncurses.h>
# include <errno.h>
# include "libft.h"
# include "op.h"
# include "eval_expr.h"

# define ERROR_USAGE			"usage: ./asm [-wv] file ...\n"
# define ERROR_EXTENSION		"%s: invalid file extension"
# define ERROR_OPTION			"illegal option -- %c"
# define ERROR_OPEN				"%s: %s"
# define ERROR_NAME				"missing champion name"
# define ERROR_COM				"missing champion comment"
# define ERROR_NAME_SYNTAX		"invalid syntax in champion name"
# define ERROR_COM_SYNTAX		"invalid syntax in champion comment"
# define ERROR_HEADER_LINE		"invalid line in champion header"

# define WARNING_FLAG			0x01
# define VISUAL_FLAG			0x02
# define TAB_SIZE				1000
# define NAME_LEN				PROG_NAME_LENGTH
# define COM_LEN				COMMENT_LENGTH

typedef uint8_t			t_uint8;
typedef struct s_tab	t_tab;
typedef struct s_buf	t_buf;
typedef struct s_tmplb	t_tmplb;
typedef struct s_lstlb	t_lstlb;
typedef struct s_label	t_label;

struct		s_tab
{
	char	*line;
	t_uint8	*ptr;
	int		size;
	int		new_line;
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

/*
**	-- Global variables --
*/
extern	int		g_lines;
extern	int		g_option;
extern	t_buf	g_bin;
extern	t_op	g_op[17];
/*
**	-- Common --
*/
int			print_error(int usage, const char *msg, ...);
char		*get_name(char *file);
int			fill_binary(char *name);
int			word_equal(char *s1, char *s2);
/*
**	-- Parsing --
*/
int			parse_file(char *name);
int			get_header(t_tab *tab, int fd);
int			get_instructions(t_tab *tab, t_label *label, int fd);
int			store_line(t_tab *tab, t_tab *current);
/*
**	-- Labels --
*/
int			check_labels(t_label *label);
/*
**	-- Visual --
*/
void		run_visual(t_tab *tab);

#endif
