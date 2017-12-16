/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disas.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:38:10 by iburel            #+#    #+#             */
/*   Updated: 2017/12/16 23:53:55 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISAS_H
# define DISAS_H

/*
03 70 01 00 92 03 70 01 00 92 03 70 01 00 92 03
70 01 00 92 03 70 01 00 31 03 70 01 00 59 08 54
02 02 02 0C 00 6E 02 90 FF FF FF F1 03 02 90 00
00 00 01 04 04 54 03 04 03 09 00 0B 08 54 05 05
05 09 FF F3 01 00 00 00 01 02 90 FF FF FF E7 03
02 90 00 00 00 01 04 04 54 03 04 03 09 00 0B 08
54 05 05 05 09 FF F3 08 54 01 01 01 04 54 01 01
01 01 00 00 00 01 0C 00 03 0C 00 03 0C 00 03 0C
00 03 0C 00 03 0C 00 03 0C 00 03 0C 00 03 0C 00
03 01 00 00 00 01 01 00 00 00 01 01 00 00 00 01
01 00 00 00 01 09 FF EC
*/
# include "libft.h"
# include "op.h"
# include <errno.h>

# define DISAS_EXT		".s"
# define COR_EXT		".cor"
# define BSIZE			100000

# define USAGE			"usage: %s [-v] <filename>.cor\n"
# define EXEC_NAME		"disas"

# define ERROR_EXT			"Invalid file extension"
# define ERROR_SIZE			"Invalid file size"
# define ERROR_MAGIC		"Invalid magic number"
# define ERROR_INST			"Invalid instruction"
# define ERROR_ARG			"Invalid argument"

# define HEADER_SIZE	(PROG_NAME_LENGTH + COMMENT_LENGTH + 16)

typedef unsigned char		t_uint8;
typedef struct	s_file		t_file;
typedef struct	s_buf		t_buf;

struct	s_file
{
	char		*path;
	t_uint8		*prog;
	int			prog_size;
	int			cursor;
	char		name[PROG_NAME_LENGTH + 4];
	char		comment[COMMENT_LENGTH + 4];
};

extern char		*g_buf;
extern int		g_i;
extern t_op		op_tab[17];

int			print_error(char *msg);
int			get_binary(t_file *file, char *path);
int			parse_file(t_file *file);
void		short_arg(t_file *file, int isdir);
void		int_arg(t_file *file);
int			first_arg(t_file *file, t_uint8 octal, int size);
int			second_arg(t_file *file, t_uint8 octal, int size);
int			third_arg(t_file *file, t_uint8 octal, int size);

#endif
