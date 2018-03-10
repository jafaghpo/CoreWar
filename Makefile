# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 19:20:07 by jafaghpo          #+#    #+#              #
#    Updated: 2018/03/10 13:51:32 by iburel           ###   ########.fr        #
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

$(ASM_DIR)/$(ASM_NAME): $(LIBFT) $(LIBMAT)
	make -C $(ASM_DIR)

$(DISAS_NAME): $(DISAS_DIR)/$(DISAS_NAME)
	rsync -u $< $@

$(DISAS_DIR)/$(DISAS_NAME): $(LIBFT) $(LIBMAT)
	make -C $(DISAS_DIR)

$(VM_NAME): $(VM_DIR)/$(VM_NAME)
	rsync -u $< $@

$(VM_DIR)/$(VM_NAME): $(LIBFT) $(LIBMAT)
	make -C $(VM_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBMAT):
	make $(LIBFT_DIR)

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
	make

.PHONY: all $(ASM_NAME)  $(DISAS_NAME) $(VM_NAME) $(ASM_DIR)/$(ASM_NAME) $(DISAS_DIR)/$(DISAS_NAME) $(VM_DIR)/$(VM_NAME) clean fclean re
