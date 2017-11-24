/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 13:24:51 by iburel            #+#    #+#             */
/*   Updated: 2017/09/10 19:32:21 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	strcpy_spe(char *dest, char *line)
{
	int		esc;

	esc = 0;
	if (*line != '"')
		return (0);
	line++;
	while (1)
	{
		if (*line == '\\' && !esc)
			esc = 1;
		else
		{
			if ((*line == '"' && !esc) || *line == 0)
				break ;
			*dest = *line;
			dest++;
			esc = 0;
		}
		line++;
	}
	if (*line != '"')
		return (0);
	line++;
	ft_delspace(&line);
	return (!*line || *line == ' ' || *line == '\t' || *line == COMMENT_CHAR);
}

int			point(char *line, header_t *header)
{
	int len;

	len = wordlen(line);
	line[len] = 0;
	if (!(ft_strcmp(NAME_CMD_STRING, line)))
	{
		line += len + 1;
		ft_delspace(&line);
		if (!strcpy_spe(header->prog_name, line))
			return (puterror(ERROR_SYNTAX_NAME, 0));
	}
	else if (!(ft_strcmp(COMMENT_CMD_STRING, line)))
	{
		line += len + 1;
		ft_delspace(&line);
		if (!strcpy_spe(header->comment, line))
			return (puterror(ERROR_SYNTAX_COMMENT, 0));
	}
	else
		return (1);
//		return (puterror(ERROR_SYNTAX_POINT, 0));
	return (1);
}
