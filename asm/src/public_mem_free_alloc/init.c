/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 03:53:38 by achernys          #+#    #+#             */
/*   Updated: 2018/11/07 04:44:20 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

t_labels		*init_label(char *name_label, int index)
{
	t_labels	*label;

	label = (t_labels *)malloc(sizeof(t_labels));
	label->name = ft_strdup(name_label);
	label->index = index;
	label->next = NULL;
	return (label);
}

void			init_header(t_public_struct *public_struct)
{
	public_struct->header.magic = COREWAR_EXEC_MAGIC;
	public_struct->header.prog_size = 0;
	ft_bzero(public_struct->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(public_struct->header.comment, COMMENT_LENGTH + 1);
}

t_public_struct	*init_public_struct(char *file_name)
{
	t_public_struct *public_struct;

	public_struct = (t_public_struct *)malloc(sizeof(t_public_struct));
	public_struct->commands = 0;
	public_struct->labels = 0;
	init_header(public_struct);
	public_struct->file_name = file_name;
	return (public_struct);
}
