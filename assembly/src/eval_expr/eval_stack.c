/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:12:14 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/24 17:39:34 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		(*g_calc[128])(int, int, int*) =
{
	['+'] = add_calc,
	['-'] = sub_calc,
	['*'] = mult_calc,
	['/'] = div_calc,
	['%'] = mod_calc,
	['&'] = and_calc,
	['|'] = or_calc,
	['^'] = xor_calc,
	['<'] = lshift_calc,
	['>'] = rshift_calc
};

void	reduce_op(char *expr, t_token *token, t_heap *s)
{
	t_type	current;
	int		n[2];
	int		op;

	current = token->type[(int)expr[token->cursor]];
	while (current <= s->op->rank && s->op->rank != DELIMITER)
	{
		n[0] = s->nb->token;
		pop_token(token, &s->nb);
		n[1] = s->nb->token;
		pop_token(token, &s->nb);
		op = pop_token(token, &s->op);
		push_token(g_calc[op](n[1], n[0], &token->error),
		token, &s->nb, NUMBER);
	}
	push_token(expr[token->cursor], token, &s->op, current);
}

void	reduce_b(t_token *token, t_heap *s)
{
	int		n[2];
	int		op;

	while (s->op->rank != BRACKET && s->op->rank != DELIMITER)
	{
		n[0] = s->nb->token;
		pop_token(token, &s->nb);
		n[1] = s->nb->token;
		pop_token(token, &s->nb);
		op = pop_token(token, &s->op);
		push_token(g_calc[op](n[1], n[0], &token->error),
		token, &s->nb, NUMBER);
	}
	if (s->op->rank == DELIMITER)
	{
		token->error = 1;
		return ;
	}
	pop_token(token, &s->op);
}

void	reduce_s(t_token *token, t_heap *s)
{
	int		n[2];
	int		op;

	while (s->op->rank != DELIMITER)
	{
		n[0] = s->nb->token;
		pop_token(token, &s->nb);
		n[1] = s->nb->token;
		pop_token(token, &s->nb);
		op = pop_token(token, &s->op);
		push_token(g_calc[op](n[1], n[0], &token->error),
		token, &s->nb, NUMBER);
	}
}

void	eval_stack(char *expr, t_token *token, t_heap *stack, t_flag flag)
{
	if (token->error == 1)
		return ;
	else if (flag == INFERIOR_OP)
		reduce_op(expr, token, stack);
	else if (flag == CLOSED_BRACKET)
		reduce_b(token, stack);
	else
		reduce_s(token, stack);
}
