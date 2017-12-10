/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:02:05 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/10 16:22:28 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

int			check_file_ext(char *filename, t_file *file)
{
	size_t	len;

	len = ft_strlen(filename);
	if (!(file->path = malloc(sizeof(char) * len - 1)))
		return (print_error(errno, __func__, __FILE__, __LINE__));
	if (ft_strcmp(filename + len - 4, COR_EXT))
		return (print_error(EINVAL, __func__, __FILE__, __LINE__));
	ft_memcpy(file->path, filename, len - 4);
	ft_memcpy(file->path + len - 4 , DISAS_EXT, 3);
	return (1);
}
