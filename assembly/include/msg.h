/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:39:31 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/03/08 21:25:07 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

/*
**	-- Compilation messages --
*/

# define COMPILATION_START	"Compiling %s\n"
# define COMPILATION_END	"Compilation done in %s\n"

/*
**	-- Error messages --
*/

# define NO_PARAMETER		"missing parameters"
# define USAGE				"usage: ./asm [-wv] file ..."
# define EXTENSION			"invalid file extension: \"%s\""
# define OPTION				"illegal option -- %c"
# define UNKNOWN_FILE		"%s: %s"
# define SYNTAX				"invalid syntax: \"%s\""
# define HEADER_LINE		"invalid line in champion header: \"%s\""
# define NAME_SIZE			"invalid name size\n"
# define COMMENT_SIZE		"invalid comment size\n"
# define LABEL_SYNTAX		"invalid label syntax: \"%s\""
# define UNKNOWN_INST		"unknown instruction: \"%s\""
# define REGISTER_ARG		"invalid register: \"%s\""
# define DIRECT_ARG			"invalid direct argument: \"%s\""
# define INDIRECT_ARG		"invalid indirect argument: \"%s\""
# define ARG_NUMBER			"invalid number of argument: \"%s\""
# define NO_SEPARATOR		"missing separator between args: \"%s\""
# define UNDEF_LABEL		"undefined label: \"%s\""
# define DUPLICATE_LABEL	"duplicate label name: \"%s\""

/*
**	-- Flag -s (size) messages --
*/

# define PROG_SIZE_MSG		"Program size is \033[31m%d\033[0m bytes\n"
# define PROG_SIZE_WARNING	"%sWarning:%s too large size [max: %d bytes]\n"

#endif
