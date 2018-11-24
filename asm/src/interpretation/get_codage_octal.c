/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_codage_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achernys <achernys@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:55:45 by achernys          #+#    #+#             */
/*   Updated: 2018/11/07 15:56:07 by achernys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/interpretation.h"

unsigned char	i_get_codage_octal(t_commands *commands)
{
	unsigned char	codage_octal;

	codage_octal = 0;
	codage_octal = (codage_octal + commands->opt[0]) << 2;
	codage_octal += commands->opt[1];
	codage_octal <<= 2;
	codage_octal += commands->opt[2];
	codage_octal <<= 2;
	return (codage_octal);
}
