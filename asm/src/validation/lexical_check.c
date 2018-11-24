/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:56:06 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/23 21:03:58 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

int		v_is_dir_label(t_v_validation *valid, size_t size)
{
	int	i;

	i = 0;
	if (valid->buff[valid->x_curs] == DIRECT_CHAR)
	{
		if ((valid->buff[valid->x_curs + 1] != LABEL_CHAR
		&& (i = v_is_digit_arg(valid->buff + valid->x_curs + 1, 1)) != -1)
		&& valid->buff[valid->x_curs + 1] != LABEL_CHAR)
		{
			valid->x_curs += i;
			return (LEXICAL);
		}
		if (v_is_digit_arg(valid->buff + valid->x_curs + 1, 1) == -1)
			return (1);
		if (v_is_label_chars(valid,
				valid->buff + valid->x_curs + 2, size - 2) != 1)
		{
			valid->x_curs += 2;
			return (LEXICAL);
		}
		if (v_find_label(valid, valid->buff + valid->x_curs + 2) == 0)
			return (DIRECT_LABEL);
		return (1);
	}
	return (-1);
}

int		v_is_label(t_v_validation *valid)
{
	int i;

	i = 0;
	while (ft_isspace(valid->buff[valid->x_curs + i]) != 1
	&& valid->buff[valid->x_curs + i] != ':'
	&& valid->buff[valid->x_curs + i] != '\0')
	{
		if (ft_strchr(LABEL_CHARS, valid->buff[valid->x_curs + i]) == NULL
		&& valid->buff[valid->x_curs + i] != ':')
			return (LEXICAL);
		i++;
	}
	if (valid->buff[valid->x_curs + i] != ':')
		return (SYNTAX_INSTRUCT);
	return (1);
}

int		v_is_reg(t_v_validation *valid)
{
	int num;

	if (*(valid->buff + valid->x_curs) == 'r')
	{
		if (v_count_size(valid->buff + valid->x_curs) > 3)
			return (SYNTAX_INSTRUCT);
		if ((num = v_is_digit_arg(valid->buff + valid->x_curs + 1, 0)) == -1)
			num = ft_atoi(valid->buff + valid->x_curs + 1);
		else
		{
			valid->x_curs += num;
			return (LEXICAL);
		}
		if (num < 0 || num >= 100)
			return (SYNTAX_INSTRUCT);
		return (1);
	}
	return (-1);
}

int		v_is_ind(t_v_validation *valid, size_t size)
{
	if (valid->buff[valid->x_curs] == LABEL_CHAR)
	{
		if (v_is_label_chars(valid,
				valid->buff + valid->x_curs + 1, size - 1) != 1)
		{
			valid->x_curs++;
			return (LEXICAL);
		}
		if (v_find_label(valid, valid->buff + valid->x_curs + 1) == 0)
			return (DIRECT_LABEL);
		return (1);
	}
	else if (v_is_digit_arg(valid->buff + valid->x_curs, 1) != -1)
		return (-1);
	return (1);
}
