/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:00:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/15 22:09:28 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int			parse_arg(t_file *file, int i)
{
	int		size;
	int		nb_args;

	size = g_optab[file->prog[i]].size;
	nb_args = g_optab[file->prog[i]].nb_args;
	
	return (i);
}
