/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_params_on_field.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:34:40 by achernys          #+#    #+#             */
/*   Updated: 2018/11/07 15:37:02 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/interpretation.h"

void	i_write_params(unsigned char *start_input_field, unsigned int value,
						char size)
{
	unsigned short	hdir;

	if (size == 1)
		start_input_field[0] = (unsigned char)value;
	else if (size == 2)
	{
		hdir = (unsigned short)value;
		start_input_field[0] = (unsigned char)((hdir & 65280) >> 8);
		start_input_field[1] = (unsigned char)(hdir & 255);
	}
	else if (size == 4)
	{
		start_input_field[0] = (unsigned char)((value & 4278190080) >> 24);
		start_input_field[1] = (unsigned char)((value & 16711680) >> 16);
		start_input_field[2] = (unsigned char)((value & 65280) >> 8);
		start_input_field[3] = (unsigned char)(value & 255);
	}
}
