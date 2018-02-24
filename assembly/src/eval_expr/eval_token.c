/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:36:19 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/24 17:42:49 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

void		eval_number(char *expr, t_token *token, t_heap *stack)
{
	int		nb;

	nb = 0;
	if (token->next == OPERATOR)
		token->error = 1;
	else
	{
		nb = atoi_base(expr, token) * token->sign;
		token->sign = 1;
		push_token(nb, token, &stack->nb, NUMBER);
		token->next = OPERATOR;
	}
}

void		eval_operator(char *expr, t_token *token, t_heap *stack)
{
	t_type	current;

	current = token->type[(int)expr[token->cursor]];
	if (token->next == OPERAND && expr[token->cursor] == '-')
		token->sign *= -1;
	else if (token->next == OPERAND && expr[token->cursor] != '-')
		token->error = 1;
	else if (expr[token->cursor] == '<' && expr[token->cursor + 1] != '<')
		token->error = 1;
	else if (expr[token->cursor] == '>' && expr[token->cursor + 1] != '>')
		token->error = 1;
	else
	{
		if (current <= stack->op->rank && stack->op->rank != DELIMITER)
			eval_stack(expr, token, stack, INFERIOR_OP);
		else
			push_token(expr[token->cursor], token, &stack->op, current);
		token->next = OPERAND;
	}
	if (expr[token->cursor] == '>' || expr[token->cursor] == '<')
		token->cursor++;
}

void		eval_bracket(char *expr, t_token *token, t_heap *stack)
{
	if (expr[token->cursor] == '(')
	{
		token->bracket++;
		if (token->next == OPERATOR)
			token->error = 1;
		else
		{
			push_token(expr[token->cursor], token, &stack->op, BRACKET);
			token->next = OPERAND;
		}
	}
	else
	{
		token->bracket--;
		if (token->next == OPERAND)
			token->error = 1;
		else
		{
			eval_stack(expr, token, stack, CLOSED_BRACKET);
			token->next = OPERATOR;
		}
	}
	if (token->bracket < 0)
		token->error = 1;
}

void		eval_invalid(char *expr, t_token *token)
{
	(void)expr;
	token->error = 1;
}

void		eval_whitespace(void)
{
}
