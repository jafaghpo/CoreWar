/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_spe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 12:44:14 by iburel            #+#    #+#             */
/*   Updated: 2017/09/13 12:27:29 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		count_words(char *line)
{
	int		nb;

	if (!*line)
		return (0);
	nb = 1;
	while (*line && *line != COMMENT_CHAR)
	{
		if (*line == SEPARATOR_CHAR)
			nb++;
		line++;
	}
	return (nb);
}

int		split_spe(t_parse *parse, char *line)
{
	int		i;

	ft_delspace(&line);
	parse->nb = count_words(line);
	if (!(parse->ptr = malloc(sizeof(char *) * parse->nb)))
		ft_afferror(ERROR_MALLOC);
	if (!(parse->size = malloc(sizeof(int) * parse->nb)))
		ft_afferror(ERROR_MALLOC);
	parse->ptr[0] = line;
	i = 0;
	while (*line && *line != COMMENT_CHAR)
	{
		if (*line == SEPARATOR_CHAR)
		{
			*line = 0;
			line++;
			ft_delspace(&line);
			if (!*line || *line == SEPARATOR_CHAR)
				return (puterror(ERROR_SYNTAX_SEPARATOR, 0));
			parse->ptr[i + 1] = line;
			i++;
		}
		line++;
	}
	return (1);
}
