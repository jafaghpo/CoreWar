/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:15:29 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/15 22:09:25 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int			parse_inst(t_file *file, int fd)
{
	int		i;
	int		opcode;

	i = 0;
	while (i < file->prog_size)
	{
		opcode = file->prog[i];
		if (opcode > 0 && opcode < 17)
			ft_printf("%fd%s\t", fd, g_optab[opcode].inst);
		else
			return (print_error(E_INST, __func__, __FILE__, __LINE__));
		if (g_optab[opcode].size)
			i = parse_size_args(file, i);
		else
			i = parse_args(file, i);
	}
}

int			build_file(t_file *file)
{
	int		fd;

	if ((fd = open(file->path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		return (print_error(NULL, __func__, __FILE__, __LINE__));
	if (!parse_inst(file, fd))
		return (0);
	if (close(fd) < 0)
		return (print_error(E_INST, __func__, __FILE__, __LINE__));
	return (1);
}
