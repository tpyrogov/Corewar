/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_is_need_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:20:16 by achernys          #+#    #+#             */
/*   Updated: 2018/11/20 15:20:16 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

char	i_is_need_write(t_commands *commands)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (commands->dir_label[i] == 1 || commands->ind_label[i] == 1)
			return (1);
		i++;
	}
	return (0);
}
