/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_champ_mem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 12:17:00 by achernys          #+#    #+#             */
/*   Updated: 2018/11/20 12:24:39 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/interpretation.h"

void	resize_champ_mem(t_i_data *i_data, size_t index, size_t multiplier)
{
	unsigned char	*new_field;

	new_field = (unsigned char *)ft_memalloc(CHAMP_MAX_SIZE * multiplier);
	ft_memcpy(new_field, i_data->champ_byte_code, index);
	free(i_data->champ_byte_code);
	i_data->champ_byte_code = new_field;
}
