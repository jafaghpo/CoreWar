/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 21:46:14 by iburel            #+#    #+#             */
/*   Updated: 2017/04/16 19:26:44 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_pars	ft_fill_tab_pars(t_uint u, void (*f)(t_flags *, t_uint,
								char **, va_list))
{
	t_pars	ret;

	ret.u = u;
	ret.f = f;
	return (ret);
}

static void		ft_fill_tab(t_pars **f)
{
	if (!(*f = (t_pars *)malloc(sizeof(**f) * 128)))
		ft_afferror("error malloc in ft_flags");
	(*f)['#'] = ft_fill_tab_pars(FHT, ft_fillflags);
	(*f)['0'] = ft_fill_tab_pars(FZE, ft_fillflags);
	(*f)['1'] = ft_fill_tab_pars(0, ft_blanks);
	(*f)['2'] = ft_fill_tab_pars(0, ft_blanks);
	(*f)['3'] = ft_fill_tab_pars(0, ft_blanks);
	(*f)['4'] = ft_fill_tab_pars(0, ft_blanks);
	(*f)['5'] = ft_fill_tab_pars(0, ft_blanks);
	(*f)['6'] = ft_fill_tab_pars(0, ft_blanks);
	(*f)['7'] = ft_fill_tab_pars(0, ft_blanks);
	(*f)['8'] = ft_fill_tab_pars(0, ft_blanks);
	(*f)['9'] = ft_fill_tab_pars(0, ft_blanks);
	(*f)['-'] = ft_fill_tab_pars(FSUB, ft_fillflags);
	(*f)['+'] = ft_fill_tab_pars(FADD, ft_fillflags);
	(*f)[' '] = ft_fill_tab_pars(FSPACE, ft_fillflags);
	(*f)['.'] = ft_fill_tab_pars(FPREC, ft_precs);
	(*f)['h'] = ft_fill_tab_pars(FH, ft_type);
	(*f)['l'] = ft_fill_tab_pars(FL, ft_type);
	(*f)['j'] = ft_fill_tab_pars(FJ, ft_type);
	(*f)['z'] = ft_fill_tab_pars(FZ, ft_type);
	(*f)['L'] = ft_fill_tab_pars(FL2, ft_fillflags);
	(*f)['*'] = ft_fill_tab_pars(0, ft_blanks);
}

void			ft_flags(char **str, t_flags *flags, va_list ap)
{
	static t_pars *f = NULL;

	if (!f)
		ft_fill_tab(&f);
	(*f[(int)**str].f)(flags, f[(int)**str].u, str, ap);
}
