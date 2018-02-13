/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_theme.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iburel <iburel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:44:38 by iburel            #+#    #+#             */
/*   Updated: 2018/02/13 15:17:55 by iburel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char	*ft_strdup_spe(char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] && str[i] != '#')
		i++;
	while (str[i - 1] == ' ' || str[i - 1] == '\t')
		i--;
	if (!(new = malloc(sizeof(*new) * (i + 1))))
		return (NULL);
	ft_memcpy(new, str, i);
	new[i] = 0;
	return (new);
}

void		del_blanks(char **str)
{
	while (**str == ' ' || **str == '\t')
		(*str)++;
}

int			get_filename(char *line, char **str)
{
	del_blanks(&line);
	if (*line != '=')
		return (0);
	line++;
	del_blanks(&line);
	*str = ft_strdup_spe(line);
	return (1);
}

int			get_theme(t_args *flags, char *str)
{
	char	*line;
	char	*tmp;
	t_file	*file;
	int		i;
	int		size;

	(void)flags;
	size = ft_strlen(str);
	if (!(tmp = malloc(sizeof(*tmp) * (6 + size + 1 + size + 1))))
		return (0);
	ft_sprintf(tmp, "theme/%s/%s", str, str);
	if (!(file = ft_fopen(tmp, O_RDONLY)))
		return (ft_printf("error open theme file\n") * 0);
	free(tmp);
	i = 1;
	while (ft_getline(&tmp, file))
	{
		line = tmp;
		del_blanks(&line);
		check_line_theme(line, tmp, i);
		free(tmp);
		i++;
	}
	return (1);
}
