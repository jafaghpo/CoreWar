/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 18:56:54 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/02 20:37:16 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

static int	islabel(t_label *labels, char *expr, t_token *token)
{
	int		i;
	int		addr;

	token->cursor++;
	i = 0;
	if ((addr = get_label_addr(expr, labels, token)) != -1)
	{
		token->cursor--;
		return (addr - token->size);
	}
	return (token->error = 2);
}

static void	label_value(char *expr, t_token *t, t_heap *s, t_label *labels)
{
	int		nb;

	if (t->next == operator)
		t->error = 1;
	else
	{
		nb = islabel(labels, expr, t);
		push_token(nb, t, &s->nb, number);
		t->next = operator;
	}
}

int			lexer(char *expr, t_token *token, t_heap *stack, t_label *labels)
{
	static void		(*eval[8])() = {eval_invalid, eval_whitespace,
	eval_number, label_value, eval_bracket, eval_operator, eval_operator};
	t_type			current;

	while (expr[token->cursor])
	{
		current = token->type[(int)expr[token->cursor]];
		eval[current](expr, token, stack, labels);
		if (token->error)
			return (0);
		token->cursor++;
	}
	if (token->bracket || token->next != operator)
		token->error = 1;
	eval_stack(expr, token, stack, final);
	return (stack->nb->token);
}
