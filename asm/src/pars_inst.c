/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 13:21:49 by iburel            #+#    #+#             */
/*   Updated: 2017/12/16 20:46:19 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		pars_inst(char *line, int *size, t_label *labels)
{
	t_parse	parse;
	char	inst[20];
	int		len;
	int		op;

	ft_delspace(&line);
	len = wordlen(line);
	line[len] = 0;
	if ((op = get_opcode(line)) == -1)
		return (puterror(ERROR_INST, 0));
	inst[0] = (char)op;
	inst[1] = 0;
	line += len + 1;
	if (!split_spe(&parse, line))
		return (0);
	if (!fill_size(&parse))
		return (0);
#ifdef DEBUG
	putparse(&parse);
#endif
	if (parse.nb != op_tab[op - 1].nb_args)
		return (puterror(ERROR_NB_ARGS, 0));
	if (!(len = pars_args(&parse, labels, inst, op, *size)))
		return (0);
	*size += len;
	buff(inst, len);
	return (1);
}
