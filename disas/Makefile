# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niragne <niragne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 20:51:34 by jafaghpo          #+#    #+#              #
#    Updated: 2017/09/21 02:37:08 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG				=	yes

NAME				=	disas

SRC_PATH			=	src
SRCS				=	main.c op.c buff.c puterror.c get_name.c disas.c putheader.c
SRC					=	$(addprefix $(SRC_PATH)/, $(SRCS))

OBJ_PATH			=	obj
OBJ					=	$(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

ifeq ($(DEBUG), yes)
	CFLAGS			=	-g
else
	CFLAGS			=	-Werror -Wextra -Wextra -Ofast
endif

INCL_PATH			=	include
OP_INC_PATH			=	../include
INCL				=	$(INCL_PATH)/disas.h $(OP_INC_PATH)/op.h

LIBFT_PATH			=	../lib/libft
LIBFT				=	$(LIBFT_PATH)/libft.a
LIBFT_INCL_PATH		=	$(LIBFT_PATH)/include
LIBFT_INCL			=	$(LIBFT_INCL_PATH)/libft.h

RED					=	\033[1;31m
GREEN				=	\033[1;32m
NC					=	\033[0m

#.SILENT:

all: $(NAME)

$(NAME): void obj $(OBJ) $(LIBFT)
	printf "\n=> \x1B[33mCompiling assembler...\x1b[37m"
	gcc -o $(NAME) $(OBJ) $(LIBFT) $(CFLAGS)
	printf "\n=> \x1B[32mExecutable asm ready !\x1B[37m\n"

void:
	printf "=> \e[38;5;208mMaking assembler obj files... \x1B[37m"

$(LIBFT):
	make "DEBUG=$(DEBUG)" -C $(LIBFT_PATH) str printf mem put file char conv

obj:
	mkdir obj

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCL) 
	gcc -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)
	printf "\e[38;5;208m▒\e[0m"

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ)
	printf "=> \x1B[31mDeleting assembler .obj files...\x1B[37m\n"

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	printf "=> \x1B[31mDeleting executable asm...\x1B[37m\n"

re: fclean all

.PHONY: all clean fclean re
