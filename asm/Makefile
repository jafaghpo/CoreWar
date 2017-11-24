# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niragne <niragne@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 20:51:34 by jafaghpo          #+#    #+#              #
#    Updated: 2017/10/14 23:27:46 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG				=	no
TIME				=	no

NAME				=	asm

SRC_PATH			=	src
SRCS				=	op.c buff.c parse.c main.c get_name.c puterror.c \
						analyze_line.c split_spe.c putpars.c pars_inst.c \
						point.c wordlen.c add_label.c check_label.c fill_size.c \
						pars_args.c get_label_addr.c get_opcode.c putlabels.c \
						add_tmplb.c check_tmplb.c verif_tmp.c arglen.c labelcmp.c \
						labeldup.c atoi_base.c eval_expr.c rmspace.c
SRC					=	$(addprefix $(SRC_PATH)/, $(SRCS))

OBJ_PATH			=	obj
OBJ					=	$(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

ifeq ($(DEBUG), yes)
	CFLAGS			=	-g -D DEBUG
else
	CFLAGS			=	-Werror -Wextra -Wextra -Ofast -U DEBUG
endif

ifeq ($(TIME), yes)
	OPTI			=	-pg
endif

INCL_PATH			=	include
OP_INC_PATH			=	../include
INCL				=	$(INCL_PATH)/asm.h $(OP_INC_PATH)/op.h

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
	gcc -o $(NAME) $(OBJ) $(LIBFT) $(CFLAGS) $(OPTI)
	printf "\n=> \x1B[32mExecutable asm ready !\x1B[37m\n"

void:
	printf "=> \e[38;5;208mMaking assembler obj files... \x1B[37m"

$(LIBFT):
	make "DEBUG=$(DEBUG)" -C $(LIBFT_PATH) str printf mem put file char

obj:
	mkdir obj

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCL) 
	gcc -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH) $(OPTI)
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
