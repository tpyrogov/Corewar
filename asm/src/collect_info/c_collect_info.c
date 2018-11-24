/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_collect_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <dlewando@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:05:01 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/20 14:35:09 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"
#include "../../inc/interpretation.h"
#include "../../inc/collect_info.h"

void	c_collect_info(t_public_struct *public_struct,
					t_i_collect_info **collect_info)
{
	*collect_info = c_collect_info_init(*collect_info);
	c_get_name_and_comment(*collect_info, public_struct->fd);
	c_get_commands_and_labels(public_struct, *collect_info);
	c_link_labels(public_struct, *collect_info);
	ft_strcpy(public_struct->header.prog_name, (*collect_info)->name);
	ft_strcpy(public_struct->header.comment, (*collect_info)->comment);
}
