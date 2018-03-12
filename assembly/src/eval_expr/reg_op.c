/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:37:26 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/12 14:29:39 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int			add_calc(int a, int b, int *error)
{
	(void)error;
	return (a + b);
}

int			sub_calc(int a, int b, int *error)
{
	(void)error;
	return (a - b);
}

int			mult_calc(int a, int b, int *error)
{
	(void)error;
	return (a * b);
}

int			div_calc(int a, int b, int *error)
{
	if (b == 0)
		return (*error = 1);
	return (a / b);
}

int			mod_calc(int a, int b, int *error)
{
	if (b == 0)
		return (*error = 1);
	return (a % b);
}
