/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:22:46 by jafaghpo          #+#    #+#             */
/*   Updated: 2017/12/15 18:18:55 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disas.h"

static int		check_binary_extension(char *filename, t_file *file)
{
	size_t		len;

	len = ft_strlen(filename);
	if (!(file->path = malloc(sizeof(char) * len - 1)))
		return (print_error(NULL, __func__, __FILE__, __LINE__));
	if (ft_strcmp(filename + len - 4, COR_EXT))
		return (print_error(E_EXT, __func__, __FILE__, __LINE__));
	ft_memcpy(file->path, filename, len - 4);
	ft_memcpy(file->path + len - 4 , DISAS_EXT, 3);
	return (1);
}

static t_uint8	*file_to_string(char *path, int *ret)
{
	char		tmp[BSIZE + 1];
	t_uint8		*str;
	int			fd;

	str = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (!print_error(NULL, __func__, __FILE__, __LINE__) ? NULL : str);
	if ((*ret = read(fd, tmp, BSIZE)) < 0)
		return (!print_error(NULL, __func__, __FILE__, __LINE__) ? NULL : str);
	if (*ret == BSIZE)
		return (!print_error(E_LEN, __func__, __FILE__, __LINE__) ? NULL : str);
	if (!(str = malloc(sizeof(*str) * (*ret))))
		return (!print_error(NULL, __func__, __FILE__, __LINE__) ? NULL : str);
	tmp[*ret] = 0;
	ft_memcpy(str, tmp, *ret);
	if (close(fd) < 0)
		return (!print_error(NULL, __func__, __FILE__, __LINE__) ? NULL : str);
	return (str);
}

static int		check_magic(t_uint8 *str)
{
	int			magic;

	magic = 0;
	magic |= str[0] << 24;
	magic |= str[1] << 16;
	magic |= str[2] << 8;
	magic |= str[3] << 0;
	if (magic != COREWAR_EXEC_MAGIC)
		return (print_error(E_MGC, __func__, __FILE__, __LINE__));
	return (1);
}

int				get_binary(t_file *file, char *path)
{
	int			ret;
	t_uint8		*str;

	ret = 0;
	if (!check_binary_extension(path, file))
		return (0);
	if (!(str = file_to_string(path, &ret)))
		return (0);
	if (!check_magic(str))
		return (0);
	ft_memcpy(file->name, str + 4, PROG_NAME_LENGTH);
	ft_memcpy(file->comment, str + PROG_NAME_LENGTH + 8 + 4, COMMENT_LENGTH);
	file->prog_size = ret - HEADER_SIZE;
	if (!(file->prog = malloc(sizeof(char) * file->prog_size)))
		return (print_error(NULL, __func__, __FILE__, __LINE__));
	ft_memcpy(file->prog, str + HEADER_SIZE, file->prog_size);
	return (1);
}
