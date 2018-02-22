/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 17:48:21 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/22 17:48:22 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

static void		init_next(t_type *type)
{
	type['&'] = low_op;
	type['|'] = low_op;
	type['^'] = low_op;
	type['<'] = low_op;
	type['>'] = low_op;
	type['%'] = high_op;
	type[LABEL_CHAR] = label;
}

static void		init_type(t_type *type)
{
	int			i;

	i = -1;
	while (++i < 256)
		type[i] = invalid;
	i = '0' - 1;
	while (++i <= '9')
		type[i] = number;
	i = 'a' - 1;
	while (++i <= 'f')
		type[i] = number;
	i = 'A' - 1;
	while (++i <= 'F')
		type[i] = number;
	type[' '] = whitespace;
	type['\t'] = whitespace;
	type['+'] = low_op;
	type['-'] = low_op;
	type['*'] = high_op;
	type['/'] = high_op;
	type['('] = bracket;
	type[')'] = bracket;
	init_next(type);
}

static t_stack	*init_stack(int *error)
{
	t_stack		*stack;

	if (!(stack = malloc(sizeof(t_stack))))
	{
		ft_printf("Error: malloc failure\n");
		*error = 1;
		return (NULL);
	}
	stack->token = 0;
	stack->rank = delimiter;
	stack->next = NULL;
	return (stack);
}

void			free_stack(t_heap *stack)
{
	t_stack		*tmp;

	while (stack->op)
	{
		tmp = stack->op->next;
		ft_memdel((void**)&stack->op);
		stack->op = tmp;
	}
	while (stack->nb)
	{
		tmp = stack->nb->next;
		ft_memdel((void**)&stack->nb);
		stack->nb = tmp;
	}
}

int				eval_expr(char *expr, t_label *labels, int *error, int size)
{
	t_token			token;
	t_heap			stack;
	static t_type	type[256] = {1};
	int				result;

	if (type[0] == 1)
		init_type(type);
	token = (t_token){type, operand, 0, 0, 1, 0, size};
	stack = (t_heap){init_stack(error), init_stack(error)};
	result = lexer(expr, &token, &stack, labels);
	free_stack(&stack);
	*error = token.error;
	if (*error == 2)
		return (2);
	return (result);
}
