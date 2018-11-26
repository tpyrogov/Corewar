NAME = asm

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

.PHONY: clean fclean all re 

SRC_DIR = src

SRC_FILES =   collect_info/c_add_current_command.c\
        collect_info/c_add_label_and_pointer.c\
        collect_info/c_additional_functions.c\
        collect_info/c_collect_info.c\
        collect_info/c_free_info.c\
        collect_info/c_get_commands_and_labels.c\
        collect_info/c_get_reg_dir_ind.c\
        collect_info/c_initialization.c\
        collect_info/c_link_labels.c\
        collect_info/c_read_comment.c\
        collect_info/c_read_name.c\
        validation/check_param.c\
        validation/search.c\
        validation/labels.c\
        validation/error_func.c\
        validation/lexical_check.c\
        validation/free_validation.c\
        validation/validation.c\
        validation/init_validation.c\
        validation/comment_and_name.c\
        validation/print_index_error.c\
        interpretation/mem_free_alloc/init.c\
        interpretation/get_codage_octal.c\
        interpretation/write_header_code.c\
        interpretation/add_index_label.c\
        interpretation/write_param_value_funcs.c\
        interpretation/interpritation.c\
        interpretation/write_data_in_file.c\
        interpretation/get_param_size.c\
        interpretation/resize_champ_mem.c\
        interpretation/i_is_need_write.c\
        interpretation/write_miss_data.c\
        interpretation/input_params_on_field.c\
        interpretation/write_commands.c\
        public_mem_free_alloc/init.c\
        main.c \
        validation/syntax_error.c \
        validation/validation_2.c\
        validation/name_comment_error.c

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