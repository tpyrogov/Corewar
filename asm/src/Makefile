#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/02 17:20:41 by tpyrogov          #+#    #+#              #
#    Updated: 2018/11/02 17:20:44 by tpyrogov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CFLAGS		=	-Wall -Wextra -Werror
SRC			=   ./main.c \
                ./parse_string.c \
                ./free.c \
                ./init.c
INCL		=	./asm.h
INCL_LIB	=	./libft/includes/libft.h
OBJ			=	$(SRC:.c=.o)
NAME		=	asm

all: $(NAME)

$(NAME): $(OBJ) $(INCL)
	make -C libft/ fclean && make -C libft/
	gcc $(CFLGS) -o $@ $(OBJ) -L ./libft -lft

$(OBJ):%.o: %.c $(INCL)
	gcc -I=${INCL} -c $< -o $@

clean:
	rm -f *.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all