/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:32:45 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/11/01 19:45:35 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bc.h"

int			and_calc(int a, int b, int *error)
{
	(void)error;
	return (a & b);
}

int			or_calc(int a, int b, int *error)
{
	(void)error;
	return (a | b);
}

int			xor_calc(int a, int b, int *error)
{
	(void)error;
	return (a ^ b);
}

int			lshift_calc(int a, int b, int *error)
{
	(void)error;
	return (a << b);
}

int			rshift_calc(int a, int b, int *error)
{
	(void)error;
	return (a >> b);
}
