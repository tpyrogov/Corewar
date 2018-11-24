/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:37:06 by achernys          #+#    #+#             */
/*   Updated: 2018/11/07 15:37:06 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/interpretation.h"

static t_labels	*get_label_with_next_command(t_commands *commands)
{
	while (commands != 0)
	{
		if (commands->label_pointer != 0)
			return (commands->label_pointer);
		commands = commands->next;
	}
	return (0);
}

void			i_add_index_label(t_commands *commands)
{
	t_labels	*first_label;
	t_labels	*next_label_with_command;

	first_label = commands->label_pointer;
	next_label_with_command = get_label_with_next_command(commands->next);
	while (commands->label_pointer != 0 &&
			commands->label_pointer != next_label_with_command)
	{
		commands->label_pointer->index = commands->command_place;
		commands->label_pointer = commands->label_pointer->next;
	}
	commands->label_pointer = first_label;
}
