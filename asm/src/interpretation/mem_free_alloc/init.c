/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 04:19:58 by achernys          #+#    #+#             */
/*   Updated: 2018/11/20 15:21:18 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/interpretation.h"

void		i_init_write_param_func_arr(t_i_data *i_data)
{
	i_data->write_param_value_arr[0] = &i_write_register;
	i_data->write_param_value_arr[1] = &i_write_dir;
	i_data->write_param_value_arr[2] = &i_write_ind;
}

t_i_data	*i_init_i_data(t_public_struct *public_struct)
{
	t_i_data *i_data;

	i_data = (t_i_data *)ft_memalloc(sizeof(t_i_data));
	i_data->fd = -1;
	i_data->public_struct = public_struct;
	ft_bzero(i_data->header_code, HEADER_CODE_SIZE);
	i_data->champ_byte_code = (unsigned char *)ft_memalloc(CHAMP_MAX_SIZE);
	i_init_write_param_func_arr(i_data);
	return (i_data);
}
