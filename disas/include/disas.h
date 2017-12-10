/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disas.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:38:10 by iburel            #+#    #+#             */
/*   Updated: 2017/12/10 18:30:57 by jafaghpo         ###   ########.fr       */
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

# define HEADER_SIZE	(8 + (PROG_NAME_LENGTH + 4) + (COMMENT_LENGTH + 4))

typedef unsigned char		t_uint8;
typedef struct	s_file		t_file;
typedef struct	s_buffer	t_buffer;

struct	s_file
{
	char	*path;
	char	*prog;
	char	name[PROG_NAME_LENGTH + 4];
	char	comment[COMMENT_LENGTH + 4];
};

struct	s_buffer
{
	char	*content;
	int		size;
	int		cursor;
};

int			print_error(int errnum, const char function[], char *file, int line);
int			get_binary(t_file *file, char *path);
int			build_file(t_file *file);

#endif
