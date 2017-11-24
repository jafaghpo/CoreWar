/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disas.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 21:38:10 by iburel            #+#    #+#             */
/*   Updated: 2017/09/20 23:44:04 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISAS_H
# define DISAS_H

# include "libft.h"
# include "op.h"

# define HEADER_LENGTH PROG_NAME_LENGTH + COMMENT_LENGTH + 16

# define ERROR_OPEN_S		"error open s"
# define ERROR_OPEN_COR		"error open cor"
# define ERROR_MALLOC		"error malloc"
# define ERROR_READ			"error read"
# define ERROR_BAD_FORMAT	"error the file is not a .cor"
# define ERROR_HEADER		"error no header or bad header"
# define ERROR_MAGIC		"error corewar exec magic number"
# define ERROR_INST			"error bad format instruction"
# define ERROR_PROG_SIZE	"error prog too big"
# define ERROR_BAD_INST		"error bad instruction"

typedef struct s_buf	t_buf;

struct s_buf
{
	char	*buf;
	int		size;
	int		i;
};

extern t_op op_tab[17];

/*
** buff
*/
void	buff(char *str, int len);
void	buff_init(void);
void	buff_put(int fd);

/*
** file
*/
char	*get_name(char *file);

/*
** error
*/
int		puterror(char *str, int ret);

/*
** put
*/
int		disas(int fd);
int		putheader(int fd);

#endif
