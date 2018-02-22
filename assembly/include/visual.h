/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:03:21 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/19 16:06:49 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <ncurses.h>
# include "asm.h"

/*
**	-- Defines --
*/
# define NC_BLACK		0
# define NC_GREEN		1
# define NC_YELLOW		2
# define NC_BLUE		3
# define NC_RED			4

# define AUTO_MODE		"Automatic mode: [press enter key]"
# define STEP_MODE		"Step by step mode: [press any key]"
# define ERROR_VISUAL	"Failed to run visual"

/*
**	-- Typedefs --
*/
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
int				setup_visual(t_visual *win, t_tab **tab);
void			run_visual(t_tab *tab, t_visual *win);
void			reset_visual(t_visual *win);
void			delete_visual(t_visual *win, t_tab *tab);
void			clear_tab(t_tab *tab);
void			wait_end(void);

#endif
