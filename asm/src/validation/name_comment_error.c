/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:20:02 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/24 14:25:43 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

void		v_name_comment_error(int error_code, t_v_validation *valid)
{
	if (error_code == TOO_LONG_NAME)
		ft_printf("{yellow}Champion name too long (Max length 128){eoc}");
	else if (error_code == TOO_LONG_COMMENT)
		ft_printf("{yellow}Champion comment too long (Max length 2048){eoc}");
	else
	{
		v_print_index_error(valid->buff, valid->x_curs);
		v_pass_whitespaces(valid);
		v_get_error_string(valid);
		if (error_code == NO_NAME)
			ft_printf("{red}Champion has no name!{eoc}");
		else if (error_code == NO_COMMENT)
			ft_printf("{red}Champion has no comment!{eoc}");
	}
}

void		v_lexical_error(t_v_validation *valid)
{
	v_print_index_error(valid->buff, valid->x_curs);
	v_pass_whitespaces(valid);
	v_get_error_string(valid);
	ft_printf("{red}Lexical error at [%d:%d]{eoc}", valid->y_curs + 1,
			valid->x_curs + 1);
}
