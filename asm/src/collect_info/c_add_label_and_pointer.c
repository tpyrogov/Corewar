/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_add_label_and_pointer.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <dlewando@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:05:12 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/20 17:54:15 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/collect_info.h"

void	c_add_label(t_public_struct *public_struct, char *name_label, int index)
{
	t_labels *temp;

	if (public_struct->labels == NULL)
		public_struct->labels = init_label(name_label, index);
	else
	{
		temp = public_struct->labels;
		while (temp->next)
			temp = temp->next;
		temp->next = init_label(name_label, index);
	}
}

void	c_add_command(t_public_struct *public_struct, int command)
{
	t_commands *temp;

	if (public_struct->commands == NULL)
		public_struct->commands = c_init_command(command);
	else
	{
		temp = public_struct->commands;
		while (temp->next)
			temp = temp->next;
		temp->next = c_init_command(command);
	}
}

void	c_add_label_pointer(t_public_struct *public_struct, t_labels *tmp)
{
	t_commands *tmp1;

	tmp1 = (public_struct)->commands;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	tmp1->label_pointer = tmp;
}

void	c_get_name_and_comment(t_i_collect_info *collect_info, int fd)
{
	int label;

	label = 0;
	collect_info->i = 0;
	while (get_next_line(fd, &collect_info->buff))
	{
		cut_comment(&collect_info->buff);
		if (ft_strchr(collect_info->buff, '.') != NULL &&
		ft_strncmp(ft_strchr(collect_info->buff, '.'), ".name", 5) == 0)
		{
			c_read_name(collect_info, fd);
			label += 1;
		}
		else if (ft_strchr(collect_info->buff, '.') != NULL &&
			ft_strncmp(ft_strchr(collect_info->buff, '.'), ".comment", 8) == 0)
		{
			c_read_comment(collect_info, fd);
			label += 1;
		}
		else
			free(collect_info->buff);
		if (label == 2)
			break ;
	}
}

int		c_command_in_string(const char *str, t_i_collect_info *collect_info)
{
	collect_info->i = 15;
	while (collect_info->i >= 0)
	{
		if (ft_strncmp(str, collect_info->commands_names[collect_info->i],
			ft_strlen(collect_info->commands_names[collect_info->i])) == 0)
			return (collect_info->i + 1);
		collect_info->i--;
	}
	return (0);
}
