/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:29:36 by achernys          #+#    #+#             */
/*   Updated: 2018/11/26 19:29:39 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../lib/mylib/ft_printf/ft_printf.h"
# include "../lib/mylib/get_next_line.h"
# include "../inc/op.h"
# include "errors.h"

typedef enum				e_reserved_words
{
	live = 1, ld, st, add, sub, and, or, xor,
	zjmp, ldi, sti, fork_cmd, lld, lldi, lfork, aff
}							t_reserved_words;

typedef struct				s_labels
{
	char					*name;
	size_t					index;
	struct s_labels			*next;
}							t_labels;

typedef union				u_di_value
{
	unsigned int			number;
	t_labels				*labels;
	char					*str_name;
}							t_di_value;

typedef struct				s_commands
{
	t_reserved_words		reserved_words;
	size_t					command_place;
	char					reg_num[3];
	char					dir_label[3];
	t_di_value				dir_value[3];
	char					ind_label[2];
	t_di_value				ind_value[2];
	char					opt[3];
	size_t					label_insert_index[3];
	t_labels				*label_pointer;
	struct s_commands		*next;

}							t_commands;

typedef struct				s_public_struct
{
	t_labels				*labels;
	t_commands				*commands;
	t_header				header;
	char					*file_name;
	int						fd;
}							t_public_struct;

void						interpretation(t_public_struct *public_struct);

t_labels					*init_label(char *name_label, int index);
void						add_label(t_public_struct *public_struct,
										char *name_label, int index);
t_public_struct				*init_public_struct(char *file_name);
void						trim_string_array(char **array);
void						put_error(int error_code);
void						free_char_array(char **arr);
void						cut_comment(char **s);
void						free_public_struct(t_public_struct *public_struct);

#endif
