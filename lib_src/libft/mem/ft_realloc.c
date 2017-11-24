/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 04:11:48 by iburel            #+#    #+#             */
/*   Updated: 2017/02/03 04:19:11 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *data, size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
		ft_afferror("error malloc in ft_realloc");
	if (!data)
		return (tmp);
	ft_memmove(tmp, data, size);
	free(data);
	return (tmp);
}
