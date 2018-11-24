/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_miss_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:07:21 by achernys          #+#    #+#             */
/*   Updated: 2018/11/20 17:06:32 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/interpretation.h"

static void	i_write_miss_dir(t_commands *commands, unsigned char *field_champ,
								size_t i)
{
	if (commands->dir_label[i] == 1)
	{
		if ((commands->reserved_words > 8 &&
			commands->reserved_words < 13) ||
			commands->reserved_words == 14 ||
			commands->reserved_words == 15)
			i_write_params(&field_champ[commands->label_insert_index[i]],
							(unsigned)(commands->dir_value[i].labels->index -
							commands->command_place), DIR_LENG - 2);
		else
			i_write_params(&field_champ[commands->label_insert_index[i]],
							(unsigned)(commands->dir_value[i].labels->index -
							commands->command_place), DIR_LENG);
	}
	if (i < 2 && commands->ind_label[i] == 1)
	{
		i_write_params(&field_champ[commands->label_insert_index[i]],
							(unsigned)(commands->ind_value[i].labels->index -
							commands->command_place), IND_LENG);
	}
}

void		i_write_data(t_commands *commands, unsigned char *field_champ)
{
	size_t	i;

	i = 0;
	while (i < 3)
	{
		if (commands->dir_label[i] == 1)
			i_write_miss_dir(commands, field_champ, i);
		if (i < 2 && commands->ind_label[i] == 1)
		{
			i_write_params(&field_champ[commands->label_insert_index[i]],
							(unsigned)(commands->ind_value[i].labels->index -
							commands->command_place), IND_LENG);
		}
		i++;
	}
}
