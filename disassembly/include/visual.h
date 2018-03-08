/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:47:10 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 17:28:09 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <ncurses.h>
# include "disas.h"

/*
**	-- Defines --
*/
# define NC_BLACK		0
# define NC_GREEN		1
# define NC_YELLOW		2
# define NC_BLUE		3
# define NC_RED			4
# define NC_WHITE		5

# define GO_START		"\n\n\n\t"
# define GO_NEXT		"\n\t"
# define AUTO_MODE		"Automatic mode: [press enter key]"
# define STEP_MODE		"Step by step mode: [press any key]"
# define NEXT_MANUAL	"press enter key to go to next champion"
# define ERROR_VISUAL	"Failed to run visual mode"
# define ERROR_CHAMP	"Failed to compile %s"

typedef struct s_size	t_size;
typedef struct s_visual	t_visual;
typedef struct s_tab	t_tab;
/*
**	-- Structures --
*/
struct			s_size
{
	int			x;
	int			y;
};

struct			s_visual
{
	WINDOW		*as;
	WINDOW		*bin;
	t_size		size;
	t_size		cur;
	int			delay;
};

/*
**	-- Prototypes --
*/
void			store_line(t_visual *win, t_tab *tab, t_tab current);
int				setup_visual(t_visual *win, t_tab **tab);
void			run_visual(t_tab *tab, t_visual *win);
void			reset_visual(t_visual *win, char *name, char *arg);
void			delete_visual(t_visual *win, t_tab *tab);
void			clear_tab(t_tab *tab);
int				wait_event(t_visual *win);
void			wait_end(void);

#endif
