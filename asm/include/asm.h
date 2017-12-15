/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:38:13 by iburel            #+#    #+#             */
/*   Updated: 2017/12/15 18:38:43 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <ncurses.h>
# include "libft.h"
# include "op.h"
# include "ft_bc.h"

# define ERROR_OPEN_S				"error open s"
# define ERROR_OPEN_COR				"error open cor"
# define ERROR_MALLOC				"error malloc"
# define ERROR_READ					"error read"
# define ERROR_SYNTAX_LABEL			"error syntax label"
# define ERROR_SYNTAX_POINT			"error syntax command"
# define ERROR_INST					"error bad instruction"
# define ERROR_SYNTAX_REG			"error syntax register"
# define ERROR_SYNTAX_DIR			"error syntax direct"
# define ERROR_SYNTAX_IND			"error syntax indirect"
# define ERROR_REG_NUMBER			"error undefined register"
# define ERROR_BAD_LABEL			"error undefined label"
# define ERROR_SYNTAX_SEPARATOR		"error syntax bad separator"
# define ERROR_SYNTAX_NAME			"error syntax name"
# define ERROR_SYNTAX_COMMENT		"error syntax comment"
# define ERROR_NB_ARGS				"error nb args"
# define ERROR_BAD_TYPE_ARG			"error bad type arg"
# define ERROR_BAD_FORMAT			"error the file is not a .s"

typedef struct s_buf	t_buf;
typedef struct s_label	t_label;
typedef struct s_lstlb	t_lstlb;
typedef struct s_tmplb	t_tmplb;
typedef struct s_parse	t_parse;
typedef struct s_token	t_token;

struct	s_buf
{
	t_uchar	*buf;
	int		size;
	int		i;
};

struct	s_tmplb
{
	char	*name;
	int		cursor;
	int		size;
	int		rel;
	t_tmplb	*next;
};

struct	s_lstlb
{
	char	*name;
	int		addr;
	t_lstlb	*next;
};

struct	s_label
{
	t_tmplb	*tmp;
	t_lstlb	*lst;
};

struct	s_parse
{
	char	**ptr;
	int		*size;
	int		nb;
};

extern	t_op			g_optab[17];

/*
**	debug
*/
void		putparse(t_parse *parse);
void		putlabels(t_label *label);

/*
**	buff
*/
void		buff(char *str, int len);
void		buff_atcursor(int addr, int i, int len);
void		buff_header(header_t *header, int name_len, int comment_len);
void		buff_init(void);
int			buff_getcursor(void);
void		buff_put(int fd);
void		display_buff(void);

/*
**	label
*/
t_lstlb		*add_label(t_lstlb *label, char *name, int addr);
t_tmplb		*add_tmplb(t_tmplb *label, char *name, int cursor,
			int size, int rel);
int			check_label(char *str);
int			check_tmplb(t_label *labels);
int			get_label_addr(char *str, t_label *labels, t_token *token);
int			verif_tmp(t_tmplb *tmp);
int			labelcmp(char *labe1, char *label2);
char		*labeldup(char *label);

/*
**	parse
*/
int			split_spe(t_parse *parse, char *line);
int			fill_size(t_parse *parse);
int			wordlen(char *line);
int			arglen(char *str);

/*
**	resolve
*/
char		*get_name(char *file);
int			parse(int fd);
int			analyze_line(char *line, t_label *labels,
			header_t *header, int *size);
int			pars_inst(char *line, int *size, t_label *labels);
int			pars_args(t_parse *parse, t_label *labels, char *inst,
			int op, int size);
int			point(char *line, header_t *header);
int			get_opcode(char *inst);

/*
**	error
*/
int			puterror(char *str, int error);

#endif
