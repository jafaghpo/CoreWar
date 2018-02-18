/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_music.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 15:27:45 by iburel            #+#    #+#             */
/*   Updated: 2018/02/16 20:12:27 by iburel           ###   ########.fr       */
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
	printf("%s\n", music_command);
	system(music_command);
	free(music_command);
}
