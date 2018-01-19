/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 11:29:50 by root              #+#    #+#             */
/*   Updated: 2018/01/20 00:49:33 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_uint8  *get_binary(char *file, t_uint32 *size)
{
    t_uint8 buf[READ_MAX + 1];
    t_uint8 *binary;
    int     fd;
    int     ret;

    if ((fd = open(file, O_RDONLY)) == -1)
        ft_afferror("error open file");
    if ((ret = read(fd, buf, READ_MAX + 1)) == -1)
        ft_afferror("error read file");
    if (ret == READ_MAX + 1 || ret < PROG_NAME_LENGTH + COMMENT_LENGTH + 16)
        ft_afferror("file bad size");
    if (!(binary = malloc(sizeof(*binary) * ret)))
        ft_afferror("error malloc");
    ft_memcpy(binary, buf, ret);
    *size = ret - PROG_NAME_LENGTH - COMMENT_LENGTH - 16;
    return (binary);
}

static void     fill_player(t_player *players, t_uint8 *binary)
{

#ifdef DEBUG
    ft_printf("\nmagic : %#x\n", get_uint32(binary));
    ft_printf("real magic : %#x\n\n", COREWAR_EXEC_MAGIC);
#endif

    if (get_uint32(binary) != COREWAR_EXEC_MAGIC)
        ft_afferror("bad magic number");

#ifdef DEBUG
        ft_printf("size : %#x\n", get_uint32(binary + PROG_NAME_LENGTH + 8));
        ft_printf("real size : %#x\n\n", players->size);
#endif

    if (get_uint32(binary + PROG_NAME_LENGTH + 8) != players->size)
        ft_afferror("bad size");
    players->name = (char *)binary + 4;
    players->comment = (char *)binary + PROG_NAME_LENGTH + 12;
    players->buffer = binary + PROG_NAME_LENGTH + COMMENT_LENGTH + 16;
}

t_player        *get_players(t_file *files, int nb_players)
{
    t_player    *players;
    t_uint8     *binary;
    int         i = 0;

    if (!(players = malloc(sizeof(*players) * nb_players)))
        ft_afferror("error malloc");
    while (files)
    {
        binary = get_binary(files->name, &(players[files->pos].size));
        fill_player(players + files->pos, binary);
        g_champs[files->pos].name = players[files->pos].name;
        g_champs[files->pos].number = rand();
		if (i == 0)
			g_champs[files->pos].color = (t_case){1.f / 255.f, 223.f / 255.f, 215.f / 255.f};
		else
			g_champs[files->pos].color = (t_case){233.f / 255.f, 70.f / 255.f, 70.f / 255.f};
        files = files->next;
        i++;
    }
    return (players);
}
