/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_getdaymonth.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:57:40 by iburel            #+#    #+#             */
/*   Updated: 2017/04/04 12:02:12 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

time_t		ft_getmonth(time_t *k, time_t bis)
{
	if ((*k -= 31) < 0)
		return (1 + (*k += 31) * 0);
	if ((*k -= 28 + bis) < 0)
		return (2 + (*k += 28 + bis) * 0);
	if ((*k -= 31) < 0)
		return (3 + (*k += 31) * 0);
	if ((*k -= 30) < 0)
		return (4 + (*k += 30) * 0);
	if ((*k -= 31) < 0)
		return (5 + (*k += 31) * 0);
	if ((*k -= 30) < 0)
		return (6 + (*k += 30) * 0);
	if ((*k -= 31) < 0)
		return (7 + (*k += 31) * 0);
	if ((*k -= 31) < 0)
		return (8 + (*k += 31) * 0);
	if ((*k -= 30) < 0)
		return (9 + (*k += 30) * 0);
	if ((*k -= 31) < 0)
		return (10 + (*k += 31) * 0);
	if ((*k -= 30) < 0)
		return (11 + (*k += 30) * 0);
	if ((*k -= 31) < 0)
		return (12 + (*k += 31) * 0);
	return (0);
}

void		ft_day(time_t d, char **str)
{
	if (!(*str = (char *)malloc(sizeof(**str) * 25)))
		ft_afferror("error malloc in ft_printf_ktoa");
	if (d == 0)
		ft_strcpy(*str, "Lun ");
	else if (d == 1)
		ft_strcpy(*str, "Mar ");
	else if (d == 2)
		ft_strcpy(*str, "Mer ");
	else if (d == 3)
		ft_strcpy(*str, "Jeu ");
	else if (d == 4)
		ft_strcpy(*str, "Ven ");
	else if (d == 5)
		ft_strcpy(*str, "Sam ");
	else if (d == 6)
		ft_strcpy(*str, "Dim ");
}

void		ft_month(time_t m, char *str)
{
	if (m == 1)
		ft_strcpy(str + 4, "Jan ");
	else if (m == 2)
		ft_strcpy(str + 4, "Fev ");
	else if (m == 3)
		ft_strcpy(str + 4, "Mar ");
	else if (m == 4)
		ft_strcpy(str + 4, "Avr ");
	else if (m == 5)
		ft_strcpy(str + 4, "Mai ");
	else if (m == 6)
		ft_strcpy(str + 4, "Jun ");
	else if (m == 7)
		ft_strcpy(str + 4, "Jui ");
	else if (m == 8)
		ft_strcpy(str + 4, "Aou ");
	else if (m == 9)
		ft_strcpy(str + 4, "Sep ");
	else if (m == 10)
		ft_strcpy(str + 4, "Oct ");
	else if (m == 11)
		ft_strcpy(str + 4, "Nov ");
	else if (m == 12)
		ft_strcpy(str + 4, "Dec ");
}
