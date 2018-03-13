/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_music.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:27:45 by iburel            #+#    #+#             */
/*   Updated: 2018/03/13 20:56:57 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	start_music(void)
{
	char	*music_command;

	if (!g_theme.music_file)
		return ;
	if (!(music_command = malloc(sizeof(*music_command)
		* (70 + ft_strlen(g_theme.music_file) + 2))))
		return ;
	ft_sprintf(music_command, "afplay %s&", g_theme.music_file);
	system(music_command);
	free(music_command);
}
