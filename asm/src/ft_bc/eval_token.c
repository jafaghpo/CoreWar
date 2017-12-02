/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:36:19 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/11/20 23:11:22 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bc.h"

void		eval_number(char *expr, t_token *token, t_heap *stack)
{
	int		nb;

	nb = 0;
	if (token->next == operator)
		token->error = 1;
	else
	{
		nb = atoi_base(expr, token) * token->sign;
		token->sign = 1;
		push_token(nb, token, &stack->nb, number);
		token->next = operator;
	}
}

void		eval_operator(char *expr, t_token *token, t_heap *stack)
{
	t_type	current;

	current = token->type[(int)expr[token->cursor]];
	if (token->next == operand && expr[token->cursor] == '-')
		token->sign *= -1;
	else if (token->next == operand && expr[token->cursor] != '-')
		token->error = 1;
	else if (expr[token->cursor] == '<' && expr[token->cursor + 1] != '<')
		token->error = 1;
	else if (expr[token->cursor] == '>' && expr[token->cursor + 1] != '>')
		token->error = 1;
	else
	{
		if (current <= stack->op->rank && stack->op->rank != delimiter)
			eval_stack(expr, token, stack, inferior_op);
		else
			push_token(expr[token->cursor], token, &stack->op, current);
		token->next = operand;
	}
	if (expr[token->cursor] == '>' || expr[token->cursor] == '<')
		token->cursor++;
}

void		eval_bracket(char *expr, t_token *token, t_heap *stack)
{
	if (expr[token->cursor] == '(')
	{
		token->bracket++;
		if (token->next == operator)
			token->error = 1;
		else
		{
			push_token(expr[token->cursor], token, &stack->op, bracket);
			token->next = operand;
		}
	}
	else
	{
		token->bracket--;
		if (token->next == operand)
			token->error = 1;
		else
		{
			eval_stack(expr, token, stack, closed_bracket);
			token->next = operator;
		}
	}
	if (bracket < 0)
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
