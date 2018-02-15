# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/06 20:51:34 by jafaghpo          #+#    #+#              #
#    Updated: 2018/02/15 15:06:08 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG					=	no
TIME					=	no

NAME					=	corewar
CFLAGS					=	-Wall -Wextra -Werror

ifeq ($(DEBUG), yes)
	CFLAGS				+= -g -D DEBUG# -fsanitize=address
else
	CFLAGS				+=
endif

ifeq ($(TIME), yes)
	CFLAGS				+=	-pg
endif

PATH_PROJECT 			=	$(shell pwd)

SRC_PATH				=	src
SRCS					=	parse_flags.c flags_v.c add_file.c get_nums.c get_dumps.c \
							fill_pos_players.c get_players.c get_uint32.c get_uint16.c \
							load_players.c debug.c vm.c op.c init_proc.c insert_proc.c \
							get_args.c check_type.c get_reg.c get_dir.c \
							get_ind.c get_void.c live.c get_mod.c put_uint32.c \
							create_proc.c get_real_value.c ft_abs.c check_reg.c \
							exec_procs_foreach.c exec_proc.c get_player_id.c purge.c \
							pick_winner.c keyhook.c get_breakpoints.c \
							bubble_tab.c get_sleep.c end_game.c move_procs_foreach.c \
							move_proc.c settings.c clear_new.c add_clear_new.c get_theme.c \
							free_files.c checkandcolor.c main.c

SRC_OP_PATH				=	$(SRC_PATH)/op
SRCS_OP					=	op_live.c op_ld.c op_st.c op_add.c op_sub.c op_and.c \
							op_or.c op_xor.c op_zjmp.c op_ldi.c op_sti.c op_fork.c \
							op_lld.c op_lldi.c op_lfork.c op_aff.c op_win.c

SRC_DISPLAY_PATH		=	$(SRC_PATH)/display
SRCS_DISPLAY			=	display.c init_sdl.c init_gl.c shader_build.c load_image.c \
							get_alpha.c event.c create_prog.c numbers2.c init.c \
							load_screen.c square_texture.c init_freetype.c chat.c \
							numbers.c load_hud.c add_text.c start_music.c

SRC						=	$(addprefix $(SRCS_PATH)/, $(SRCS))
SRC						+=	$(addprefix $(SRCS_OP_PATH)/, $(SRCS_OP))
SRC						+=	$(addprefix $(SRCS_DISPLAY_PATH)/, $(SRCS_DISPLAY))

OBJ_PATH				=	obj
OBJ						=	$(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))
OBJ						+=	$(addprefix $(OBJ_PATH)/, $(SRCS_OP:.c=.o))
OBJ						+=	$(addprefix $(OBJ_PATH)/, $(SRCS_DISPLAY:.c=.o))

INCL_PATH				=	include
OP_INC_PATH				=	../include
INCL_VM					=	$(INCL_PATH)/vm.h
INCL_DISPLAY			=	$(INCL_PATH)/display.h
INCL_OP					=	$(OP_INC_PATH)/op.h

LIB_SRC_PATH			=	../lib_src
LIB_PATH				=	../lib

LIBOPENGL				=	-framework openGL

LIBSDL2					=	$(LIB_PATH)/SDL2/lib -lSDL2 -lSDL2_image
LIBSDL2_INCL			=	$(LIB_PATH)/SDL2/include

LIBFREETYPE				=	$(LIB_PATH)/freetype/lib -lfreetype
LIBFREETYPE_INCL		=	$(LIB_PATH)/freetype/include

LIBFT					=	$(LIB_PATH)/libft -lft
LIBFT_INCL				=	$(LIB_PATH)/libft/include

LIBMAT					=	$(LIB_PATH)/libmat -lmat
LIBMAT_INCL				=	$(LIB_PATH)/libmat/include


all: $(NAME)

$(NAME): obj $(OBJ)
	gcc -o $(NAME) $(OBJ) -L $(LIBFT) -L $(LIBMAT) -L $(LIBSDL2) -L $(LIBFREETYPE) $(LIBOPENGL) $(CFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCL_OP) $(INCL_VM)
	gcc -o $@ -c $< -D PATH=\"$(PATH_PROJECT)\" $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL) -I $(LIBMAT_INCL) -I $(LIBFREETYPE_INCL) -I $(LIBSDL2_INCL)

$(OBJ_PATH)/%.o: $(SRC_OP_PATH)/%.c $(INCL_OP) $(INCL_VM)
	gcc -o $@ -c $< -D PATH=\"$(PATH_PROJECT)\" $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL) -I $(LIBMAT_INCL) -I $(LIBFREETYPE_INCL) -I $(LIBSDL2_INCL)

$(OBJ_PATH)/%.o: $(SRC_DISPLAY_PATH)/%.c $(INCL_OP) $(INCL_VM) $(INCL_DISPLAY)
	gcc -o $@ -c $< -D PATH=\"$(PATH_PROJECT)\" $(CFLAGS) -I $(INCL_PATH) -I $(OP_INC_PATH) -I $(LIBFT_INCL) -I $(LIBMAT_INCL) -I $(LIBFREETYPE_INCL) -I $(LIBSDL2_INCL)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	make -j

.PHONY: all clean fclean re
