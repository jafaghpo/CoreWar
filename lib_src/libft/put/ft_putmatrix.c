/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:55:13 by iburel            #+#    #+#             */
/*   Updated: 2017/03/13 20:55:16 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmatrix(t_matrix *mat)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < mat->ligne)
	{
		j = 0;
		while (j < mat->colonne)
		{
			ft_printf("%6.1f", mat->matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
