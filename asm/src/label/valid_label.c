/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 21:56:26 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/11 23:09:39 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			setup_token(char *token, char *label_char)
{
	int		i;

	i = 0;
	while (i < 128)
	{
		token[i] = 0;
		i++;
	}
	i = 0;
	while (label_char[i])
	{
		token[(int)label_char[i]] = 1;
		i++;
	}
}

int					valid_label(char *str)
{
	static char		token[128] = {1};
	int				i;
	int				valid;

	if (token[0] == 1)
		setup_token(token, LABEL_CHARS);
	i = 0;
	valid = 1;
	while (token[(int)str[i])
		i++;
	if (str[i] == LABEL_CHAR)
		return (i + 1);
	while (str[i] != ' ' && str[i] != '\t' && str[i])
		i++;
	if (str[i - 1] == LABEL_CHAR)
		return (-1);
	return (0);
}
