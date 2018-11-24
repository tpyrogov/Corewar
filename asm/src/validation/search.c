/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:56:17 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/23 21:57:01 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

size_t	v_find_label(t_v_validation *valid, char *s)
{
	t_labels	*cur;
	size_t		cur_size;

	cur = valid->labels;
	while (cur != NULL)
	{
		cur_size = v_count_size(cur->name);
		if (ft_strncmp(s, cur->name, cur_size - 1) == 0
		&& (ft_isspace(s[cur_size - 1]) == 1
		|| s[cur_size - 1] == '\0' || s[cur_size - 1] == SEPARATOR_CHAR))
			return (ft_strlen(cur->name));
		cur = cur->next;
	}
	return (0);
}

void	v_pass_whitespaces(t_v_validation *valid)
{
	while (ft_isspace(valid->buff[valid->x_curs]) == 1
		&& valid->buff[valid->x_curs] != '\0')
		valid->x_curs++;
}

size_t	v_count_size(char *s)
{
	size_t i;

	i = 0;
	while (ft_isspace(s[i]) != 1 && s[i] != '\0'
	&& s[i] != SEPARATOR_CHAR && s[i] != '"')
		i++;
	return (i);
}

char	v_ft_is_whitespace_line(const char *str)
{
	size_t i;

	if (str == 0)
		return (0);
	if (*str == '\0')
		return (1);
	i = 0;
	while (str[i] != 0)
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	v_miss_empty_lines(t_v_validation *valid)
{
	while (v_ft_is_whitespace_line(valid->buff) == 1)
	{
		if (v_ft_is_whitespace_line(valid->buff) == 1)
			ft_strdel(&valid->buff);
		else if (ft_strchr(valid->buff, COMMENT_CHAR) != NULL)
		{
			v_cut_comment(valid->buff);
			if (v_ft_is_whitespace_line(valid->buff) != 1)
				return ;
			ft_strdel(&valid->buff);
		}
		else
			return ;
		valid->x_curs = 0;
		valid->y_curs++;
		get_next_line(valid->fd, &valid->buff);
	}
}
