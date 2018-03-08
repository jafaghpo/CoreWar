/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:08:42 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 21:34:32 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_path(char *file)
{
	char	*path;
	size_t	len;

	len = ft_strlen(file);
	if (len < 3 || !ft_strequ(file + len - 2, ".s"))
	{
		print_error(EXTENSION, file);
		return (NULL);
	}
	if (!(path = malloc(sizeof(*path) * (len + 3))))
	{
		print_error(0, strerror(errno));
		return (NULL);
	}
	ft_strncpy(path, file, len - 2);
	ft_strcpy(path + len - 2, ".cor");
	return (path);
}
