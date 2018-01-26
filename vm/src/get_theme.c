/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_theme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:44:38 by iburel            #+#    #+#             */
/*   Updated: 2018/01/26 22:47:14 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int  get_color(char *str, t_case *color)
{
    int     i;

    color->r = 0;
    i = 0;
    while (str[i] != ',')
    {
        color->r = color->r * 10 + str[i] - '0';
        i++;
    }
    color->r /= 255.f;
    color->g = 0;
    i++;
    while (str[i] != ',')
    {
        color->g = color->g * 10 + str[i] - '0';
        i++;
    }
    color->g /= 255.f;
    color->b = 0;
    i++;
    while (str[i] != '\n' && str[i] != ' ' && str[i])
    {
        color->b = color->b * 10 + str[i] - '0';
        i++;
    }
    color->b /= 255.f;
    i++;
    return (i);
}

int             get_theme(t_args *flags, char *str)
{
    int     fd;
    char    *line;
    int     i;

    (void)flags;
    if ((fd = open(str, O_RDONLY)) == -1)
        return (0);
    get_next_line(fd, &g_theme.background_file);
    get_next_line(fd, &g_theme.hud_file);
    get_next_line(fd, &g_theme.music_file);
    get_next_line(fd, &g_theme.police_file);
    get_next_line(fd, &line);
    get_color(line, &g_theme.color_empty);
    free(line);
    get_next_line(fd, &line);
    i = get_color(line, &g_theme.color_players[0]);
    i += get_color(line + i, &g_theme.color_players[1]);
    i += get_color(line + i, &g_theme.color_players[2]);
    get_color(line + i, &g_theme.color_players[3]);
    free(line);
    get_next_line(fd, &line);
    get_color(line, &g_theme.color_numbers);
    free(line);
    get_next_line(fd, &line);
    get_color(line, &g_theme.color_chat);
    free(line);
    get_next_line(fd, &line);
    get_color(line, &g_theme.color_fps);
    free(line);
    return (1);
}