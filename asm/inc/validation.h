/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:27:13 by achernys          #+#    #+#             */
/*   Updated: 2018/11/24 14:46:06 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_VALIDATION_H
# define ASM_VALIDATION_H

# include "../inc/asm.h"

typedef struct		s_v_cmd
{
	char			*cmd;
	int				args_count;
	char			dir[3];
	char			ind[3];
	char			reg[3];
}					t_v_cmd;

extern t_v_cmd		g_cmd[16];

typedef struct		s_v_validation
{
	char			*buff;
	char			*file_name;
	int				fd;
	int				x_curs;
	int				y_curs;
	int				name_checked;
	int				comment_checked;
	int				param_index;
	char			*type;
	int				cur_cmd;
	t_labels		*labels;
}					t_v_validation;

void				v_validation(t_public_struct *public);
t_v_validation		*v_init_validation(char *s);
char				*v_get_string(t_v_validation *valid, char c);

void				v_read_command_type(t_v_validation *valid);

size_t				v_find_label(t_v_validation *valid, char *s);
void				v_pass_whitespaces(t_v_validation *valid);
void				v_miss_empty_lines(t_v_validation *valid);
size_t				v_count_size(char *s);
void				v_choose_error(t_v_validation *valid);
int					v_is_digit_arg(char *valid, int sign);

void				v_put_validation_error(int error_code,
											t_v_validation *valid);
char				v_ft_is_whitespace_line(const char *str);

void				v_get_error_string(t_v_validation *valid);

void				v_get_labels(t_v_validation *valid, int save_lines);

int					v_is_command(t_v_validation *valid);
int					v_is_label(t_v_validation *valid);
int					v_is_reg(t_v_validation *valid);
int					v_is_ind(t_v_validation *valid, size_t size);
int					v_is_dir_label(t_v_validation *valid, size_t size);
int					v_is_label_chars(t_v_validation *valid, char *str,
																size_t size);

void				v_pass_command_name(t_v_validation *valid, char *temp,
																	int size);

int					v_is_empty(t_v_validation *valid);
void				separator(t_v_validation *valid);

void				v_cut_comment(char *s);
size_t				v_count_label_size(char *s);

t_labels			*v_init_label(char *name_label, int index);

void				v_name_comment_error(int error_code, t_v_validation *valid);
void				v_lexical_error(t_v_validation *valid);

void				v_return_to_command_star(t_v_validation *valid, int read);
void				v_free_validation(t_v_validation *valid);
void				v_syntax_error(int error_code, t_v_validation *valid);
void				v_print_index_error(char *str, int index);

#endif
