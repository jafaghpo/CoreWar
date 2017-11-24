/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixaddfloat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:28:41 by iburel            #+#    #+#             */
/*   Updated: 2017/04/09 15:26:19 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrixaddfloat(t_matrix *mat, float x, float y, float z)
{
	unsigned int	i;

	i = 0;
	while (i < mat->colonne)
	{
		mat->matrix[0][i] += x;
		mat->matrix[1][i] += y;
		mat->matrix[2][i] += z;
		i++;
	}
}
