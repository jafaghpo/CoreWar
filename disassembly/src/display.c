/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 15:44:57 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/14 23:42:09 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int		g_line = 1;

void			display_inst(t_dfile *file, int opcode)
{
	g_i += sprintf(g_buf + g_i, "%s\t", op_tab[opcode].inst);
	if (file->win.flag)
	{
		win_key_hook(file);
		wattron(file->win.as, COLOR_PAIR(4) | A_BOLD);
		if (g_line == LINES - 7)
		{
			werase(file->win.as);
			wprintw(file->win.as, "\n\n\n");
			box(file->win.as, ACS_VLINE, ACS_HLINE);
			wrefresh(file->win.as);
			g_line = 1;
		}
		wprintw(file->win.as, "\t%s\t\t\t", op_tab[opcode].inst);
		wattroff(file->win.as, COLOR_PAIR(4));
		win_put_binary(file, (t_gap){file->cursor, 0});
		box(file->win.as, ACS_VLINE, ACS_HLINE);
		wrefresh(file->win.as);
		g_line++;
	}
}

void			display_separator(t_dfile *file, char *sep, int start, int end)
{
	t_gap		gap;

	g_i += sprintf(g_buf + g_i, "%s", sep);
	if (file->win.flag)
	{
		gap.start = start;
		gap.end = end;
		win_key_hook(file);
		wprintw(file->win.as, "%s", sep);
		box(file->win.as, ACS_VLINE, ACS_HLINE);
		win_put_binary(file, gap);
		wrefresh(file->win.as);
	}
}

void			display_integer(t_dfile *file, char *format, int arg)
{
	g_i += sprintf(g_buf + g_i, format, arg);
	if (file->win.flag)
	{
		wprintw(file->win.as, "\t");
		wprintw(file->win.as, format, arg);
		box(file->win.as, ACS_VLINE, ACS_HLINE);
	}
}

void			display_string(t_dfile *file, char *format, char *arg)
{
	g_i += sprintf(g_buf + g_i, format, arg);
	if (file->win.flag)
	{
		wprintw(file->win.as, format, arg);
		box(file->win.as, ACS_VLINE, ACS_HLINE);
	}
}

void			display_header(t_dfile *file)
{
	t_gap		gap;

	if (file->win.flag)
		wprintw(file->win.as, "\n\n\n\t");
	display_string(file, ".name \"%s\"\n", (char*)file->prog + MAGIC_SIZE);
	if (file->win.flag)
	{
		win_key_hook(file);
		gap = (t_gap){4, ft_strlen((char*)file->prog + MAGIC_SIZE) - 1};
		win_put_binary(file, gap);
		wrefresh(file->win.as);
	}
	if (file->win.flag)
		wprintw(file->win.as, "\t");
	display_string(file, ".comment \"%s\"\n\n", (char*)file->prog + MAGIC_SIZE);
	if (file->win.flag)
	{
		win_key_hook(file);
		wattron(file->win.as, COLOR_PAIR(5));
		gap = (t_gap){NAME_SIZE, ft_strlen((char*)file->prog + NAME_SIZE) - 1};
		win_put_binary(file, gap);
		wrefresh(file->win.as);
		g_line += 3;
	}
}
