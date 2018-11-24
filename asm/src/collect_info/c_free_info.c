/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_free_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <dlewando@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:56:45 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/20 17:49:49 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"
#include "../../inc/interpretation.h"
#include "../../inc/collect_info.h"

void	free_collect_info(t_i_collect_info *collect_info)
{
	int i;

	i = 0;
	free(collect_info->name);
	free(collect_info->comment);
	while (i <= 15)
	{
		free(collect_info->commands_names[i]);
		i++;
	}
	free(collect_info->commands_names);
	free(collect_info);
}

void	c_free_labels(t_labels *labels)
{
	if (labels == NULL)
		return ;
	c_free_labels(labels->next);
	free(labels->name);
	free(labels);
}

void	free_commands(t_commands *commands)
{
	if (commands == NULL)
		return ;
	free_commands(commands->next);
	free(commands);
}

void	free_public_struct(t_public_struct *public_struct)
{
	c_free_labels(public_struct->labels);
	free_commands(public_struct->commands);
	free(public_struct);
}
