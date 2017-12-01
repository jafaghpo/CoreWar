/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:29:02 by iburel            #+#    #+#             */
/*   Updated: 2017/04/17 20:30:14 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_typesint(t_llint *nbr)
{
	*nbr = (int)(*nbr);
}

void		ft_typeshh(t_llint *nbr)
{
	*nbr = (char)(*nbr);
}

void		ft_typesh(t_llint *nbr)
{
	*nbr = (t_hint)(*nbr);
}

static void	ft_fill_tab(void (***f)(t_llint *))
{
	if (!(*f = malloc(sizeof(**f) * 7)))
		ft_afferror("error malloc in ft_getsype");
	(*f)[0] = ft_typesint;
	(*f)[FHH] = ft_typeshh;
	(*f)[FH] = ft_typesh;
	(*f)[FJ] = ft_typesj;
	(*f)[FZ] = ft_typesz;
	(*f)[FL] = ft_typesl;
	(*f)[FLL] = ft_typesll;
}

void		ft_getstype(t_uint type, t_llint *nbr)
{
	static void	(**f)(t_llint *);

	if (!f)
		ft_fill_tab(&f);
	(*f[type])(nbr);
}
