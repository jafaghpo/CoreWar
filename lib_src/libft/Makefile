# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iburel <iburel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 22:12:15 by iburel            #+#    #+#              #
#    Updated: 2017/11/23 21:11:55 by iburel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
CC			=	gcc
ifeq ($(DEBUG), yes)
	CFLAGS	=	-g
else
	CFLAGS	=	-Wall -Wextra -Werror -Ofast
endif
INCL		=	include

SRCCONV		=	ft_atoi.c ft_atoi_split.c ft_itoa.c ft_tolower.c ft_toupper.c
SRCSCONV	=	$(addprefix conv/, $(SRCCONV))
OBJCONV		=	$(SRCSCONV:.c=.o)

SRCCPLX		=	ft_cplxadd.c ft_cplxdiv.c ft_cplxmod.c ft_cplxmult.c \
				ft_cplxnew.c ft_cplxsqrt.c ft_cplxsub.c
SRCSCPLX	=	$(addprefix cplx/, $(SRCCPLX))
OBJCPLX		= 	$(SRCSCPLX:.c=.o)

SRCFILE		= 	ft_filetostr.c get_next_line.c
SRCSFILE	=	$(addprefix file/, $(SRCFILE))
OBJFILE		= 	$(SRCSFILE:.c=.o)

SRCCHAR		=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isblank.c \
				ft_isdigit.c ft_islower.c ft_isprint.c ft_ispunct.c \
				ft_isspace.c ft_isupper.c
SRCSCHAR	=	$(addprefix char/, $(SRCCHAR))
OBJCHAR		=	$(SRCSCHAR:.c=.o)

SRCLST		=	ft_lstadd.c ft_lstaddlast.c ft_lstdel.c ft_lstdelone.c \
				ft_lstiter.c ft_lstmap.c ft_lstnew.c
SRCSLST		=	$(addprefix lst/, $(SRCLST))
OBJLST		=	$(SRCSLST:.c=.o)

SRCMATRIX	=	ft_matrix_free.c ft_matrixaddfloat.c ft_matrixforrot.c \
				ft_matrixmult.c ft_matrixnew.c ft_matrixrot.c ft_vecunit.c
SRCSMATRIX	=	$(addprefix matrix/, $(SRCMATRIX))
OBJMATRIX	=	$(SRCSMATRIX:.c=.o)

SRCMEM		=	ft_bzero.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
				ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_nbbits.c \
				ft_realloc.c
SRCSMEM		=	$(addprefix mem/, $(SRCMEM))
OBJMEM		=	$(SRCSMEM:.c=.o)

SRCPUT		=	ft_afferror.c ft_putchar.c ft_putchar_fd.c ft_putendl.c \
				ft_putendl_fd.c ft_putmatrix.c ft_putnbr.c ft_putnbr_fd.c \
				ft_putnbrendl.c ft_putstr.c ft_putstr_fd.c
SRCSPUT		=	$(addprefix put/, $(SRCPUT))
OBJPUT		=	$(SRCSPUT:.c=.o)

SRCSTR		=	ft_strcat.c ft_strcmp.c ft_strdup.c ft_striteri.c \
				ft_strlcat.c ft_strmapi.c ft_strncpy.c ft_strnstr.c \
				ft_strstr.c ft_strupper.c ft_strchr.c ft_strcpy.c \
				ft_strequ.c ft_strjoin.c ft_strlen.c ft_strncat.c \
				ft_strnequ.c ft_strrchr.c ft_strsub.c ft_wstrcpy.c \
				ft_strclr.c ft_strdel.c ft_striter.c ft_strjoin_free.c \
				ft_strmap.c ft_strncmp.c ft_strnew.c ft_strsplit.c \
				ft_strtrim.c ft_wstrlen.c ft_delspace.c ft_strcmp_space.c \
				ft_sizestr.c
SRCSSTR		=	$(addprefix str/, $(SRCSTR))
OBJSTR		=	$(SRCSSTR:.c=.o)

SRCPRINTF	=	ft_printf.c	ft_buf.c ft_color.c ft_flags.c ft_per.c ft_pars.c \
				ft_conv.c ft_convspe.c ft_getutype.c ft_getutype2.c ft_getstype.c \
				ft_getstype2.c ft_printf_s.c ft_printf_ls.c ft_printf_c.c \
				ft_printf_putchar_fd.c ft_printf_o.c ft_printf_u.c ft_printf_x.c \
				ft_printf_b.c ft_printf_k.c ft_printf_ktoa.c ft_printf_getdaymonth.c \
				ft_printf_itoa.c ft_printf_itoa_base.c ft_printf_d.c ft_printf_strnew.c \
				ft_printf_e.c ft_printf_dtoa_e.c ft_printf_f.c ft_printf_dtoa_f.c \
				ft_printf_dtoa_ent.c ft_printf_g.c ft_printf_g_e.c ft_printf_dtoa_g_e.c \
				ft_printf_g_f.c ft_printf_dtoa_g_f.c ft_printf_a.c ft_printf_dtoa_a.c \
				ft_printf_itoa_a.c ft_printf_le.c ft_printf_dtoa_le.c ft_printf_lf.c \
				ft_printf_dtoa_lf.c ft_printf_dtoa_lent.c ft_printf_lg.c \
				ft_printf_lg_le.c ft_printf_dtoa_lg_le.c ft_printf_lg_lf.c \
				ft_printf_dtoa_lg_lf.c ft_printf_la.c ft_printf_dtoa_la.c \
				ft_printf_p.c ft_printf_ind.c
SRCSPRINTF	=	$(addprefix ft_printf/, $(SRCPRINTF))
OBJPRINTF	=	$(SRCSPRINTF:.c=.o)

SRCMLX		=	ft_new_image.c ft_putpixel.c ft_clear_image.c ft_line_secure.c \
				ft_change_points.c ft_line.c ft_putpixel_secure.c
SRCSMLX		=	$(addprefix mlx/, $(SRCMLX))
OBJMLX		=	$(SRCSMLX:.c=.o)

OBJ			=	$(OBJCONV) $(OBJCPLX) $(OBJFILE) $(OBJCHAR) $(OBJLST) \
				$(OBJMATRIX) $(OBJMEM) $(OBJPUT) $(OBJSTR) $(OBJPRINTF) \
				$(OBJMLX)

all: conv cplx file char lst matrix mem put str printf mlx

conv: $(OBJCONV)
	ar rc $(NAME) $^
	ranlib $(NAME)

cplx: $(OBJCPLX)
	ar rc $(NAME) $^
	ranlib $(NAME)

file: $(OBJFILE)
	ar rc $(NAME) $^
	ranlib $(NAME)

char: $(OBJCHAR)
	ar rc $(NAME) $^
	ranlib $(NAME)

lst: $(OBJLST)
	ar rc $(NAME) $^
	ranlib $(NAME)

matrix: $(OBJMATRIX)
	ar rc $(NAME) $^
	ranlib $(NAME)

mem: $(OBJMEM)
	ar rc $(NAME) $^
	ranlib $(NAME)

put: $(OBJPUT)
	ar rc $(NAME) $^
	ranlib $(NAME)

str: $(OBJSTR)
	ar rc $(NAME) $^
	ranlib $(NAME)

printf: $(OBJPRINTF)
	ar rc $(NAME) $^
	ranlib $(NAME)

mlx: $(OBJMLX)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCL) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all conv cplx file char lst matrix mem put str printf mlx clean fclean re
