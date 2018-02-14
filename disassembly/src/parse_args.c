/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:00:51 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/14 23:42:08 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

void			short_arg(t_dfile *file, int isdir)
{
	short	arg;

	arg = 0;
	arg |= file->prog[++file->cursor] << 8;
	arg |= file->prog[++file->cursor];
	if (!isdir)
		display_integer(file, "%hd", arg);
	else
		display_integer(file, "%%%hd", arg);
}

void			int_arg(t_dfile *file)
{
	int		arg;

	arg = 0;
	arg |= file->prog[++file->cursor] << 24;
	arg |= file->prog[++file->cursor] << 16;
	arg |= file->prog[++file->cursor] << 8;
	arg |= file->prog[++file->cursor];
	display_integer(file, "%%%hd", arg);
}

int				first_arg(t_dfile *file, t_uint8 octal, int size)
{
	int		bitwise;

	bitwise = octal & 0b11000000;
	if (bitwise == 0b01000000)
		display_integer(file, "r%d", file->prog[++file->cursor]);
	else if (bitwise == 0b10000000)
	{
		if (size)
			short_arg(file, 1);
		else
			int_arg(file);
	}
	else if (bitwise == 0b11000000)
		short_arg(file, 0);
	else
		return (print_error(ERROR_ARG));
	return (1);
}

int				second_arg(t_dfile *file, t_uint8 octal, int size)
{
	int		bitwise;

	bitwise = octal & 0b00110000;
	if (bitwise == 0b00010000)
		display_integer(file, "r%d", file->prog[++file->cursor]);
	else if (bitwise == 0b00100000)
	{
		if (size)
			short_arg(file, 1);
		else
			int_arg(file);
	}
	else if (bitwise == 0b00110000)
		short_arg(file, 0);
	else
		return (print_error(ERROR_ARG));
	return (1);
}

int				third_arg(t_dfile *file, t_uint8 octal, int size)
{
	int		bitwise;

	bitwise = octal & 0b00001100;
	if (bitwise == 0b00000100)
		display_integer(file, "r%d", file->prog[++file->cursor]);
	else if (bitwise == 0b00001000)
	{
		if (size)
			short_arg(file, 1);
		else
			int_arg(file);
	}
	else if (bitwise == 0b00001100)
		short_arg(file, 0);
	else
		return (print_error(ERROR_ARG));
	return (1);
}
