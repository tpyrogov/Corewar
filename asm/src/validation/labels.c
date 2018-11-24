/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:55:54 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/23 20:33:27 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

void	v_write_label(t_v_validation *valid)
{
	t_labels	*cur;
	char		*str;

	str = v_get_string(valid, LABEL_CHAR);
	if (v_find_label(valid, str) == 0)
	{
		if (valid->labels == NULL)
			valid->labels = v_init_label(str, 0);
		else
		{
			cur = valid->labels;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = v_init_label(str, 0);
		}
	}
	ft_strdel(&str);
}

void	v_check_rest(t_v_validation *valid, int i)
{
	char *temp;

	if ((temp = ft_strchr(valid->buff + valid->x_curs + i + 1, ':')) != NULL
		&& *(temp - 1) != DIRECT_CHAR && (ft_isspace(*(temp + 1)) == 1))
	{
		while (ft_isspace(*temp) != 1 && *temp != SEPARATOR_CHAR)
			temp--;
		valid->x_curs += (temp - (valid->buff + valid->x_curs));
		v_pass_whitespaces(valid);
		v_put_validation_error(SYNTAX_LABEL, valid);
	}
}

int		v_check_label(t_v_validation *valid, size_t size)
{
	size_t	i;

	i = 0;
	v_pass_whitespaces(valid);
	if (size == 1)
		v_put_validation_error(LEXICAL, valid);
	while (valid->x_curs + i < size + valid->x_curs - 1)
	{
		if (ft_strchr(LABEL_CHARS, valid->buff[valid->x_curs + i]) == NULL)
		{
			valid->x_curs += i;
			v_put_validation_error(LEXICAL, valid);
		}
		i++;
	}
	i++;
	v_check_rest(valid, i);
	return (1);
}

void	v_get_labels(t_v_validation *valid, int save_lines)
{
	size_t		size;

	v_return_to_command_star(valid, save_lines);
	while (get_next_line(valid->fd, &valid->buff) > 0)
	{
		if (v_ft_is_whitespace_line(valid->buff))
			v_miss_empty_lines(valid);
		if (valid->buff == NULL)
			break ;
		valid->x_curs = 0;
		v_pass_whitespaces(valid);
		size = v_count_label_size(valid->buff + valid->x_curs);
		if (valid->buff[valid->x_curs + size - 1] == LABEL_CHAR
		&& v_check_label(valid, size) == 1)
			v_write_label(valid);
		valid->y_curs++;
		ft_strdel(&valid->buff);
	}
	valid->y_curs = 0;
	ft_strdel(&valid->buff);
	lseek(valid->fd, 0, 0);
}

int		v_is_label_chars(t_v_validation *valid, char *str, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (ft_strchr(LABEL_CHARS, *(str + i)) == NULL
			&& *(str + i) != SEPARATOR_CHAR)
		{
			valid->x_curs += i;
			return (LEXICAL);
		}
		i++;
	}
	return (1);
}
