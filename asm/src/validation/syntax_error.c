/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:04:28 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/24 14:49:01 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

void		v_choose_error(t_v_validation *valid)
{
	int	lexical;

	if ((lexical = v_is_reg(valid)) == 1)
		v_put_validation_error(SYNTAX_REGISTER, valid);
	else if (lexical < 70 && (lexical = v_is_dir_label(valid,
			v_count_size(valid->buff))) == 1)
		v_put_validation_error(SYNTAX_DIRECT_LABEL, valid);
	else if (lexical < 70 && (lexical = v_is_ind(valid,
			v_count_size(valid->buff))) == 1)
		v_put_validation_error(SYNTAX_INDIRECT, valid);
	else if (valid->buff[valid->x_curs] == '\0')
		v_put_validation_error(SYNTAX_ENDLINE, valid);
	else if (lexical < 70 && (lexical = v_is_label(valid)) == 1)
		v_put_validation_error(SYNTAX_LABEL, valid);
	else if (lexical < 70 && valid->buff[valid->x_curs] == SEPARATOR_CHAR)
		v_put_validation_error(SYNTAX_SEPARATOR, valid);
	else if (lexical > 70)
		v_put_validation_error(lexical, valid);
	else
		v_put_validation_error(SYNTAX_INSTRUCT, valid);
}

static void	v_syntax_error_con(int error_code, t_v_validation *valid)
{
	if (error_code == SYNTAX_DIRECT_LABEL)
		ft_printf("DIRECT_LABEL \"%s\"", valid->buff);
	else if (error_code == SYNTAX_INDIRECT)
		ft_printf("INDIRECT \"%s\"", valid->buff);
	else if (error_code == SYNTAX_REGISTER)
		ft_printf("REGISTER \"%s\"", valid->buff);
	else if (error_code == SYNTAX_COMMAND_NAME)
		ft_printf("COMMAND_NAME \"%s\"", valid->buff);
	else if (error_code == SYNTAX_LABEL)
		ft_printf("LABEL \"%s\"", valid->buff);
	else if (error_code == SYNTAX_SEPARATOR)
		ft_printf("SEPARATOR \",\"");
	else if (error_code == NO_NAME)
		ft_printf("NO_NAME");
	else if (error_code == NO_COMMENT)
		ft_printf("NO_COMMENT");
	else if (error_code == SYNTAX_DIRECT)
		ft_printf("DIRECT \"%s\"", valid->buff);
}

void		v_check_eof(t_v_validation *valid, int error_code)
{
	if (error_code == SYNTAX_END)
	{
		ft_strdel(&valid->buff);
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ",
				valid->y_curs + 1, valid->x_curs + 1);
		ft_printf("END \"%s\"", valid->buff);
	}
	else
	{
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ",
				valid->y_curs + 1, valid->x_curs + 1);
		if (get_next_line(valid->fd, &valid->buff) <= 0)
		{
			ft_strdel(&valid->buff);
			ft_printf("END \"%s\"", valid->buff);
		}
		else
			ft_printf("ENDLINE");
	}
}

void		v_syntax_error(int error_code, t_v_validation *valid)
{
	if (error_code == NO_NEW_LINE)
	{
		ft_printf("{yellow}Syntax error - unexpected end of input ");
		ft_printf("{yellow}(Perhaps you forgot to end with a newline ?)");
	}
	else if (error_code == SYNTAX_ENDLINE || error_code == SYNTAX_END)
	{
		v_check_eof(valid, error_code);
	}
	else
	{
		v_print_index_error(valid->buff, valid->x_curs);
		v_pass_whitespaces(valid);
		v_get_error_string(valid);
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] ",
				valid->y_curs + 1, valid->x_curs + 1);
		if (error_code == SYNTAX_COMMAND_COMMENT)
			ft_printf("COMMAND_COMMENT %s", valid->buff);
		else if (error_code == SYNTAX_INSTRUCT)
			ft_printf("INSTRUCTION \"%s\"", valid->buff);
		v_syntax_error_con(error_code, valid);
	}
}
