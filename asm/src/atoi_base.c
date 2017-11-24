/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:16:34 by iburel            #+#    #+#             */
/*   Updated: 2017/09/18 17:11:02 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	isdigitbase(char c, int base)
{
	if (base <= 10)
		return ((c >= '0' && c <= base + '0' - 1));
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= base - 10 + 'a' - 1) ||
			(c >= 'A' && c <= base - 10 + 'A' - 1));
}

static int	get_base(char **str)
{
	if ((*str)[0] != '0' || (*str)[1] == '\0')
		return (10);
	if ((*str)[1] == 'x' || (*str)[1] == 'X')
	{
		*str += 2;
		return (16);
	}
	if ((*str)[1] == 'b' || (*str)[1] == 'B')
	{
		*str += 2;
		return (2);
	}
	else
	{
		*str += 1;
		return (8);
	}
	return (-1);
}

static int	get_nb(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	return (c - 'A' + 10);
}

int			atoi_base(char *str, int *error)
{
	int		n;
	int		base;
	int		sign;

	*error = 0;
	sign = 1;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	base = get_base(&str);
	if (!isdigitbase(*str, base))
		*error = 1;
	n = 0;
	while (isdigitbase(*str, base))
	{
		n = n * base + get_nb(*str);
		str++;
	}
	if (*str)
		*error = 1;
	return (n * sign);
}
