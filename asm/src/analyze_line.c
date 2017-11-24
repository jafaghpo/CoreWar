/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 12:09:30 by iburel            #+#    #+#             */
/*   Updated: 2017/09/21 17:29:40 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		analyze_line(char *line, t_label *labels, header_t *header, int *size)
{
	t_pars	pars;
	int		len;

	ft_delspace(&line);
	if (!line[0] || line[0] == '#')
		return (1);
	if (line[0] == '.' && !point(line, header))
		return (0);
	else if (line[0] != '.')
	{
		len = wordlen(line);
		if (line[len - 1] == LABEL_CHAR)
		{
			line[len - 1] = 0;
			if (!check_label(line))
				return (puterror(ERROR_SYNTAX_LABEL, 0));
			labels->lst = add_label(labels->lst, line, *size);
			return (analyze_line(line + len, labels, header, size));
		}
		else if (!pars_inst(line, size, labels))
			return (0);
	}
	return (1);
}
