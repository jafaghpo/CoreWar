# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 20:51:34 by jafaghpo          #+#    #+#              #
#    Updated: 2018/02/15 19:07:30 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG				=	no

NAME				=	disas

CC					=	gcc
CFLAGS				=	-Werror -Wextra -Wall

SRC_PATH			=	src
SRCS				=	op.c main.c get_binary.c parse_file.c parse_args.c win.c display.c
SRC					=	$(addprefix $(SRC_PATH)/, $(SRCS))

OBJ_PATH			=	obj
OBJ					=	$(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

ifeq ($(DEBUG), yes)
	CFLAGS			+=	-g -D DEBUG
else
	CFLAGS			+=	-Ofast
endif

INCL_PATH			=	include
OP_INC_PATH			=	../include
INCL				=	$(INCL_PATH)/disas.h $(OP_INC_PATH)/op.h

LIB_PATH			=	../lib

LIBFT_DIR			=	$(LIB_PATH)/libft
LIBFT				=	$(LIBFT_DIR)/libft.a
LIBFT_INCL_DIR		=	$(LIBFT_DIR)/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBFT) $(CFLAGS) -lncurses

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCL)
	gcc -o $@ -c $< $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
