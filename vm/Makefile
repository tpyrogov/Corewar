NAME = corewar

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

.PHONY: clean fclean all re 

SRC_DIR = src

SRC_FILES = commands/commands1_5.c\
	commands/commands6_10.c\
	commands/commands11_15.c\
	commands/dop6_10commands.c\
	commands/dop11_15commands.c\
	errors/errors1.c\
	init_del_functions/free_memory.c\
	init_del_functions/init_and_nulling_header.c\
	init_del_functions/init_and_nulling_options.c\
	init_del_functions/init_and_nulling_pc.c\
	init_del_functions/init_and_nulling_player_and_game_info.c\
	init_del_functions/init_arrays.c\
	init_del_functions/init_data_prog.c\
	processing_program_args/additional_functions.c\
	processing_program_args/create_new_player.c\
	processing_program_args/processing_players_args.c\
	processing_program_args/read_header.c\
	processing_program_args/valid_and_set_numbers.c\
	read_options/for_read_options.c\
	read_options/read_options1.c\
	read_options/read_options2.c\
	additional_function.c\
	get_flags.c\
	iobytes.c\
	main.c\
	pc_manipulation.c\
	print_field.c\
	print_usage.c\
	processing_game.c\
	processing_players.c\
	set_options_and_execute.c

SRC_OBJ = $(addprefix $(SRC_DIR)/, $(SRC_FILES:.c=.o))

LIB_DIR = lib

LIB_FILES = mylib/mylib.a mylib/libft/libft.a

LFILES = $(addprefix $(LIB_DIR)/, $(LIB_FILES))

all: $(NAME)

$(NAME): $(SRC_OBJ)
	make -C lib/mylib
	$(CC) $(CFLAGS) $(SRC_OBJ) $(LFILES) -o $(NAME)

clean:
	rm -f $(SRC_OBJ)
	rm -f *~
	make clean -C lib/mylib

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/mylib

re: fclean all