/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 20:37:34 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/05 15:16:41 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			check_magic(unsigned char *buffer)
{
	t_uint octets;

	octets = (t_uint)(buffer[3]);
	octets |= (t_uint)(buffer[2]) << 8;
	octets |= (t_uint)(buffer[1]) << 16;
	octets |= (t_uint)(buffer[0]) << 24;
	if (octets != COREWAR_EXEC_MAGIC)
		ft_afferror(ERROR_MAGIC_NUMBER);
}

t_uint			get_champ_size(t_uchar *buffer)
{
	t_uint octets;

	octets = (t_uint)(buffer[PROG_NAME_LENGTH + 11]);
	octets |= (t_uint)((buffer[PROG_NAME_LENGTH + 10]) << 8);
	return (octets);
}

t_player		get_mem(char *name)
{
	int			size;
	int			fd;
	int			rd;
	t_player	new;
	t_uchar		buffer[READ_MAX];

	fd = open(name, O_RDONLY);
	if (fd == -1)
		ft_afferror("error open");
	rd = read(fd, buffer, READ_MAX);
	if (rd == READ_MAX || rd == -1)
		ft_afferror("error get meme");
	check_magic(buffer);
	if (((size = get_champ_size(buffer)) < 1) || size > CHAMP_MAX_SIZE)
		ft_afferror(ERROR_CHAMP_SIZE);
	new.size = size;
	ft_memcpy(new.buffer, buffer + HEADER_SIZE, size);
	ft_memcpy(new.header.prog_name, buffer + 4, PROG_NAME_LENGTH);
	ft_memcpy(new.header.comment, buffer + 12 + PROG_NAME_LENGTH,
			COMMENT_LENGTH);
	close(fd);
	return (new);
}
