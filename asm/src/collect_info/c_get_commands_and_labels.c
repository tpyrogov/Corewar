/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_get_commands_and_labels.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <dlewando@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 03:53:25 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/20 17:55:28 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/collect_info.h"

int		c_if_label(char **buff, t_labels **tmp_label,
		t_public_struct *public_struct, int *label_add)
{
	char *tmp;

	tmp = c_get_str_before_chr((*buff), ':');
	c_add_label(public_struct, tmp, -1);
	free(tmp);
	(*buff) = c_get_str_after_chr(buff, ':');
	tmp = ft_strtrim((*buff));
	free((*buff));
	(*buff) = tmp;
	if (*label_add == 0)
		*tmp_label = c_return_tmp_label(public_struct->labels);
	*label_add = 1;
	if (buff[0] == '\0')
	{
		free(*buff);
		return (1);
	}
	return (0);
}

void	if_final_label(int label_add, t_public_struct *public_struct,
		t_labels *tmp_label)
{
	if (label_add == 1)
	{
		c_add_command(public_struct, 0);
		c_add_label_pointer(public_struct, tmp_label);
	}
}

int		first_buf_validation(t_i_collect_info *collect_info, char **buff)
{
	cut_comment(&collect_info->buff);
	(*buff) = ft_strtrim(collect_info->buff);
	if (ft_strncmp(*buff, ".name", 5) == 0 ||
		ft_strncmp(*buff, ".comment", 8) == 0)
	{
		free(*buff);
		free(collect_info->buff);
		return (2);
	}
	free(collect_info->buff);
	if ((*buff)[0] == '\0')
	{
		free((*buff));
		return (1);
	}
	return (0);
}

void	if_label_exist(int label_add, t_public_struct *public_struct,
		t_labels *tmp_label)
{
	if (label_add == 1)
		c_add_label_pointer(public_struct, tmp_label);
}

void	c_get_commands_and_labels(t_public_struct *public_struct,
								t_i_collect_info *collect_info)
{
	char		*buff;
	int			label_add;
	t_labels	*tmp_label;
	int			func_result;

	collect_info->i = 0;
	label_add = 0;
	while (get_next_line(public_struct->fd, &collect_info->buff))
	{
		if ((func_result = first_buf_validation(collect_info, &buff)) == 1)
			continue ;
		else if (func_result == 2)
			break ;
		if (ft_strchr(buff, ':') != NULL && c_is_whtsp_bf_chr(buff, ':') == 0)
			if (c_if_label(&buff, &tmp_label, public_struct, &label_add) == 1)
				continue ;
		if (c_command_in_string(buff, collect_info) != 0)
		{
			c_add_current_command(public_struct, buff, collect_info);
			if_label_exist(label_add, public_struct, tmp_label);
			label_add = 0;
		}
		free(buff);
	}
	if_final_label(label_add, public_struct, tmp_label);
}
