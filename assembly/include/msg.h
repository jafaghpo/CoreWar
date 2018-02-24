/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:39:31 by jafaghpo          #+#    #+#             */
/*   Updated: 2018/02/24 16:53:32 by jafaghpo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSG_H
# define MSG_H

/*
**	-- Compilation messages --
*/

# define COMPILATION_START	"Compiling \033[31m%s\033[0m\n"
# define COMPILATION_END	"Compilation done in \033[31m%s\033[0m\n"

/*
**	-- Error messages --
*/

# define NO_PARAMETER	"missing parameters\n%s"
# define USAGE			"usage: ./asm [-wv] file ..."
# define EXTENSION		"invalid file extension: \033[31m\"%s\"\033[0m"
# define OPTION			"illegal option -- \033[31m%c\033[0m\n%s"
# define UNKNOWN_FILE	"\033[31m%s: \033[0m%s"
# define NO_NAME		"missing champion name"
# define NO_COMMENT		"missing champion comment"
# define SYNTAX			"invalid syntax: \033[31m\"%s\"\033[0m"
# define HEADER_LINE	"invalid line in champion header: \033[31m\"%s\"\033[0m"
# define LABEL_SYNTAX	"invalid label syntax: \033[31m\"%s\"\033[0m"
# define UNKNOWN_INST	"unknown instruction: \033[31m\"%s\"\033[0m"
# define REGISTER_ARG	"invalid register: \033[31m\"%s\"\033[0m"
# define DIRECT_ARG		"invalid direct argument: \033[31m\"%s\"\033[0m"
# define INDIRECT_ARG	"invalid indirect argument: \033[31m\"%s\"\033[0m"
# define ARG_NUMBER		"invalid number of argument: \033[31m\"%s\"\033[0m"
# define NO_SEPARATOR	"missing separator between args: \033[31m\"%s\"\033[0m"
# define UNDEF_LABEL	"undefined label: \033[31m\"%s\"\033[0m"

/*
**	-- Flag -s (size) messages --
*/

# define PROG_SIZE_MSG		"Program size is \033[31m%d\033[0m bytes\n"
# define PROG_SIZE_WARNING	"%sWarning:%s too large size [max: %d bytes]\n"

#endif
