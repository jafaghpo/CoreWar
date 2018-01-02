/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_addr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:15:28 by iburel            #+#    #+#             */
/*   Updated: 2017/11/29 17:06:53 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	strcmp_spe(char *s1, char *s2, t_token *token, int *i)
{
	while (s1[*i] == *s2 && token->type[s1[*i]] < bracket 
		&& token->type[s1[*i]] != whitespace && s1[*i])
	{
		(*i)++;
		s2++;
	}
	return (token->type[s1[*i]] >= bracket 
	|| token->type[s1[*i]] == whitespace || !s1[*i]);
}

int		get_label_addr(char *str, t_label *labels, t_token *token)
{
	t_lstlb	*tmp;
	int		i;

	tmp = labels->lst;
	while (tmp)
	{
		i = token->cursor;
		if (strcmp_spe(str, tmp->name, token, &i))
		{
			token->cursor = i;
			return (tmp->addr);
		}
		tmp = tmp->next;
	}
	return (-1);
}
