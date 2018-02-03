/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_music.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:27:45 by iburel            #+#    #+#             */
/*   Updated: 2018/02/03 15:31:11 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void    start_music(void)
{
    char    *music_command;

    if (!g_theme.music_file)
        return ;
    if (!(music_command = malloc(sizeof(*music_command) * (7 + ft_strlen(g_theme.music_file) + 2))))
        return ;
    ft_sprintf(music_command, "afplay %s&", g_theme.music_file);
    system("afplay ./music/aivi_answer.mp3&");
}