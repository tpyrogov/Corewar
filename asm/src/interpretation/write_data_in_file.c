/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_data_in_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:11:09 by achernys          #+#    #+#             */
/*   Updated: 2018/11/20 18:18:59 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/interpretation.h"

ssize_t	i_write_data_in_file(t_i_data *i_data, size_t champ_size)
{
	ssize_t	writed_bytes;
	ssize_t out;

	if ((writed_bytes = write(i_data->fd, i_data->header_code,
			HEADER_CODE_SIZE)) < (ssize_t)HEADER_CODE_SIZE)
		exit(WRITE_ERR);
	if (champ_size == 0)
		return (writed_bytes);
	if ((out = write(i_data->fd, i_data->champ_byte_code, (size_t)champ_size)) <
			(ssize_t)champ_size)
		exit(WRITE_ERR);
	writed_bytes += out;
	return (writed_bytes);
}
