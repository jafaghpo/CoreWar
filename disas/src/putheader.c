/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putheader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 18:44:26 by iburel            #+#    #+#             */
/*   Updated: 2017/09/20 18:48:18 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int     putheader(int fd)
{
    char    buf[HEADER_LENGTH + 1];
    int     ret;

    if ((ret = read(fd, buf, HEADER_LENGTH)) == -1)
        return (puterror(ERROR_MALLOC, 0));
    if (ret != HEADER_LENGTH)
        return (puterror(ERROR_HEADER, 0));
    buf[ret] = 0;
    if (buf[0] != (char)((COREWAR_EXEC_MAGIC & 0xff000000) >> 24) ||
        buf[1] != (char)((COREWAR_EXEC_MAGIC & 0x00ff0000) >> 16) ||
        buf[2] != (char)((COREWAR_EXEC_MAGIC & 0x0000ff00) >> 8) ||
        buf[3] != (char)((COREWAR_EXEC_MAGIC & 0x000000ff) >> 0))
        return (puterror(ERROR_MAGIC, 0));
    buff(".name \"", 7);
    buff(buf + 4, ft_strlen((char *)(buf + 4)));
    buff("\"\n.comment \"", 12);
    buff(buf + PROG_NAME_LENGTH + 12, ft_strlen(buf + PROG_NAME_LENGTH + 12));
    buff("\"\n\n", 3);
    return (1);
}