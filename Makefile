# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 19:20:07 by jafaghpo          #+#    #+#              #
#    Updated: 2018/02/15 12:51:57 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_DIR			=	assembly
ASM_NAME		=	asm

DISAS_DIR		=	disassembly
DISAS_NAME		=	disas

VM_DIR			=	vm
VM_NAME			=	corewar

all: $(ASM_NAME) $(DISAS_NAME) $(VM_NAME)

$(ASM_NAME): $(ASM_DIR)/$(ASM_NAME)
	rsync -u $< $@

$(ASM_DIR)/asm:
	make -C $(ASM_DIR)

$(DISAS_NAME): $(DISAS_DIR)/$(DISAS_NAME)
	rsync -u $< $@

$(DISAS_DIR)/disas:
	make -C $(DISAS_DIR)

$(VM_NAME): $(VM_DIR)/corewar
	rsync -u $< $@

$(VM_DIR)/corewar:
	make -C $(VM_DIR)

clean:
	make -C $(ASM_DIR) clean
	make -C $(DISAS_DIR) clean
	make -C $(VM_DIR) clean

fclean:
	make -C $(ASM_DIR) fclean
	make -C $(DISAS_DIR) fclean
	make -C $(VM_DIR) fclean
	rm -Rf $(ASM_NAME)
	rm -Rf $(DISAS_NAME)
	rm -Rf $(VM_NAME)

re: fclean all

.PHONY: re $(ASM_NAME) $(DISAS_NAME) $(VM_NAME) clean fclean all
