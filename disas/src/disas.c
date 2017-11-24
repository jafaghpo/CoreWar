/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 23:06:18 by iburel            #+#    #+#             */
/*   Updated: 2017/09/21 17:20:00 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int     putargs(char *buf)
{
    int     i;
    int     cursor;
    int     n;
    char    *tmp;
    char    direct_char[1];

    cursor = 1;
    i = 0;
    while (i < op_tab[buf[0] - 1].nb_args)
    {
        if (op_tab[buf[0] - 1].args[0] == T_DIR)
        {
            direct_char[0] = DIRECT_CHAR;
            buff(direct_char, 1);
        }
        else if (op_tab[buf[0] - 1].args[0] == T_REG)
            buff("r", 1);
        n = buf[cursor];
        n = (n << 8) | buf[cursor + 1];
        if (op_tab[buf[0] - 1].label_size == 4)
        {
            n = (n << 8) | buf[cursor + 2];
            n = (n << 8) | buf[cursor + 3];
        }
        tmp = ft_itoa(n);
        buff(tmp, ft_strlen(tmp));
        free(tmp);
        if (i != op_tab[buf[0] - 1].nb_args - 1)
            buff(", ", 2);
        cursor += op_tab[buf[0] - 1].label_size;
        i++;
    }
    buff("\n", 1);
    return (cursor);
}

int     putargsoctal(char *buf, int *arg)
{
    int     i;
    int     cursor;
    int     n;
    char    *tmp;
    int     size;
    char    direct_char[1];

    cursor = 2;
    i = 0;
    while (i < op_tab[buf[0] - 1].nb_args)
    {
        if (arg[i] == REG_CODE)
        {
            size = 1;
            buff("r", 1);
        }
        else if (arg[i] == IND_CODE)
            size = 2;
        else
        {
            size = op_tab[buf[0] - 1].label_size;
            direct_char[0] = DIRECT_CHAR;
            buff(direct_char, 1);
        }
        n = buf[cursor];
        if (size >= 2)
        n = (n << 8) | buf[cursor + 1];
        if (size == 4)
        {
            n = (n << 8) | buf[cursor + 2];
            n = (n << 8) | buf[cursor + 3];
        }
        tmp = ft_itoa(n);
        buff(tmp, ft_strlen(tmp));
        free(tmp);
        if (i != op_tab[buf[0] - 1].nb_args - 1)
            buff(", ", 2);
        cursor += size;
        i++;
    }
    buff("\n", 1);
    return (cursor);
}

int     disas(int fd)
{
    char    buf[BUFF_SIZE + 1];
    int     ret;
    int     i;
    int     tmp;
    int     arg[4];

    buff_init();
    if (!putheader(fd))
        return (0);
    if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
        return (puterror(ERROR_READ, 0));
    if (ret == BUFF_SIZE)
        return (puterror(ERROR_PROG_SIZE, 0));
    i = 0;
    while (i < ret)
    {
        if (buf[i] < 0 || buf[i] > sizeof(op_tab) / sizeof(t_op) - 1)
            return (puterror(ERROR_BAD_FORMAT, 0));
        if (i + op_tab[buf[i] - 1].octal + op_tab[buf[i] - 1].nb_args >= ret)
            return (puterror(ERROR_BAD_FORMAT, 0));
        buff(op_tab[buf[i] - 1].inst, ft_strlen(op_tab[buf[i] - 1].inst));
        buff("\t", 1);
        if (op_tab[buf[i] - 1].octal)
        {
            arg[0] = (buf[i + 1] & 0b11000000) >> 6;
            arg[1] = (buf[i + 1] & 0b00110000) >> 4;
            arg[2] = (buf[i + 1] & 0b00001100) >> 2;
            arg[3] = (buf[i + 1] & 0b00000011) >> 0;
            if (!(tmp = putargsoctal(buf + i, arg)))
                return (0);
        }
        else if (!(tmp = putargs(buf + i)))
            return (0);
        i += tmp;
    }
    return (1);
}