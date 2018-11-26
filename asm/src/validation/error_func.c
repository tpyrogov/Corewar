/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:55:08 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/24 14:25:12 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

static void	v_type_of_wrong_arg(t_v_validation *valid)
{
	if (v_is_dir_label(valid,
			v_count_size(valid->buff + valid->x_curs)))
		valid->type = ft_strdup("direct");
	else if (v_is_reg(valid))
		valid->type = ft_strdup("register");
	else if (v_is_ind(valid, v_count_size(valid->buff + valid->x_curs)))
		valid->type = ft_strdup("indirect");
}

static void	v_invalid_param(int error_code, t_v_validation *valid)
{
	v_print_index_error(valid->buff, valid->x_curs);
	v_pass_whitespaces(valid);
	v_get_error_string(valid);
	ft_printf("Invalid parameter ");
	if (error_code == WRONG_PARAM_NUM)
		ft_printf("count");
	else
	{
		v_type_of_wrong_arg(valid);
		ft_printf("%d type %s ", valid->param_index, valid->type);
	}
	ft_printf("for instruction %s", g_cmd[valid->cur_cmd].cmd);
}

static void	v_direct_label(t_v_validation *valid)
{
	v_print_index_error(valid->buff, valid->x_curs);
	v_pass_whitespaces(valid);
	v_get_error_string(valid);
	ft_printf("No such label %s while attempting to dereference ",
			valid->buff);
	ft_printf("token [TOKEN][%03d:%03d] DIRECT_LABEL \"%s\"",
			valid->y_curs + 1, valid->x_curs + 1, valid->buff);
}

void		v_invalid_instruct(t_v_validation *valid)
{
	v_print_index_error(valid->buff, valid->x_curs);
	v_pass_whitespaces(valid);
	v_get_error_string(valid);
	ft_printf("Invalid instruction at token [TOKEN][%3d:%3d]",
			valid->y_curs + 1, valid->x_curs + 1);
}

void		v_put_validation_error(int error_code, t_v_validation *valid)
{
	if (error_code == FILE_ERR)
		ft_printf("Can't read source file %s", valid->file_name);
	else if (error_code >= SYNTAX_LABEL && error_code <= NO_NEW_LINE)
	{
		v_syntax_error(error_code, valid);
	}
	else if (error_code == LEXICAL)
		v_lexical_error(valid);
	else if (error_code >= TOO_LONG_NAME && error_code <= NO_COMMENT)
		v_name_comment_error(error_code, valid);
	else if (error_code == INVALID_INSTRUCT)
		v_invalid_instruct(valid);
	else if (error_code == INVALID_PARAM_FOR_INSTRUCT
	|| error_code == WRONG_PARAM_NUM)
		v_invalid_param(error_code, valid);
	else if (error_code == DIRECT_LABEL)
		v_direct_label(valid);
	ft_printf("\n");
	exit(error_code);
}
