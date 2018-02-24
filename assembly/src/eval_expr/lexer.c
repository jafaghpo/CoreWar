/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 18:56:54 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/24 17:31:33 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

static int	compare_label(char *s1, char *s2, int i)
{
	while (s1[i] == *s2 && s1[i] && *s2 && ft_strchr(LABEL_CHARS, s1[i]))
	{
		i++;
		s2++;
	}
	if ((s1[i] == ' ' || s1[i] == '\t' || s1[i] == SEPARATOR_CHAR || !s1[i]
	|| !ft_strchr(LABEL_CHARS, s1[i])) && !*s2)
		return (i);
	return (0);
}

static int	get_label_addr(char *str, t_label *labels, t_token *token)
{
	t_lstlb	*tmp;
	int		i;

	tmp = labels->lst;
	while (tmp)
	{
		i = token->cursor;
		if ((i = compare_label(str, tmp->name, i)))
		{
			token->cursor = i;
			return (tmp->addr);
		}
		tmp = tmp->next;
	}
	return (-1);
}

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

	if (t->next == OPERATOR)
		t->error = 1;
	else
	{
		nb = islabel(labels, expr, t);
		push_token(nb, t, &s->nb, NUMBER);
		t->next = OPERATOR;
	}
}

int			lexer(char *expr, t_token *token, t_heap *stack, t_label *labels)
{
	static void		(*eval[8])() = {eval_invalid, eval_whitespace,
	eval_number, label_value, eval_bracket, eval_operator, eval_operator};
	t_type			current;

	while (expr[token->cursor] && expr[token->cursor] != SEPARATOR_CHAR
		&& expr[token->cursor] != COMMENT_CHAR)
	{
		current = token->type[(int)expr[token->cursor]];
		eval[current](expr, token, stack, labels);
		if (token->error)
			return (0);
		token->cursor++;
	}
	if (token->bracket || token->next != OPERATOR)
		token->error = 1;
	eval_stack(expr, token, stack, FINAL);
	return (stack->nb->token);
}
