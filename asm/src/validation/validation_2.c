/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:28:57 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/24 14:46:17 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

int			v_is_empty(t_v_validation *valid)
{
	while (get_next_line(valid->fd, &valid->buff) > 0)
	{
		if (v_ft_is_whitespace_line(valid->buff) != 1)
		{
			lseek(valid->fd, 0, 0);
			ft_strdel(&valid->buff);
			return (0);
		}
		ft_strdel(&valid->buff);
	}
	return (1);
}

void		separator(t_v_validation *valid)
{
	char check[1];

	if (valid->buff[valid->x_curs - 1] == SEPARATOR_CHAR
		&& v_ft_is_whitespace_line(valid->buff + valid->x_curs) == 1)
		v_put_validation_error(SYNTAX_ENDLINE, valid);
	v_pass_whitespaces(valid);
	if (valid->buff[valid->x_curs] == SEPARATOR_CHAR)
		v_put_validation_error(SYNTAX_SEPARATOR, valid);
	if (ft_strchr(valid->buff + valid->x_curs, SEPARATOR_CHAR) != NULL
		&& v_ft_is_whitespace_line(valid->buff + valid->x_curs) != 1)
		v_put_validation_error(INVALID_PARAM_FOR_INSTRUCT, valid);
	if (v_ft_is_whitespace_line(valid->buff + valid->x_curs) != 1)
	{
		v_pass_whitespaces(valid);
		v_choose_error(valid);
	}
	if (valid->buff[valid->x_curs] == '\0')
	{
		lseek(valid->fd, -1, 1);
		read(valid->fd, check, 1);
		if (check[0] != '\n')
			v_put_validation_error(NO_NEW_LINE, valid);
	}
}

void		v_pass_command_name(t_v_validation *valid, char *temp, int size)
{
	if (*(temp + size) == '\0')
		v_put_validation_error(SYNTAX_ENDLINE, valid);
	else if (!ft_isspace(*(temp + size)))
		v_put_validation_error(SYNTAX_INSTRUCT, valid);
	valid->x_curs += size;
}
