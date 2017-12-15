# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 20:51:34 by jafaghpo          #+#    #+#              #
#    Updated: 2017/12/15 21:35:18 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG				=	no
TIME				=	no

NAME				=	asm

CC					=	gcc
CFLAGS				=	-Werror -Wextra -Wextra

SRC_PATH			=	src
SRCS				=	op.c buff.c parse.c main.c get_name.c puterror.c \
						analyze_line.c split_spe.c putpars.c pars_inst.c \
						point.c wordlen.c add_label.c check_label.c fill_size.c \
						pars_args.c get_label_addr.c get_opcode.c putlabels.c \
						add_tmplb.c check_tmplb.c verif_tmp.c arglen.c labelcmp.c \
						labeldup.c
SRC					=	$(addprefix $(SRC_PATH)/, $(SRCS))

OBJ_PATH			=	obj
OBJ					=	$(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

include $(SRC_BC_PATH)/ft_bc.mk

ifeq ($(DEBUG), yes)
	CFLAGS			+=	-g -D DEBUG
else
	CFLAGS			+=	-Ofast
endif

ifeq ($(TIME), yes)
	CFLAGS			+=	-pg
endif

INCL_PATH			=	include
OP_INC_PATH			=	../include
INCL				=	$(INCL_PATH)/asm.h $(OP_INC_PATH)/op.h $(INCL_PATH)/ft_bc.h

LIB_PATH			=	../lib_src

LIBFT_PATH			=	$(LIB_PATH)/libft
LIBFT				=	$(LIBFT_PATH)/libft.a
LIBFT_INCL_PATH		=	$(LIBFT_PATH)/include


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(CFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCL) 
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_PATH)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
