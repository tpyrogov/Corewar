/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:46:09 by achernys          #+#    #+#             */
/*   Updated: 2018/11/20 15:46:40 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_INTERPRETATION_H
# define ASM_INTERPRETATION_H

# include "asm.h"

# define H_NULL 4
# define H_BOT_SIZE 4
# define H_MAGIC sizeof(unsigned)
# define PRG_CMT_SIZE (PROG_NAME_LENGTH + COMMENT_LENGTH)
# define HEADER_CODE_SIZE H_MAGIC + PRG_CMT_SIZE + H_NULL + H_BOT_SIZE + H_NULL

# define REG_LENG 1
# define IND_LENG 2
# define DIR_LENG 4

# define CREATE_FILE_ERR 75
# define UNDEFINE_ERR 77
# define WRITE_ERR 78
# define FILE_NAME_ERR 76

typedef struct		s_i_data
{
	int				fd;
	unsigned char	header_code[HEADER_CODE_SIZE];
	unsigned char	*champ_byte_code;
	t_public_struct	*public_struct;
	int				(*write_param_value_arr[3])(size_t field_idx,
												struct	s_i_data *i_data,
												char dir_size, char param_num);
}					t_i_data;

t_i_data			*i_init_i_data(t_public_struct *public_struct);

void				i_write_params(unsigned char *start_input_field,
									unsigned int value, char size);
void				i_add_index_label(t_commands *commands);
unsigned char		i_get_codage_octal(t_commands *commands);

char				i_get_all_param_size(char *params, char dir_size);
char				i_get_param_size(char param, char dir_size);

int					i_write_register(size_t field_idx, t_i_data *i_data,
									char dir_size, char param_num);
int					i_write_dir(size_t field_idx, t_i_data *i_data,
									char dir_size, char param_num);
int					i_write_ind(size_t field_idx, t_i_data *i_data,
									char dir_size, char param_num);

int					i_write_cmd_without_codage(t_i_data *i_data, char dir_size);
int					i_write_cmd_with_codage(t_i_data *i_data, char dir_size);
char				i_is_need_write(t_commands *commands);
void				i_write_data(t_commands *commands,
									unsigned char *field_champ);
void				i_write_header_code(t_i_data *i_data, size_t bot_size);
ssize_t				i_write_data_in_file(t_i_data *i_data, size_t champ_size);
void				resize_champ_mem(t_i_data *i_data, size_t index,
										size_t multiplier);

#endif
