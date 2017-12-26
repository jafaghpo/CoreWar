/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disas.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:38:10 by iburel            #+#    #+#             */
/*   Updated: 2017/12/26 21:22:50 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISAS_H
# define DISAS_H

# include "libft.h"
# include "op.h"
# include <errno.h>
# include <ncurses.h>
# include <stdarg.h>

# define DISAS_EXT		".s"
# define COR_EXT		".cor"
# define BSIZE			100000

# define EXEC_NAME		"disas"

# define ERROR_EXT		"Invalid file extension"
# define ERROR_SIZE		"Invalid file size"
# define ERROR_MAGIC	"Invalid magic number"
# define ERROR_INST		"Invalid instruction"
# define ERROR_ARG		"Invalid argument"

# define AUTO_MANUAL	"Automatic mode: [press enter key]"
# define STEP_MANUAL	"Step by step mode: [press any key]"

# define MAGIC_SIZE		4
# define NAME_SIZE		(PROG_NAME_LENGTH + MAGIC_SIZE + 8)
# define COM_SIZE		(COMMENT_LENGTH + 4)
# define HEADER_SIZE	(NAME_SIZE + COM_SIZE)

typedef unsigned char	t_uint8;
typedef struct s_file	t_file;
typedef struct s_win	t_win;
typedef struct s_gap	t_gap;

struct	s_win
{
	WINDOW		*bin;
	WINDOW		*as;
	t_uint8		flag : 1;
	t_uint8		delay : 1;
};

struct	s_file
{
	char		*path;
	t_uint8		*prog;
	int			prog_size;
	int			cursor;
	t_win		win;
};

struct	s_gap
{
	int			start;
	int			end;
};

extern char		*g_buf;
extern int		g_i;
extern int		g_line;
extern t_op		op_tab[17];

int			print_error(char *msg);
int			get_binary(t_file *file, char *path);
int			parse_file(t_file *file);
void		short_arg(t_file *file, int isdir);
void		int_arg(t_file *file);
int			first_arg(t_file *file, t_uint8 octal, int size);
int			second_arg(t_file *file, t_uint8 octal, int size);
int			third_arg(t_file *file, t_uint8 octal, int size);

void		display_inst(t_file *file, int opcode);
void		display_separator(t_file *file, char *sep, int start, int end);
void		display_integer(t_file *file, char *format, int arg);
void		display_string(t_file *file, char *format, char *arg);
void		display_header(t_file *file);

void		win_setup(t_file *file);
void		win_put_binary(t_file *file, t_gap gap);
void		win_key_hook(t_file *file);

#endif
