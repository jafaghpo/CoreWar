/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_theme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:44:38 by iburel            #+#    #+#             */
/*   Updated: 2018/01/27 01:42:58 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	del_blanks(char **str)
{
	while (**str == ' ' || **str == '\t')
		(*str)++;
}

static int	get_filename(char *line, char **str)
{
	del_blanks(&line);
	if (*line != '=')
		return (0);
	line++;
	del_blanks(&line);
	*str = ft_strdup(line);
	return (1);
}

static int	get_color(char *line, t_case *color)
{
	del_blanks(&line);
	if (*line != '=')
		return (0);
	line++;
	del_blanks(&line);
	color->r = 0;
	while (ft_isdigit(*line))
	{
		color->r = color->r * 10 + *line - '0';
		line++;
	}
	color->r /= 255.f;
	del_blanks(&line);
	if (*line != ',')
		return (0);
	color->g = 0;
	while (ft_isdigit(*line))
	{
		color->g = color->g * 10 + *line - '0';
		line++;
	}
	color->g /= 255.f;
	del_blanks(&line);
	if (*line != ',')
		return (0);
	color->b = 0;
	while (ft_isdigit(*line))
	{
		color->b = color->b * 10 + *line - '0';
		line++;
	}
	color->b /= 255.f;
	del_blanks(&line);
	if (*line != '#' && *line)
		return (0);
	return (1);
}

int             get_theme(t_args *flags, char *str)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		test;
	int		i;
	
    (void)flags;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_printf("error open theme file\n");
		return (0);
	}
	i = 1;
	while (get_next_line(fd, &tmp))
	{
		test = 0;
		line = tmp;
		del_blanks(&line);
		if (!ft_strncmp(line, "background", 10))
			test = get_filename(line + 10, &g_theme.background_file);
		else if (!ft_strncmp(line, "hud", 3))
			test = get_filename(line + 3, &g_theme.hud_file);
		else if (!ft_strncmp(line, "square texture", 14))
			test = get_filename(line + 14, &g_theme.case_texture);
		else if (!ft_strncmp(line, "music", 5))
			test = get_filename(line + 5, &g_theme.music_file);
		else if (!ft_strncmp(line, "font", 5))
			test = get_filename(line + 5, &g_theme.police_file);
		else if (!ft_strncmp(line, "color if empty", 14))
			test = get_color(line + 14, &g_theme.color_empty);
		else if (!ft_strncmp(line, "color player 1", 14))
			test = get_color(line + 14, &g_theme.color_players[0]);
		else if (!ft_strncmp(line, "color player 2", 14))
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
		if (!test && line[0] != '#' && line[0])
			ft_printf("l%2d : \"%s\" ignored\n", i, tmp);
		free(tmp);
		i++;
	}
}
