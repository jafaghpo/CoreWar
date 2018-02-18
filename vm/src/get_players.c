/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:29:50 by root              #+#    #+#             */
/*   Updated: 2018/02/18 18:22:11 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_uint8	*get_binary(char *file, t_uint32 *size)
{
	t_uint8 buf[READ_MAX + 1];
	t_uint8 *binary;
	int		fd;
	int		ret;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		ft_dprintf(2, "error open file : %s\n", file);
		exit(1);
	}
	if ((ret = read(fd, buf, READ_MAX + 1)) == -1)
	{
		ft_dprintf(2, "error read file : %s\n", file);
		exit(2);
	}
	if (ret == READ_MAX + 1 || ret < PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
		ft_afferror("file bad size\n");
	if (!(binary = malloc(sizeof(*binary) * ret)))
		ft_afferror("error malloc\n");
	ft_memcpy(binary, buf, ret);
	*size = ret - PROG_NAME_LENGTH - COMMENT_LENGTH - 16;
	return (binary);
}

static void		fill_player(t_player *players, t_uint8 *binary)
{
	if (get_uint32(binary) != COREWAR_EXEC_MAGIC)
		ft_afferror("bad magic number\n");
	if (get_uint32(binary + PROG_NAME_LENGTH + 8) != players->size)
		ft_afferror("bad size\n");
	players->name = (char *)binary + 4;
	players->comment = (char *)binary + PROG_NAME_LENGTH + 12;
	players->buffer = binary + PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
}

t_player		*get_players(t_pfile *files, int nb_players)
{
	t_player		*players;
	int				i;

	i = 0;
	if (!(players = malloc(sizeof(*players) * nb_players)))
		ft_afferror("error malloc\n");
	while (files)
	{
		files->binary = get_binary(files->name, &(players[files->pos].size));
		fill_player(players + files->pos, files->binary);
		g_champs[files->pos + 1].name = ft_strdup(players[files->pos].name);
		g_champs[files->pos + 1].number = rand();
		g_champs[files->pos + 1].color = g_theme.color_players[i % 4];
		g_champs[files->pos + 1].live = 0;
		files = files->next;
		i++;
	}
	return (players);
}
