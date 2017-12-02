/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:50:28 by niragne           #+#    #+#             */
/*   Updated: 2017/11/21 21:56:55 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		parse(int fd)
{
	t_label		labels;
	header_t	header;
	char		*line;
	int			size;
	int			rd;

	ft_bzero(header.prog_name, sizeof(header.prog_name));
	ft_bzero(header.comment, sizeof(header.comment));
	buff_init();
	labels.lst = NULL;
	labels.tmp = NULL;
	size = 0;
	while ((rd = get_next_line(fd, &line)))
	{
		if (rd == -1)
			return (puterror(ERROR_READ, 0));
#ifdef DEBUG
		ft_printf("%s\n", line);
#endif
		if (!analyze_line(line, &labels, &header, &size))
		{
#ifdef DEBUG
			exit(0);
#else
			ft_printf("%s\n", line);
			return (0);
#endif
		}
		free(line);
	}
#ifdef DEBUG
	putlabels(&labels);
#endif
	if (!check_tmplb(&labels))
		return (0);
	header.prog_size = size;
	buff_header(&header, ft_strlen(header.prog_name), ft_strlen(header.comment));
	return (1);
}
