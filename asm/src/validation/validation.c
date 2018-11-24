/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:56:29 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/24 14:30:41 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

static void	v_check_params(t_v_validation *valid)
{
	int error;

	if (valid->buff[valid->x_curs] == SEPARATOR_CHAR)
		v_put_validation_error(SYNTAX_SEPARATOR, valid);
	else if ((error = v_is_ind(valid,
		v_count_size(valid->buff + valid->x_curs + 1))) == 1
	&& g_cmd[valid->cur_cmd].ind[valid->param_index] != -1)
		valid->x_curs += v_count_size(valid->buff + valid->x_curs);
	else if (error < 70 && (error = v_is_reg(valid)) == 1
		&& g_cmd[valid->cur_cmd].reg[valid->param_index] != -1)
		valid->x_curs += v_count_size(valid->buff + valid->x_curs);
	else if (error < 70 && (error = v_is_dir_label(valid,
			v_count_size(valid->buff + valid->x_curs))) == 1
	&& g_cmd[valid->cur_cmd].dir[valid->param_index] != -1)
		valid->x_curs += v_count_size(valid->buff + valid->x_curs);
	else if (error > 70)
		v_put_validation_error(error, valid);
	else
		v_put_validation_error(INVALID_PARAM_FOR_INSTRUCT, valid);
	v_pass_whitespaces(valid);
}

static void	v_parse_commands(t_v_validation *valid)
{
	v_pass_whitespaces(valid);
	if (v_is_label(valid) == 1)
		valid->x_curs += v_count_label_size(valid->buff + valid->x_curs);
	v_pass_whitespaces(valid);
	if (v_ft_is_whitespace_line(valid->buff + valid->x_curs)
	|| *(valid->buff + valid->x_curs) == '\0')
		return ;
	if ((valid->cur_cmd = v_is_command(valid)) == -1)
		v_choose_error(valid);
	valid->x_curs += (ft_strlen(g_cmd[valid->cur_cmd].cmd) + 1);
	valid->param_index = 0;
	while (valid->param_index < g_cmd[valid->cur_cmd].args_count)
	{
		v_pass_whitespaces(valid);
		v_check_params(valid);
		if (valid->buff[valid->x_curs] != SEPARATOR_CHAR
		&& (valid->param_index != g_cmd[valid->cur_cmd].args_count - 1
		|| valid->param_index > g_cmd[valid->cur_cmd].args_count - 1))
			v_choose_error(valid);
		else if (valid->buff[valid->x_curs] == SEPARATOR_CHAR)
			valid->x_curs++;
		valid->param_index++;
	}
	separator(valid);
}

static void	v_name_and_comment(t_v_validation *valid)
{
	while (get_next_line(valid->fd, &valid->buff) > 0)
	{
		valid->x_curs = 0;
		v_pass_whitespaces(valid);
		if (valid->buff[valid->x_curs] == COMMENT_CHAR
			|| valid->buff[valid->x_curs] == ';')
			v_cut_comment(valid->buff + valid->x_curs);
		if (v_ft_is_whitespace_line(valid->buff) != 1)
		{
			v_pass_whitespaces(valid);
			if (*(valid->buff + valid->x_curs) == '.')
				v_read_command_type(valid);
			else if (valid->name_checked != 1 || valid->comment_checked != 1)
				v_choose_error(valid);
			else
				break ;
		}
		valid->y_curs++;
		ft_strdel(&valid->buff);
	}
	ft_strdel(&valid->buff);
}

void		v_read_cmds(t_v_validation *valid)
{
	v_return_to_command_star(valid, valid->y_curs);
	while (get_next_line(valid->fd, &valid->buff) > 0)
	{
		valid->x_curs = 0;
		if (ft_strchr(valid->buff, COMMENT_CHAR)
		|| ft_strchr(valid->buff, ';'))
			v_cut_comment(valid->buff);
		if (v_ft_is_whitespace_line(valid->buff) != 1)
			v_parse_commands(valid);
		ft_strdel(&valid->buff);
		valid->y_curs++;
	}
}

void		v_validation(t_public_struct *public)
{
	t_v_validation	*valid;
	int				save_lines;

	valid = v_init_validation(public->file_name);
	if ((valid->fd = open(valid->file_name, O_RDONLY)) < 0)
		v_put_validation_error(FILE_ERR, valid);
	public->fd = valid->fd;
	if (v_is_empty(valid) == 1)
		v_put_validation_error(SYNTAX_ENDLINE, valid);
	v_name_and_comment(valid);
	v_return_to_command_star(valid, valid->y_curs);
	if (v_is_empty(valid) == 1)
		v_put_validation_error(SYNTAX_ENDLINE, valid);
	save_lines = valid->y_curs;
	v_get_labels(valid, save_lines);
	valid->y_curs = save_lines;
	v_read_cmds(valid);
	v_free_validation(valid);
	lseek(valid->fd, 0, 0);
}
