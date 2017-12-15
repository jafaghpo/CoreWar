/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disas.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:38:10 by iburel            #+#    #+#             */
/*   Updated: 2017/12/15 19:08:07 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISAS_H
# define DISAS_H

# include "libft.h"
# include "op.h"
# include <errno.h>

# define DISAS_EXT		".s"
# define COR_EXT		".cor"
# define BSIZE			100000

# define USAGE			"usage: %s [-v] <filename>.cor\n"
# define EXEC_NAME		"disas"

# define E_EXT			"Invalid file extension"
# define E_LEN			"Invalid file size"
# define E_MGC			"Invalid magic number"
# define E_INST			"Invalid instruction"

# define HEADER_SIZE	(PROG_NAME_LENGTH + COMMENT_LENGTH + 12)

typedef unsigned char		t_uint8;
typedef struct	s_file		t_file;
typedef struct	s_buffer	t_buffer;

struct	s_file
{
	char	*path;
	char	*prog;
	int		prog_size;
	char	name[PROG_NAME_LENGTH + 4];
	char	comment[COMMENT_LENGTH + 4];
};

extern t_op	g_optab[17];

int			print_error(char *msg, const char function[], char *file, int line);
int			get_binary(t_file *file, char *path);
int			build_file(t_file *file);

#endif
