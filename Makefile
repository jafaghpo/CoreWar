# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 19:20:07 by jafaghpo          #+#    #+#              #
#    Updated: 2018/02/15 19:04:53 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_DIR			=	assembly
ASM_NAME		=	asm

DISAS_DIR		=	disassembly
DISAS_NAME		=	disas

VM_DIR			=	vm
VM_NAME			=	corewar

LIB_PATH		=	lib

LIBFT_DIR		=	$(LIB_PATH)/libft
LIBMAT_DIR		=	$(LIB_PATH)/libmat

LIBFT			=	$(LIBFT_DIR)/libft.a
LIBMAT			=	$(LIBMAT_DIR)/libmat.a

all: $(LIBFT) $(LIBMAT) $(ASM_NAME) $(DISAS_NAME) $(VM_NAME)

$(ASM_NAME): $(ASM_DIR)/$(ASM_NAME)
	rsync -u $< $@

$(ASM_DIR)/asm: $(LIBFT) $(LIBMAT)
	make -j -C $(ASM_DIR)

$(DISAS_NAME): $(DISAS_DIR)/$(DISAS_NAME)
	rsync -u $< $@

$(DISAS_DIR)/disas: $(LIBFT) $(LIBMAT)
	make -j -C $(DISAS_DIR)

$(VM_NAME): $(VM_DIR)/corewar
	rsync -u $< $@

$(VM_DIR)/corewar: $(LIBFT) $(LIBMAT)
	make -j -C $(VM_DIR)

$(LIBFT):
	make -j -C $(LIBFT_DIR)

$(LIBMAT):
	make -j $(LIBFT_DIR)

clean:
	make -C $(ASM_DIR) clean
	make -C $(DISAS_DIR) clean
	make -C $(VM_DIR) clean

fclean:
	make -C $(ASM_DIR) fclean
	make -C $(DISAS_DIR) fclean
	make -C $(VM_DIR) fclean
	rm -f $(ASM_NAME)
	rm -f $(DISAS_NAME)
	rm -f $(VM_NAME)

re: fclean
	make -j

.PHONY: all $(ASM_NAME) $(DISAS_NAME) $(VM_NAME) clean fclean re
