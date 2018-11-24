/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:54:36 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/24 14:38:15 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

char	*v_get_string(t_v_validation *valid, char c)
{
	char	*s;
	size_t	i;
	size_t	size;

	i = 0;
	v_pass_whitespaces(valid);
	if (c == ' ')
		size = ft_strchr(valid->buff, c) - (valid->buff + valid->x_curs);
	else if (c == ':')
		size = v_count_label_size(valid->buff + valid->x_curs);
	else
		size = v_count_size(valid->buff + valid->x_curs);
	s = ft_strnew(size + 1);
	while (i < size)
	{
		s[i] = valid->buff[valid->x_curs + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	v_cut_comment(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == COMMENT_CHAR
		|| s[i] == ';')
		{
			s[i] = '\0';
			return ;
		}
		i++;
	}
}

void	v_get_error_string(t_v_validation *valid)
{
	char	*s;
	size_t	size;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (valid->buff != NULL)
	{
		size = v_count_size(valid->buff + valid->x_curs) + 1;
		s = ft_strnew(size + 1);
		while (i < size - 1)
		{
			if (valid->buff[valid->x_curs + i] == DIRECT_CHAR
				|| valid->buff[valid->x_curs + i] == LABEL_CHAR)
				j--;
			else
				s[j] = valid->buff[valid->x_curs + i];
			i++;
			j++;
		}
		s[j] = '\0';
		ft_strdel(&valid->buff);
		valid->buff = s;
	}
}

int		v_is_digit_arg(char *valid, int sign)
{
	int i;

	i = 0;
	if (sign == 1 && valid[i] == '-')
	{
		i++;
		if (ft_isdigit(valid[i]) == 0)
			return (i);
	}
	while (ft_isdigit(valid[i]) == 1)
		i++;
	if (i == 0 || (i == 1 && (ft_isspace(valid[i]) != 1
	&& valid[i] != SEPARATOR_CHAR && valid[i] != '\0'))
	|| (ft_isspace(valid[i]) != 1
	&& valid[i] != SEPARATOR_CHAR && valid[i] != '\0'))
	{
		if (i == 0)
			return (i);
		else
			return (i + 1);
	}
	return (-1);
}

void	v_return_to_command_star(t_v_validation *valid, int read)
{
	int i;

	lseek(valid->fd, 0, 0);
	i = 0;
	while (i < read && get_next_line(valid->fd, &valid->buff) > 0)
	{
		ft_strdel(&valid->buff);
		i++;
	}
}
