/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpritation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 03:36:40 by achernys          #+#    #+#             */
/*   Updated: 2018/11/23 18:00:17 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/interpretation.h"

char	*i_get_file_name(char *s_file)
{
	char	*tmp;
	char	*file_name;
	size_t	i;
	size_t	start_i;

	tmp = ft_strdup(s_file);
	i = 0;
	start_i = 0;
	while (tmp[i] != 0)
	{
		i++;
		if (tmp[i] == '/')
			start_i = i;
	}
	i = start_i != 0 ? start_i + 1 : 0;
	while (tmp[i] != 0 && tmp[i] != '.')
		i++;
	if (tmp[i] == 0)
		exit(FILE_NAME_ERR);
	tmp[i] = 0;
	file_name = ft_strnew(i + 3);
	ft_strcpy(file_name, tmp);
	ft_strcpy(&file_name[i], ".cor");
	free((void *)tmp);
	return (file_name);
}

int		i_write_commands(t_i_data *i_data)
{
	t_reserved_words reserved_words;

	reserved_words = i_data->public_struct->commands->reserved_words;
	if (reserved_words == 0)
		return (0);
	if (reserved_words == 1)
		return (i_write_cmd_without_codage(i_data, DIR_LENG));
	else if (reserved_words == 9 || reserved_words == 12)
		return (i_write_cmd_without_codage(i_data, DIR_LENG - 2));
	else if (reserved_words == 10 || reserved_words == 11 ||
				reserved_words == 14)
		return (i_write_cmd_with_codage(i_data, DIR_LENG - 2));
	else
		return (i_write_cmd_with_codage(i_data, DIR_LENG));
}

size_t	i_write_command_without_label(t_i_data *i_data)
{
	t_commands	*start_command;
	size_t		index;
	size_t		multiplier;

	index = 0;
	multiplier = 1;
	start_command = i_data->public_struct->commands;
	while (i_data->public_struct->commands != 0)
	{
		i_data->public_struct->commands->command_place = index;
		i_add_index_label(i_data->public_struct->commands);
		i_data->champ_byte_code[
				i_data->public_struct->commands->command_place] =
						i_data->public_struct->commands->reserved_words;
		if (index + 11 > CHAMP_MAX_SIZE * multiplier)
			resize_champ_mem(i_data, index, ++multiplier);
		index += i_write_commands(i_data);
		i_data->public_struct->commands = i_data->public_struct->commands->next;
	}
	i_data->public_struct->commands = start_command;
	return (index);
}

void	i_write_missing_params(t_i_data *i_data)
{
	t_commands	*start_command;

	start_command = i_data->public_struct->commands;
	while (i_data->public_struct->commands != 0)
	{
		if (i_is_need_write(i_data->public_struct->commands))
			i_write_data(i_data->public_struct->commands,
							i_data->champ_byte_code);
		i_data->public_struct->commands = i_data->public_struct->commands->next;
	}
	i_data->public_struct->commands = start_command;
}

void	interpretation(t_public_struct *public_struct)
{
	t_i_data	*i_data;
	char		*file_name;
	size_t		champ_size;

	i_data = i_init_i_data(public_struct);
	champ_size = i_write_command_without_label(i_data);
	i_write_missing_params(i_data);
	i_write_header_code(i_data, champ_size);
	file_name = i_get_file_name(public_struct->file_name);
	if ((i_data->fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC)) == -1)
		exit(CREATE_FILE_ERR);
	i_write_data_in_file(i_data, champ_size);
	ft_printf("{green}Writing output program to %s{eoc}\n", file_name);
	free((void *)file_name);
	close(i_data->fd);
	free((void *)i_data->champ_byte_code);
	free((void *)i_data);
}
