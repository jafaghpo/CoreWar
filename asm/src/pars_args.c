/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 09:04:18 by iburel            #+#    #+#             */
/*   Updated: 2018/01/03 15:00:13 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_register(t_parse *parse, char *inst, int *len, int i, int op)
{
	int		j;
	int		n;

	if (op_tab[op - 1].octal)
		inst[1] |= REG_CODE << (6 - 2 * i);
	n = 0;
	j = 1;
	while (ft_isdigit(parse->ptr[i][j]))
	{
		n = n * 10 + parse->ptr[i][j] - '0';
		j++;
	}
	if (parse->ptr[i][j])
		return (puterror(ERROR_SYNTAX_REG, 0));
	if (n > REG_NUMBER)
		return (puterror(ERROR_REG_NUMBER, 0));
	inst[*len] = (char)n;
	(*len)++;
	return (1);
}

static int	get_direct(t_parse *parse, char *inst, int *len, int i, t_label *labels, int op, int size)
{
	int		n;
	int		j;
	char	sign;
	int		error;

	error = 0;
	if (op_tab[op - 1].octal)
		inst[1] |= DIR_CODE << (6 - 2 * i);
	n = eval_expr(rmspace(parse->ptr[i] + 1), labels, &error, size);
	if (error == 1)
		return (puterror(ERROR_SYNTAX_DIR, 0));
	else if (error == 2)
	{
		labels->tmp = add_tmplb(labels->tmp, parse->ptr[i] + 1, buff_getcursor() + *len, op_tab[op - 1].size, size);
		*len += 2 + (!op_tab[op - 1].size);
		return (1);
	}
	if (op_tab[op - 1].size)
	{
		inst[*len + 0] = (char)(n >> 8);
		inst[*len + 1] = (char)(n >> 0);
		*len += 2;
	}
	else
	{
		inst[*len + 0] = (char)(n >> 24);
		inst[*len + 1] = (char)(n >> 16);
		inst[*len + 2] = (char)(n >> 8);
		inst[*len + 3] = (char)(n >> 0);
		*len += 4;
	}
	return (1);
}

static int	get_indirect(t_parse *parse, char *inst, int *len, int i, t_label *labels, int op, int size)
{
	int		error;
	int		sign;
	int		n;
	int		j;

	error = 0;
	if (op_tab[op - 1].octal)
		inst[1] |= IND_CODE << (6 - 2 * i);
	n = eval_expr(rmspace(parse->ptr[i]), labels, &error, size);
	if (error == 1)
		return (puterror(ERROR_SYNTAX_IND, 0));
	else if (error == 2)
	{
		labels->tmp = add_tmplb(labels->tmp, parse->ptr[i], buff_getcursor() + *len, 1, size);
		*len += 2;
		return (1);
	}
	inst[*len + 0] = (char)(n >> 8);
	inst[*len + 1] = (char)(n >> 0);
	*len += 2;
	return (1);
}

int			pars_args(t_parse *parse, t_label *labels, char *inst, int op, int size)
{
	int		i;
	int		len;

	len = 1 + op_tab[op - 1].octal;
	i = 0;
	while (i < parse->nb)
	{
		if (parse->ptr[i][0] == 'r')
		{
			if (!(op_tab[op - 1].args[i] & T_REG))
				return (puterror(ERROR_BAD_TYPE_ARG, 0));
			if (!(get_register(parse, inst, &len, i, op)))
				return (0);
		}
		else if (parse->ptr[i][0] == DIRECT_CHAR)
		{
			if (!(op_tab[op - 1].args[i] & T_DIR))
				return (puterror(ERROR_BAD_TYPE_ARG, 0));
			if (!get_direct(parse, inst, &len, i, labels, op, size))
				return (0);
		}
		else
		{
			if (!(op_tab[op - 1].args[i] & T_IND))
				return (puterror(ERROR_BAD_TYPE_ARG, 0));
			if (!(get_indirect(parse, inst, &len, i, labels, op, size)))
				return (0);
		}
		i++;
	}
	return (len);
}
