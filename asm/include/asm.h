/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:38:13 by iburel            #+#    #+#             */
/*   Updated: 2018/01/03 23:07:08 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <ncurses.h>
# include <errno.h>
# include "libft.h"
# include "op.h"
# include "eval_expr.h"

# define ERROR_EXT		"Invalid file extension"

# define WARNING_FLAG	0x01
# define VISUAL_FLAG	0x02
# define BSIZE			10000

typedef uint8_t	t_uint8;

typedef struct	s_tab
{
	char		*line;
	t_uint8		*ptr;
	int			size;
}				t_tab;

typedef struct	s_buf
{
	t_uint8		*data;
	int			size;
	int			i;
}				t_buf;

extern	t_buf	g_bin;
extern	t_op	g_op[17];

/*
**	-- Common --
*/

int				print_error(char *msg);
char			*get_name(char *file);
int				fill_binary(char *name);

/*
**	-- Parsing --
*/

int				parse_file(char *name, int option);
int				parse_header(t_tab *tab, int option);
int				parse_core(t_tab *tab);

/*
**	--	Visual flag --
*/

void			run_visual(t_tab *tab);

#endif
