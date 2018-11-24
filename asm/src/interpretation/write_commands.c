/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 06:51:01 by achernys          #+#    #+#             */
/*   Updated: 2018/11/20 18:19:20 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/interpretation.h"

int		i_write_cmd_with_codage(t_i_data *i_data, char dir_size)
{
	char	i;
	size_t	indent;

	indent = 1;
	i = 0;
	i_data->champ_byte_code[i_data->public_struct->commands->command_place +
							indent] =
			i_get_codage_octal(i_data->public_struct->commands);
	indent++;
	while (i < 3 && i_data->public_struct->commands->opt[(int)i] != 0)
	{
		indent += i_data->write_param_value_arr[
				i_data->public_struct->commands->opt[(int)i] - 1](
				i_data->public_struct->commands->command_place + indent,
				i_data, dir_size, i);
		i++;
	}
	return (i_get_all_param_size(i_data->public_struct->commands->opt, dir_size)
			+ 2);
}

int		i_write_cmd_without_codage(t_i_data *i_data, char dir_size)
{
	i_data->write_param_value_arr[i_data->public_struct->commands->opt[0] - 1](
			i_data->public_struct->commands->command_place + 1,
			i_data, dir_size, 0);
	return (i_get_all_param_size(i_data->public_struct->commands->opt, dir_size)
			+ 1);
}
