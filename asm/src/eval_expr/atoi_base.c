/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:00:30 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/02 20:37:16 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

static int	isdigitbase(char c, int base)
{
	if (base <= 10)
		return ((c >= '0' && c <= base + '0' - 1));
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= base - 10 + 'a' - 1) ||
			(c >= 'A' && c <= base - 10 + 'A' - 1));
}

static int	get_base(char *str, t_token *token)
{
	if (str[token->cursor] == '0' && ft_isdigit(str[token->cursor + 1]))
	{
		token->cursor += 1;
		return (8);
	}
	else if (str[token->cursor + 1] == 'x' || str[token->cursor + 1] == 'X')
	{
		token->cursor += 2;
		return (16);
	}
	else if (str[token->cursor + 1] == 'b' || str[token->cursor + 1] == 'B')
	{
		token->cursor += 2;
		return (2);
	}
	else
		return (10);
	return (-1);
}

static int	get_nb(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	return (c - 'A' + 10);
}

int			atoi_base(char *str, t_token *token)
{
	int		n;
	int		base;
	int		sign;

	sign = 1;
	if (str[token->cursor] == '-')
	{
		token->cursor++;
		sign = -1;
	}
	base = get_base(str, token);
	if (!isdigitbase(str[token->cursor], base))
		token->error = 1;
	n = 0;
	while (isdigitbase(str[token->cursor], base))
	{
		n = n * base + get_nb(str[token->cursor]);
		token->cursor++;
	}
	token->cursor--;
	return (n * sign);
}
