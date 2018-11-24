/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_info.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <dlewando@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:32:32 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/20 14:35:13 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_COLLECT_INFO_H
# define ASM_COLLECT_INFO_H

# include "asm.h"

typedef struct		s_i_collect_info
{
	char	*name;
	char	*comment;
	char	*buff;
	int		i;
	char	**commands_names;
}					t_i_collect_info;

void				c_get_name_and_comment(t_i_collect_info *collect_info,
							int fd);
int					c_is_whtsp_bf_chr(const char *str, char chr);
char				*c_get_str_before_chr(const char *str, char chr);
char				*c_get_str_after_chr(char **str, char chr);
t_commands			*c_init_command(int command);
void				c_add_command(t_public_struct *public_struct,
									int command);
void				c_get_commands_and_labels(t_public_struct *public_struct,
								t_i_collect_info *collect_info);
void				c_add_current_command(t_public_struct *public_struct,
									char *buff,
									t_i_collect_info *collect_info);
t_i_collect_info	*c_collect_info_init(t_i_collect_info *collect_info);
void				c_add_label(t_public_struct *public_struct,
								char *name_label, int index);
void				c_link_labels(t_public_struct *public_struct,
										t_i_collect_info *collect_info);
void				c_read_name(t_i_collect_info *collect_info, int fd);
void				c_read_comment(t_i_collect_info *collect_info, int fd);
void				c_get_reg(t_public_struct *public_struct, char *buff,
												int i, int commas_counter);
void				c_get_dir(t_public_struct *public_struct,
							const char *buff, int i, int commas_counter);
void				c_get_ind(t_public_struct *public_struct,
							const char *buff, int i, int commas_counter);
void				c_add_label_pointer(t_public_struct *public_struct,
									t_labels *tmp);
t_labels			*c_return_tmp_label(t_labels *labels);
t_labels			*c_return_label_pointer(t_labels *labels, char *str);
int					c_command_in_string(const char *str,
							t_i_collect_info *collect_info);
void				c_collect_info(t_public_struct *public_struct,
						t_i_collect_info **collect_info);
void				free_collect_info(t_i_collect_info *collect_info);

#endif
