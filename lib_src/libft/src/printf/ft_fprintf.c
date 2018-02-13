/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:44:25 by root              #+#    #+#             */
/*   Updated: 2018/02/10 14:42:28 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_fprintf(int fd, char *format, ...)
{
	va_list arg;
	int		done;

	va_start(arg, format);
	done = ft_vfprintf(fd, format, arg);
	va_end(arg);
	return (done);
}
