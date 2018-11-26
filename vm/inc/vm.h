/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <dlewando@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:04:39 by achernys          #+#    #+#             */
/*   Updated: 2018/11/16 14:19:34 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../lib/mylib/ft_printf/ft_printf.h"
# include "../inc/op.h"
# include "errors.h"
# include <fcntl.h>

# define FIELD_SIZE 4096
# define FIRST_CODE(x) (x >> 6 & 3)
# define MIDDLE_CODE(x) (x >> 4 & 3)
# define LAST_CODE(x) (x >> 2 & 3)

typedef struct			s_options
{
	char				reg[3];
	unsigned int		dir[3];
	short				ind[2];
	char				option_number[3];
}						t_options;

typedef struct			s_pc
{
	short				pc_index;
	unsigned char		alive_label;
	unsigned short		time_todo;
	unsigned char		command;
	unsigned char		action;
	int					pc_number;
	char				carry;
	unsigned int		registry[REG_NUMBER];
	t_options			*options;
	struct s_pc			*next;
}						t_pc;

typedef struct			s_player
{
	t_header			*header;
	unsigned			player_number;
	int					alive_counter;
	int					last_live;
	char				*file_name;
	struct s_player		*next;
}						t_player;

typedef struct			s_sell
{
	char				owner;
	unsigned char		value;
}						t_sell;

typedef struct			s_game_info
{
	int					counter;
	unsigned short		max_checks_counter;
	int					stop_game;
	int					flag_s;
	char				flag_m;
	char				flag_i;
	char				flag_pc;
	t_sell				field[FIELD_SIZE];
}						t_game_info;

typedef struct			s_data_prog
{
	t_game_info			*game_info;
	t_player			*player;
	int					pc_number;
	t_pc				*first_pc;
	t_pc				*pc;
	t_player			*first_player;
	struct s_arrays		*arrays;
	unsigned short		to_do_list[16];
}						t_data_prog;

typedef struct			s_arrays
{
	char				(*options_array[16])(t_options *options, t_sell
	*field, short pc_i, char dir_size);
	unsigned int		(*functions_array[14])(t_data_prog *data_prog);
}						t_arrays;

unsigned int			bytestoui(const t_sell *byte, short index);
short					bytestos(const t_sell *byte, short index);
void					uitobytes(unsigned value, t_sell *field, short index);

unsigned int			alive_command(t_data_prog *data_prog);
unsigned int			load_command(t_data_prog *data_prog);
unsigned int			store_command(t_data_prog *data_prog);
unsigned int			addition_command(t_data_prog *data_prog);
unsigned int			substraction_command(t_data_prog *data_prog);
unsigned int			and_function(t_data_prog *data_prog);
unsigned int			or_function(t_data_prog *data_prog);
unsigned int			xor_function(t_data_prog *data_prog);
unsigned int			load_index_function(t_data_prog *data_prog);
unsigned int			store_index_function(t_data_prog *data_prog);
unsigned int			fork_function(t_data_prog *data_prog);
unsigned int			long_load_command(t_data_prog *data_prog);
unsigned int			long_load_index_function(t_data_prog *data_prog);
unsigned int			long_fork_function(t_data_prog *data_prog);
short					true_value_pc_index(short pc_index);
char					isrdi(unsigned char byte, char shift);
char					save_reg(t_sell *field, t_options *opt, char opt_num);
char					save_dir(t_sell *field, t_options *opt, char opt_num);
char					save_ind(t_sell *field, t_options *opt, char opt_num);
char					add_indent(char arg, int dir_size);
char					d_options(t_options *options, t_sell *field, short pc_i,
										char dir_size);
char					di_r_options(t_options *opt, t_sell *field, short pc_i);
char					r_ri_options(t_options *opt, t_sell *field, short pc_i);
char					r_r_r_options(t_options *options, t_sell *field,
										short pc_i);
char					r_options(t_options *options, t_sell *field,
										short pc_i);
char					rdi_rdi_r_options(t_options *opt, t_sell *field,
										short pc_i);
char					rdi_rd_r_options(t_options *opt, t_sell *field,
										short pc_i);
char					r_rdi_rd_options(t_options *opt, t_sell *field,
										short pc_i);

void					set_players(t_data_prog *data_prog, int start_arg,
										int argc, char **argv);
void					current_cycle_to_die(t_data_prog *data_prog);

void					print_field(t_game_info *game_info);
char					get_indent_pc(unsigned char codage_octal,
										char dir_size);
void					copy_registry(t_pc *new_pc, t_pc *pc);
void					goround_pc(t_data_prog *data_prog);
void					free_memory(t_data_prog *data_prog);
unsigned int			dop_load_index_function(t_data_prog *data_prog,
										unsigned int result, unsigned int a,
										unsigned int b);
void					dop_xor_function(t_data_prog *data_prog,
										unsigned int *result, unsigned int a,
										unsigned int b);
void					dop_or_function(t_data_prog *data_prog,
										unsigned int *result, unsigned int a,
										unsigned int b);
void					dop_and_function(t_data_prog *data_prog,
										unsigned int *result, unsigned int a,
										unsigned int b);
unsigned int			dop_long_load_index_function(t_data_prog *data_prog,
										unsigned int result, unsigned
										int a, unsigned int b);
unsigned int			dop_store_index_function(t_data_prog *data_prog,
										unsigned int result, unsigned int b);
int						get_flags(t_data_prog *data_prog, char **argv,
										int argc);
void					print_usage(void);
void					set_options(t_data_prog *data_prog);
void					execute_command(t_data_prog *data_prog);
void					check_players_numbers(t_player *player, char quantity,
								unsigned *free_numbers);
unsigned				get_free_number(unsigned *free_numbers);
void					set_start_numbers(unsigned *free_numbers);
char					is_valid_number(t_player *players,
										t_player *current_player);
char					set_player_numbers(t_data_prog *data_prog,
										int start_arg, int argc, char **argv);
char					read_mag_and_name(int fd, t_header *header);
int						read_header(t_game_info *game_info, t_header *header,
										char *filename, short start_position);
char					read_bot_size_and_comment(int fd, t_header *header);
t_player				*create_new_player(t_data_prog *data_prog, t_player
															*current_player);
void					save_in_var(unsigned int *var, unsigned char *arr);
void					copy_field(t_game_info *game_info, unsigned char *field,
								int field_size, short start_position);
void					set_registry(t_pc *pc, unsigned int num);
void					set_start_pc_index(t_pc *pc, char quantity, char i);
void					init_player_numbers_data(unsigned *free_numbers,
									t_player **current_player,
									t_data_prog *data_prog,
									char *quantity_players);
void					print_players_on_field(t_player *current_player,
								unsigned int player_number,
								t_data_prog *data_prog);
void					death_pc_delete(t_data_prog *data_prog);
void					dop_pc_delete(t_data_prog *data_prog,
									t_pc **save_previous,
									t_pc **tmp_pc, char *flag);
int						pc_number(t_pc *pc);
void					nulling_alive_pc(t_pc *pc, t_data_prog *data_prog);
void					check_num_flag(unsigned int *dest,
									char **argv, int arg, char sign);
#endif
