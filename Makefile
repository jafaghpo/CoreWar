# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 19:20:07 by jafaghpo          #+#    #+#              #
#    Updated: 2018/02/14 21:34:33 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME	= asm
VM_NAME		= corewar

ASM_PATH	= assembler/
VM_PATH		= virtual_machine/

all:

clean:

fclean:

re: fclean all

.PHONY: re fclean clean all
