/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:38:13 by iburel            #+#    #+#             */
/*   Updated: 2018/01/06 17:40:46 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <ncurses.h>
# include <errno.h>
# include "libft.h"
# include "op.h"
# include "eval_expr.h"

# define ERROR_USAGE	"usage: ./asm [-wv] file ...\n"
# define ERROR_EXT		"%s: Invalid file extension\n"
# define ERROR_OPTION	"illegal option -- %c\n"
# define ERROR_DIR		"%s: %s\n"
# define ERROR_MEM		"%s for %s\n"

# define WARNING_FLAG	0x01
# define VISUAL_FLAG	0x02
# define BSIZE			10000

typedef uint8_t			t_uint8;
typedef struct s_tab	t_tab;
typedef struct s_buf	t_buf;
typedef struct s_tmplb	t_tmplb;
typedef struct s_lstlb	t_lstlb;
typedef struct s_label	t_label;

struct		s_tab
{
	char	*line;
	int		len;
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
/*
**	-- Parsing --
*/
int			parse_file(char *name);
int			tokenize_file(t_tab *tab, t_label *label, int fd);
int			tokenize_line(char *line, t_tab *cur, t_label *label);
int			store_bin_line(t_tab *tab, t_tab *current, int nb_lines);
/*
**	-- Labels --
*/
int			check_tmp_labels(t_label *label);
/*
**	-- Visual --
*/
void		run_visual(t_tab *tab);

#endif
