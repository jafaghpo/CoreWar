/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 18:22:29 by iburel            #+#    #+#             */
/*   Updated: 2017/10/03 12:44:02 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int		isop(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

char	*rmpar(char *str)
{
	int		par;
	int		i;

	i = 0;
	while (str[i] == '(')
		i++;
	par = i;
	if (par == 0)
		return (str);
	while (str[i])
	{
		if (str[i] == '(')
			par++;
		else if (str[i] == ')')
			par--;
		if (par == 0)
		{
			if (str[i + 1] == 0)
			{
				str[i] = 0;
				return (str + 1);
			}
			else
				return (str);
		}
		i++;
	}
	return (NULL);
}

int		islabel(t_label *labels, char *str, int *error, int size)
{
	int		i;
	int		addr;

	*error = 0;
	if (*str != LABEL_CHAR)
		return ((*error = 1));
	str++;
	i = 0;
	while (str[i] && !isop(str[i]) && str[i] != '(' && str[i] != ')')
		i++;
	if (str[i])
		return ((*error = 1));
	if ((addr = get_label_addr(str, labels)) != -1)
		return (addr - size);
	return (*error = 2);
}

int		eval_expr(char *str, t_label *labels, int *error, int size)
{
	char	*op;
	int		par;
	int		i;
	char	c;

	if (*error == 2)
		return (0);
	*error = 0;
	str = rmpar(str);
	par = islabel(labels, str, error, size);
	if (*error != 1)
		return (par);
	par = atoi_base(str, error);
	if (!*error)
		return (par);
	op = NULL;
	par = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			par++;
		else if (str[i] == ')')
			par--;
		if (par == 0 && isop(str[i]) && (!op || str[i] == '-' || str[i] == '+' || *op == '*' || *op == '/' || *op == '%') && !isop(str[i - 1]))
			op = str + i;
		i++;
	}
	c = *op;
	*op = 0;
	if (c == '+')
		return (eval_expr(str, labels, error, size) + eval_expr(op + 1, labels, error, size));
	if (c == '-')
		return (eval_expr(str, labels, error, size) - eval_expr(op + 1, labels, error, size));
	if (c == '*')
		return (eval_expr(str, labels, error, size) * eval_expr(op + 1, labels, error, size));
	if (c == '/')
		return (eval_expr(str, labels, error, size) / eval_expr(op + 1, labels, error, size));
	if (c == '%')
		return (eval_expr(str, labels, error, size) % eval_expr(op + 1, labels, error, size));
	return (1);
}
