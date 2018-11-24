/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_initialization.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <dlewando@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:50:04 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/20 10:50:30 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/collect_info.h"

t_labels			*c_init_label(char *name_label, int index)
{
	t_labels	*label;

	label = (t_labels *)ft_memalloc(sizeof(t_labels));
	label->name = (char *)ft_memalloc(sizeof(char) * (ft_strlen(name_label) +
			1));
	ft_strcpy(label->name, name_label);
	label->index = index;
	label->next = NULL;
	return (label);
}

t_commands			*c_init_command(int command)
{
	t_commands	*label;

	label = (t_commands *)ft_memalloc(sizeof(t_commands));
	label->reserved_words = command;
	label->next = NULL;
	return (label);
}

t_i_collect_info	*c_collect_info_init(t_i_collect_info *collect_info)
{
	collect_info = (t_i_collect_info *)ft_memalloc(sizeof(t_i_collect_info));
	collect_info->name = (char *)ft_memalloc(sizeof(char) * PROG_NAME_LENGTH
			+ 1);
	collect_info->comment = (char *)ft_memalloc(sizeof(char) * COMMENT_LENGTH
			+ 1);
	collect_info->commands_names = ft_strsplit(
	"live ld st add sub and or xor zjmp ldi sti fork lld lldi lfork aff", ' ');
	return (collect_info);
}
