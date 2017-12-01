/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getutype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:27:48 by iburel            #+#    #+#             */
/*   Updated: 2017/04/20 15:07:21 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_typeuint(t_ullint *nbr)
{
	*nbr = (t_uint)(*nbr);
}

void		ft_typeuhh(t_ullint *nbr)
{
	*nbr = (t_uchar)(*nbr);
}

void		ft_typeuh(t_ullint *nbr)
{
	*nbr = (t_uhint)(*nbr);
}

static void	ft_fill_tab(void (***f)(t_ullint *))
{
	if (!(*f = malloc(sizeof(**f) * 7)))
		ft_afferror("error malloc in ft_getuype");
	(*f)[0] = ft_typeuint;
	(*f)[FHH] = ft_typeuhh;
	(*f)[FH] = ft_typeuh;
	(*f)[FJ] = ft_typeuj;
	(*f)[FZ] = ft_typeuz;
	(*f)[FL] = ft_typeul;
	(*f)[FLL] = ft_typeull;
}

void		ft_getutype(t_uint type, t_ullint *nbr)
{
	static void	(**f)(t_ullint *);

	if (!f)
		ft_fill_tab(&f);
	(*f[type])(nbr);
}
