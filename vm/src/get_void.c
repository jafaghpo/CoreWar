/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_void.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggregoir <ggregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:13:57 by niragne           #+#    #+#             */
/*   Updated: 2018/02/05 16:11:00 by ggregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_int32		get_void(t_uint32 pc, t_inst *args, t_int8 index, t_int8 octal)
{
	(void)pc;
	(void)args;
	(void)index;
	(void)octal;
	return (0);
}
