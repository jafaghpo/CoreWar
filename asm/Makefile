# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jafaghpo <jafaghpo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 20:51:34 by jafaghpo          #+#    #+#              #
#    Updated: 2018/01/06 16:38:26 by jafaghpo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG				=	no

NAME				=	asm

CC					=	gcc
CFLAGS				=	-Werror -Wextra -Wextra

SRC_PATH			=	src
SRCS				=	main.c
SRC					=	$(addprefix $(SRC_PATH)/, $(SRCS))

OBJ_PATH			=	obj
OBJ					=	$(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

include src/general/general.mk
include src/parsing/parse.mk
include src/visual/visual.mk
include src/label/label.mk
#include src/eval_expr/eval_expr.mk

ifeq ($(DEBUG), yes)
	CFLAGS			+=	-g -D DEBUG
else
	CFLAGS			+=	-Ofast
endif

INCL_PATH			=	include
OP_INC_PATH			=	../include
INCL				=	$(INCL_PATH)/asm.h $(OP_INC_PATH)/op.h $(INCL_PATH)/eval_expr.h

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
