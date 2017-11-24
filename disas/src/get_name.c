/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 18:36:37 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/09/19 22:02:15 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <disas.h>

char	*get_name(char *file)
{
	char	*name;
	size_t	len;

	len = ft_strlen(file);
	if (len < 5 || !ft_strequ(file + len - 4, ".cor"))
	{
		ft_printf("%s\n", ERROR_BAD_FORMAT);
		return (NULL);
	}
	if (!(name = malloc(sizeof(*name) * (len - 1))))
		ft_afferror(ERROR_MALLOC);
	ft_strncpy(name, file, len - 4);
	ft_strcpy(name + len - 4, ".s");
	return (name);
}
