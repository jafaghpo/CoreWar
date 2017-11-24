/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixmult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:56:57 by iburel            #+#    #+#             */
/*   Updated: 2017/04/09 16:12:02 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_case(t_matrix *mat1, t_matrix *mat2, t_uint i, t_uint j)
{
	t_uint	k;
	double	ret;

	ret = 0;
	k = 0;
	while (k < mat1->colonne)
	{
		ret += mat1->matrix[i][k] * mat2->matrix[k][j];
		k++;
	}
	return (ret);
}

t_matrix		ft_matrixmult(t_matrix *mat1, t_matrix *mat2)
{
	t_matrix	ret;
	t_uint		i;
	t_uint		j;

	if (mat1->colonne != mat2->ligne)
		ft_afferror("operation impossible in ft_matrixmult");
	ret = ft_matrixnew(mat1->ligne, mat2->colonne);
	i = 0;
	while (i < ret.ligne)
	{
		j = 0;
		while (j < ret.colonne)
		{
			ret.matrix[i][j] = ft_case(mat1, mat2, i, j);
			j++;
		}
		i++;
	}
	return (ret);
}
