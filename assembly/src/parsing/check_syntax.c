/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 11:06:53 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/11 12:09:34 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	check_syntax_error(t_uint8 *dest, char *line, int i)
{
	if (!*line)
	{
		dest[i++] = '\n';
		g_state |= NEXT_LINE;
		return (i + 1);
	}
	line++;
	ft_delspace(&line);
	if (*line != COMMENT_CHAR && *line)
		return (print_error(SYNTAX, line));
	g_state &= ~(NEXT_LINE);
	return (i + 1);
}

int			check_syntax(t_uint8 *dest, char *line)
{
	int		esc;
	int		i;

	esc = 0;
	i = 0;
	while (*line && !(*line == '"' && !esc))
	{
		if (*line == '\\' && !esc)
			esc = 1;
		else
		{
			dest[i++] = *line;
			esc = 0;
		}
		line++;
	}
	i = check_syntax_error(dest, line, i);
	return (i);
}
