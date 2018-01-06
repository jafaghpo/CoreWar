/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:08:42 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/01/06 16:57:54 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_name(char *file)
{
	char	*name;
	size_t	len;

	len = ft_strlen(file);
	if (len < 3 || !ft_strequ(file + len - 2, ".s"))
	{
		print_error(0, ERROR_EXT, file);
		return (NULL);
	}
	if (!(name = malloc(sizeof(*name) * (len + 3))))
	{
		print_error(0, ERROR_MEM, strerror(errno), "name");
		return (NULL);
	}
	ft_strncpy(name, file, len - 2);
	ft_strcpy(name + len - 2, ".cor");
	return (name);
}
