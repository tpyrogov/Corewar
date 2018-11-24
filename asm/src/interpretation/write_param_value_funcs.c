/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_param_value_funcs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:44:22 by achernys          #+#    #+#             */
/*   Updated: 2018/11/20 15:10:48 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/interpretation.h"

int		i_write_register(size_t field_idx,
							t_i_data *i_data, char dir_size, char param_num)
{
	dir_size++;
	i_write_params(&i_data->champ_byte_code[(int)field_idx],
			(unsigned)i_data->public_struct->commands->reg_num[(int)param_num],
			REG_LENG);
	return (REG_LENG);
}

int		i_write_dir(size_t field_idx, t_i_data *i_data, char dir_size,
						char param_num)
{
	if (i_data->public_struct->commands->dir_label[(int)param_num] == 0)
		i_write_params(&i_data->champ_byte_code[(int)field_idx],
			i_data->public_struct->commands->dir_value[(int)param_num].number,
			dir_size);
	else if (i_data->public_struct->commands->dir_label[(int)param_num] == 1)
		i_data->public_struct->commands->label_insert_index[(int)param_num] =
				field_idx;
	else
		return (0);
	return (dir_size);
}

int		i_write_ind(size_t field_idx, t_i_data *i_data, char dir_size,
						char param_num)
{
	dir_size++;
	if (i_data->public_struct->commands->ind_label[(int)param_num] == 0)
		i_write_params(&i_data->champ_byte_code[(int)field_idx],
			i_data->public_struct->commands->ind_value[(int)param_num].number,
			IND_LENG);
	else if (i_data->public_struct->commands->ind_label[(int)param_num] == 1)
		i_data->public_struct->commands->label_insert_index[(int)param_num] =
				field_idx;
	else
		return (0);
	return (IND_LENG);
}
