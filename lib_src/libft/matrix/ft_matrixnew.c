/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 20:56:42 by iburel            #+#    #+#             */
/*   Updated: 2017/04/09 16:08:46 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	ft_matrixnew(unsigned int ligne, unsigned int colonne)
{
	t_matrix		ret;
	unsigned int	i;

	ret.ligne = ligne;
	ret.colonne = colonne;
	if (!(ret.matrix = (float **)malloc(sizeof(float *) * ligne)))
		exit(0);
	i = 0;
	while (i < ligne)
	{
		if (!(ret.matrix[i] = (float *)malloc(sizeof(float) * colonne)))
			exit(0);
		i++;
	}
	return (ret);
}
