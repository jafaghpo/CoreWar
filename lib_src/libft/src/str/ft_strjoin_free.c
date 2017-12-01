/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 21:51:08 by iburel            #+#    #+#             */
/*   Updated: 2017/02/09 17:13:59 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, unsigned short int c)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (c == 'L' || c == 'L' + 'R')
		free(s1);
	if (c == 'R' || c == 'L' + 'R')
		free(s2);
	return (tmp);
}
