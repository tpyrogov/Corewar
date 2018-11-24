/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_link_labels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <dlewando@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 20:10:14 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/20 10:51:15 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/collect_info.h"

t_labels	*c_return_tmp_label(t_labels *labels)
{
	t_labels *tmp;

	tmp = labels;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_labels	*c_return_label_pointer(t_labels *labels, char *str)
{
	t_labels *tmp;

	tmp = labels;
	while (tmp != NULL)
	{
		if (tmp->name != NULL && ft_strcmp(tmp->name, (str)) == 0)
		{
			free(str);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (0);
}

void		c_link_labels(t_public_struct *public_struct,
		t_i_collect_info *collect_info)
{
	t_commands *tmp;

	tmp = public_struct->commands;
	collect_info->i = 0;
	while (tmp != NULL)
	{
		collect_info->i = 0;
		while (collect_info->i < 3)
		{
			if (tmp->dir_label[collect_info->i] == 1)
				tmp->dir_value[collect_info->i].labels =
						c_return_label_pointer(public_struct->labels,
							(tmp->dir_value[collect_info->i].str_name));
			else if (collect_info->i < 2 && tmp->ind_label[collect_info->i]
											== 1)
				tmp->ind_value[collect_info->i].labels =
						c_return_label_pointer(public_struct->labels,
							(tmp->ind_value[collect_info->i].str_name));
			collect_info->i++;
		}
		tmp = tmp->next;
	}
}
