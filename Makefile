# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 19:20:07 by jafaghpo          #+#    #+#              #
#    Updated: 2017/09/07 14:40:27 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_NAME	= asm
VM_NAME		= corewar

ASM_PATH	= assembler/
VM_PATH		= virtual_machine/

all:
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Make Assembler ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(ASM_PATH)
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Make Virtual Machine ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(VM_PATH)
	@cp $(ASM_PATH)/$(ASM_NAME) .
	@cp $(VM_PATH)/$(VM_NAME) .

clean:
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Clean Assembler ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(ASM_PATH) clean
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Clean Virtual Machine ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(VM_PATH) clean

fclean:
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Fclean Assembler ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(ASM_PATH) fclean
	@printf "\n=> \x1B[33mᚔᚔᚔᚔᚔ Fclean Virtual Machine ᚔᚔᚔᚔᚔ\x1b[37m\n"
	@make -C $(VM_PATH) fclean
	@rm -f $(ASM_NAME)
	@rm -f $(VM_NAME)

re: fclean all

.PHONY: re fclean clean all
