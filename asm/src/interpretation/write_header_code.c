/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header_code.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:19:14 by achernys          #+#    #+#             */
/*   Updated: 2018/11/20 15:22:27 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/interpretation.h"
#define WRITE_NAME 0
#define WRITE_COMMENT 1

static int	i_write_name_and_cmt(t_i_data *i_data, int idx, char lable)
{
	char	*str;
	int		i;

	if (lable == 0)
		str = i_data->public_struct->header.prog_name;
	else if (lable == 1)
		str = i_data->public_struct->header.comment;
	else
		exit(UNDEFINE_ERR);
	i = 0;
	while (str[i] != 0)
	{
		i_write_params(&i_data->header_code[idx], (unsigned)str[i], 1);
		i++;
		idx++;
	}
	return (i);
}

void		i_write_header_code(t_i_data *i_data, size_t bot_size)
{
	int		idx;

	idx = 4;
	i_write_params(i_data->header_code, COREWAR_EXEC_MAGIC, 4);
	i_write_name_and_cmt(i_data, idx, WRITE_NAME);
	idx = PROG_NAME_LENGTH + 8;
	i_write_params(&i_data->header_code[idx], (unsigned)bot_size, 4);
	idx += 4;
	i_write_name_and_cmt(i_data, idx, WRITE_COMMENT);
}
