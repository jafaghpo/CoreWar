/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:12:14 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/11/01 20:08:23 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bc.h"

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
	while (current <= s->op->rank && s->op->rank != delimiter)
	{
		n[0] = s->nb->token;
		pop_token(token, &s->nb);
		n[1] = s->nb->token;
		pop_token(token, &s->nb);
		op = pop_token(token, &s->op);
		push_token(g_calc[op](n[1], n[0], &token->error),
		token, &s->nb, number);
	}
	push_token(expr[token->cursor], token, &s->op, current);
}

void	reduce_b(t_token *token, t_heap *s)
{
	int		n[2];
	int		op;

	while (s->op->rank != bracket && s->op->rank != delimiter)
	{
		n[0] = s->nb->token;
		pop_token(token, &s->nb);
		n[1] = s->nb->token;
		pop_token(token, &s->nb);
		op = pop_token(token, &s->op);
		push_token(g_calc[op](n[1], n[0], &token->error),
		token, &s->nb, number);
	}
	if (s->op->rank == delimiter)
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

	while (s->op->rank != delimiter)
	{
		n[0] = s->nb->token;
		pop_token(token, &s->nb);
		n[1] = s->nb->token;
		pop_token(token, &s->nb);
		op = pop_token(token, &s->op);
		push_token(g_calc[op](n[1], n[0], &token->error),
		token, &s->nb, number);
	}
}

void	eval_stack(char *expr, t_token *token, t_heap *stack, t_flag flag)
{
	if (token->error == 1)
		return ;
	else if (flag == inferior_op)
		reduce_op(expr, token, stack);
	else if (flag == closed_bracket)
		reduce_b(token, stack);
	else
		reduce_s(token, stack);
}
