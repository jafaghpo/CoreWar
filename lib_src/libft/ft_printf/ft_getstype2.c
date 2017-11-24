/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstype2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 19:29:18 by iburel            #+#    #+#             */
/*   Updated: 2017/04/20 15:08:00 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_typesj(t_llint *nbr)
{
	*nbr = (intmax_t)(*nbr);
}

void	ft_typesz(t_llint *nbr)
{
	*nbr = (ssize_t)(*nbr);
}

void	ft_typesl(t_llint *nbr)
{
	*nbr = (t_lint)(*nbr);
}

void	ft_typesll(t_llint *nbr)
{
	(void)nbr;
}
