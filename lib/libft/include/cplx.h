/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cplx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:09:29 by iburel            #+#    #+#             */
/*   Updated: 2017/06/08 14:57:17 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPLX_H
# define CPLX_H

struct	s_cplx
{
	double	re;
	double	im;
};

t_cplx	ft_cplxdiv(t_cplx z1, t_cplx z2);
t_cplx	ft_cplxadd(t_cplx z1, t_cplx z2);
double	ft_cplxmod(t_cplx z);
t_cplx	ft_cplxmult(t_cplx z1, t_cplx z2);
t_cplx	ft_cplxnew(double re, double im);
t_cplx	ft_cplxsqrt(t_cplx z);
t_cplx	ft_cplxsub(t_cplx z1, t_cplx z2);
t_cplx	ft_cplxpow(t_cplx z, int pow);

#endif
