/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkandcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:13:41 by iburel            #+#    #+#             */
/*   Updated: 2018/02/13 15:37:33 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

float		one_color(char **line)
{
	float	color;

	color = 0;
	while (ft_isdigit(**line))
	{
		color = color * 10 + **line - '0';
		(*line)++;
	}
	return (color / 255.f);
}

int			get_color(char *line, t_case *color)
{
	del_blanks(&line);
	if (*line != '=')
		return (0);
	line++;
	del_blanks(&line);
	color->r = one_color(&line);
	del_blanks(&line);
	if (*line != ',')
		return (0);
	line++;
	del_blanks(&line);
	color->g = one_color(&line);
	del_blanks(&line);
	if (*line != ',')
		return (0);
	line++;
	del_blanks(&line);
	color->b = one_color(&line);
	del_blanks(&line);
	if (*line != '#' && *line)
		return (0);
	return (1);
}

static int	check2(char *line)
{
	int		test;

	test = 0;
	if (!ft_strncmp(line, "color player 2", 14))
		test = get_color(line + 14, &g_theme.color_players[1]);
	else if (!ft_strncmp(line, "color player 3", 14))
		test = get_color(line + 14, &g_theme.color_players[2]);
	else if (!ft_strncmp(line, "color player 4", 14))
		test = get_color(line + 14, &g_theme.color_players[3]);
	else if (!ft_strncmp(line, "color numbers", 13))
		test = get_color(line + 14, &g_theme.color_numbers);
	else if (!ft_strncmp(line, "color square texture", 20))
		test = get_color(line + 20, &g_theme.color_texture);
	else if (!ft_strncmp(line, "color chat", 10))
		test = get_color(line + 10, &g_theme.color_chat);
	else if (!ft_strncmp(line, "color hud numbers", 17))
		test = get_color(line + 17, &g_theme.color_fps);
	return (test);
}

void		check_line_theme(char *line, char *tmp, int i)
{
	int		test;

	test = 0;
	if (!ft_strncmp(line, "background", 10))
		test = get_filename(line + 10, &g_theme.background_file);
	else if (!ft_strncmp(line, "hud background", 14))
		test = get_filename(line + 14, &g_theme.hud_background_file);
	else if (!ft_strncmp(line, "hud", 3))
		test = get_filename(line + 3, &g_theme.hud_file);
	else if (!ft_strncmp(line, "square texture", 14))
		test = get_filename(line + 14, &g_theme.case_texture);
	else if (!ft_strncmp(line, "music", 5))
		test = get_filename(line + 5, &g_theme.music_file);
	else if (!ft_strncmp(line, "font", 4))
		test = get_filename(line + 5, &g_theme.police_file);
	else if (!ft_strncmp(line, "color empty", 11))
		test = get_color(line + 11, &g_theme.color_empty);
	else if (!ft_strncmp(line, "color player 1", 14))
		test = get_color(line + 14, &g_theme.color_players[0]);
	else
		test = check2(line);
	if (!test && line[0] != '#' && line[0])
		ft_printf("l%-2d : \"%s\" ignored\n", i, tmp);
}
