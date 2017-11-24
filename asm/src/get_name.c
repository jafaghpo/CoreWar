/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 18:36:37 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/09/19 21:55:52 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

char	*get_name(char *file)
{
	char	*name;
	size_t	len;

	len = ft_strlen(file);
	if (len < 3 || !ft_strequ(file + len - 2, ".s"))
	{
		ft_printf("%s\n", ERROR_BAD_FORMAT);
		return (NULL);
	}
	if (!(name = malloc(sizeof(*name) * (len + 3))))
		ft_afferror("asm: malloc failure");
	ft_strncpy(name, file, len - 2);
	ft_strcpy(name + len - 2, ".cor");
	return (name);
}
