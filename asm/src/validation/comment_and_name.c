/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment_and_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:54:50 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/24 14:45:31 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

static size_t	v_command_string_size(t_v_validation *valid)
{
	size_t	size;
	char	*temp;

	size = 0;
	valid->x_curs++;
	if ((temp = ft_strchr(valid->buff + valid->x_curs, '"')) == NULL)
	{
		while ((temp = ft_strchr(valid->buff + valid->x_curs, '"')) == NULL)
		{
			if (*(valid->buff + valid->x_curs) == '\0')
				v_put_validation_error(SYNTAX_END, valid);
			size += ft_strlen(valid->buff + valid->x_curs);
			valid->x_curs += ft_strlen(valid->buff + valid->x_curs);
			ft_strdel(&valid->buff);
			if (get_next_line(valid->fd, &valid->buff) <= 0)
				v_put_validation_error(SYNTAX_END, valid);
			valid->x_curs = 0;
			valid->y_curs++;
		}
		size += (size_t)(temp - valid->buff);
	}
	else
		size = (size_t)(temp - valid->buff);
	valid->x_curs = (int)(temp - valid->buff) + 1;
	return (size);
}

static void		v_check_name(t_v_validation *valid)
{
	char	*temp;

	if ((temp = ft_strstr(valid->buff, NAME_CMD_STRING)) != NULL)
	{
		valid->x_curs = (int)(temp - valid->buff);
		v_pass_command_name(valid, temp, 5);
		v_pass_whitespaces(valid);
		if (valid->buff[valid->x_curs] == COMMENT_CHAR
		|| valid->buff[valid->x_curs] == ';')
			v_put_validation_error(SYNTAX_ENDLINE, valid);
		if (valid->buff[valid->x_curs] == '"')
		{
			if (valid->buff[valid->x_curs + 1] == '"')
				v_put_validation_error(NO_NAME, valid);
			if (v_command_string_size(valid) > PROG_NAME_LENGTH)
				v_put_validation_error(TOO_LONG_NAME, valid);
		}
		else
			v_put_validation_error(SYNTAX_INSTRUCT, valid);
	}
	else
		v_put_validation_error(SYNTAX_INSTRUCT, valid);
}

static void		v_check_comment(t_v_validation *valid)
{
	char	*temp;

	if ((temp = ft_strstr(valid->buff, COMMENT_CMD_STRING)) != NULL)
	{
		valid->x_curs = (int)(temp - valid->buff);
		v_pass_command_name(valid, temp, 8);
		v_pass_whitespaces(valid);
		if (valid->buff[valid->x_curs] == COMMENT_CHAR
		|| valid->buff[valid->x_curs] == ';')
			v_put_validation_error(SYNTAX_ENDLINE, valid);
		if (valid->buff[valid->x_curs] == '"')
		{
			if (valid->buff[valid->x_curs + 1] == '"')
				v_put_validation_error(NO_COMMENT, valid);
			if (v_command_string_size(valid) > COMMENT_LENGTH)
				v_put_validation_error(TOO_LONG_COMMENT, valid);
		}
		else
			v_put_validation_error(SYNTAX_INSTRUCT, valid);
	}
	else
		v_put_validation_error(SYNTAX_INSTRUCT, valid);
}

void			v_read_command_type(t_v_validation *valid)
{
	char *temp;

	if ((temp = ft_strstr(valid->buff, NAME_CMD_STRING))
		&& *(temp + 1) != '\0')
	{
		if (valid->name_checked == 1)
			v_put_validation_error(SYNTAX_COMMAND_NAME, valid);
		v_check_name(valid);
		valid->name_checked = 1;
	}
	else if ((temp = ft_strstr(valid->buff, COMMENT_CMD_STRING))
		&& *(temp + 1) != '\0')
	{
		if (valid->comment_checked == 1)
			v_put_validation_error(SYNTAX_COMMAND_COMMENT, valid);
		v_check_comment(valid);
		valid->comment_checked = 1;
	}
	else
		v_put_validation_error(LEXICAL, valid);
	if (ft_strchr(valid->buff + valid->x_curs, COMMENT_CHAR) != NULL
	|| ft_strchr(valid->buff + valid->x_curs, ';') != NULL)
		v_cut_comment(valid->buff + valid->x_curs);
	if (v_ft_is_whitespace_line(valid->buff + valid->x_curs) != 1)
		v_put_validation_error(SYNTAX_INSTRUCT, valid);
}

int				v_is_command(t_v_validation *valid)
{
	char	*temp;
	int		i;

	i = 0;
	while (i != 16)
	{
		if ((temp = ft_strstr(valid->buff + valid->x_curs,
				g_cmd[i].cmd)) != NULL)
		{
			if ((ft_isspace(*(temp + ft_strlen(g_cmd[i].cmd)))
			|| *(temp + ft_strlen(g_cmd[i].cmd)) == '\0')
			&& (ft_isspace(*(temp - 1))
			|| (temp - (valid->buff + valid->x_curs)) == 0))
				return (i);
		}
		i++;
	}
	return (-1);
}
