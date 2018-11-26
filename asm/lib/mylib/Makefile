# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achernys <achernys@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/27 17:30:25 by achernys          #+#    #+#              #
#    Updated: 2018/02/28 17:13:36 by achernys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
 
NAME = mylib.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

.PHONY: clean fclean all re 

FT_PRINTF_DIR = ft_printf

FT_PRINTF_SRC = ft_printf.c ft_getparam.c ft_getint.c\
		ft_get_tval.c ft_realloc.c ft_forparse.c\
		ft_processingflags.c ft_parsetype.c ft_procint.c\
		ft_proctxt.c	ft_gettxtval.c ft_bitoa.c\
		ft_forparse01.c ft_procstr.c ft_itoabase.c\
		ft_procnotation.c ft_getunsignedval.c ft_other.c\
		ft_forparse02.c ft_getfloatval.c ft_procdouble.c\
		ft_ftoa.c ft_setcolor.c ft_proc_e_type.c\

FT_PRINTF_OBJ = $(addprefix $(FT_PRINTF_DIR)/, $(FT_PRINTF_SRC:.c=.o))

SRC = get_next_line.c

SRC_OBJ = $(SRC:.c=.o)

OFILES = $(FT_PRINTF_OBJ) $(SRC_OBJ)

all: $(NAME)

$(NAME): $(OFILES)
	make -C libft/
	ar rc $@ $^
	ranlib $@

clean:
	rm -f $(OFILES)
	rm -f *~
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
