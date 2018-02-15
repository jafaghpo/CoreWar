# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 19:20:07 by jafaghpo          #+#    #+#              #
#    Updated: 2018/02/15 15:35:08 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_DIR			=	assembly
ASM_NAME		=	asm

DISAS_DIR		=	disassembly
DISAS_NAME		=	disas

VM_DIR			=	vm
VM_NAME			=	corewar

LIB_SRC_PATH	=	lib_src
LIB_PATH		=	lib


all: .libs $(ASM_NAME) $(DISAS_NAME) $(VM_NAME)

$(ASM_NAME): $(ASM_DIR)/$(ASM_NAME)
	rsync -u $< $@

$(ASM_DIR)/asm: .libs
	make -j -C $(ASM_DIR)

$(DISAS_NAME): $(DISAS_DIR)/$(DISAS_NAME)
	rsync -u $< $@

$(DISAS_DIR)/disas: .libs
	make -j -C $(DISAS_DIR)

$(VM_NAME): $(VM_DIR)/corewar
	rsync -u $< $@

$(VM_DIR)/corewar: .libs
	make -j -C $(VM_DIR)

.libs:
	make -j $(LIB_PATH)
	make -j ft mat sdl2 sdl2_image freetype
	touch .libs

$(LIB_PATH):
	mkdir $(LIB_PATH)

ft: $(LIB_PATH)/libft
	make -j "DEBUG=$(DEBUG)" "TIME=$(TIME)" -C $(LIB_SRC_PATH)/libft
	cp $(LIB_SRC_PATH)/libft/libft.a $(LIB_PATH)/libft
	cp -R $(LIB_SRC_PATH)/libft/include $(LIB_PATH)/libft

mat: $(LIB_PATH)/libmat
	make -j "DEBUG=$(DEBUG)" "TIME=$(TIME)" -C $(LIB_SRC_PATH)/libmat
	cp $(LIB_SRC_PATH)/libmat/libmat.a $(LIB_PATH)/libmat
	cp -R $(LIB_SRC_PATH)/libmat/include $(LIB_PATH)/libmat

sdl2: $(LIB_PATH)/SDL2
	cd $(LIB_SRC_PATH)/SDL2 && \
	./configure --prefix=$(shell pwd)/$(LIB_PATH)/SDL2 && \
	make -j install

sdl2_image: $(LIB_PATH)/SDL2 sdl2
	cd $(LIB_SRC_PATH)/SDL2_image && \
	./configure --prefix=$(shell pwd)/$(LIB_PATH)/SDL2 && \
	make -j install

freetype: $(LIB_PATH)/freetype
	cd $(LIB_SRC_PATH)/freetype && \
	./configure --prefix=$(shell pwd)/$(LIB_PATH)/freetype && \
	make -j install

$(LIB_PATH)/libft: $(LIB_PATH)
	mkdir $(LIB_PATH)/libft

$(LIB_PATH)/libmat: $(LIB_PATH)
	mkdir $(LIB_PATH)/libmat

$(LIB_PATH)/SDL2: $(LIB_PATH)
	mkdir $(LIB_PATH)/SDL2

$(LIB_PATH)/freetype: $(LIB_PATH)
	mkdir $(LIB_PATH)/freetype

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
	rm -f .libs
	rm -Rf $(LIB_PATH)

re: fclean
	make -j

.PHONY: all $(ASM_NAME) $(DISAS_NAME) $(VM_NAME) ft mat sdl2 sdl2_image freetype clean fclean re
