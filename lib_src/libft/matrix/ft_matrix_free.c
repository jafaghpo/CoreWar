/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 17:11:21 by iburel            #+#    #+#             */
/*   Updated: 2017/02/12 17:14:02 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_matrix_free(t_matrix *matrix)
{
	unsigned int	i;

	i = 0;
	while (i < matrix->ligne)
	{
		free(matrix->matrix[i]);
		i++;
	}
	free(matrix->matrix);
}
