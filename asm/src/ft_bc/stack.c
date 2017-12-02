/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 19:53:20 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/11/20 21:53:45 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bc.h"

void	push_token(int current, t_token *token, t_stack **stack, t_type rank)
{
	t_stack	*new;

	if (!(new = malloc(sizeof(t_stack))))
	{
		token->error = 1;
		return ;
	}
	new->token = current;
	new->rank = rank;
	new->next = *stack;
	*stack = new;
}

int		pop_token(t_token *token, t_stack **stack)
{
	t_stack	*tmp;
	int		result;

	(void)token;
	tmp = (*stack)->next;
	result = (*stack)->token;
	free(*stack);
	*stack = tmp;
	return (result);
}
