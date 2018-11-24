/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:55:39 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/21 16:52:56 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

t_v_cmd			g_cmd[16] =
{
	{"live", 1, {1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
	{"ld", 2, {1, -1, -1}, {1, -1, -1}, {-1, 1, -1}},
	{"st", 2, {-1, -1, -1}, {-1, 1, -1}, {1, 1, -1}},
	{"add", 3, {-1, -1, -1}, {-1, -1, -1}, {1, 1, 1}},
	{"sub", 3, {-1, -1, -1}, {-1, -1, -1}, {1, 1, 1}},
	{"and", 3, {1, 1, -1}, {1, 1, -1}, {1, 1, 1}},
	{"or", 3, {1, 1, -1}, {1, 1, -1}, {1, 1, 1}},
	{"xor", 3, {1, 1, -1}, {1, 1, -1}, {1, 1, 1}},
	{"zjmp", 1, {1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
	{"ldi", 3, {1, 1, -1}, {1, -1, -1}, {1, 1, 1}},
	{"sti", 3, {-1, 1, 1}, {-1, 1, -1}, {1, 1, 1}},
	{"fork", 1, {1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
	{"lld", 2, {1, -1, -1}, {1, -1, -1}, {-1, 1, -1}},
	{"lldi", 3, {1, 1, -1}, {1, -1, -1}, {1, 1, 1}},
	{"lfork", 1, {1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}},
	{"aff", 1, {-1, -1, -1}, {-1, -1, -1}, {1, -1, -1}},
};

t_v_validation	*v_init_validation(char *s)
{
	t_v_validation *validation;

	validation = (t_v_validation *)malloc(sizeof(t_v_validation));
	validation->buff = NULL;
	validation->type = NULL;
	validation->file_name = ft_strdup(s);
	validation->x_curs = 0;
	validation->y_curs = 0;
	validation->name_checked = 0;
	validation->comment_checked = 0;
	validation->labels = NULL;
	validation->fd = -1;
	validation->cur_cmd = -1;
	return (validation);
}

t_labels		*v_init_label(char *name_label, int index)
{
	t_labels	*label;

	label = (t_labels *)malloc(sizeof(t_labels));
	label->name = ft_strdup(name_label);
	label->index = (size_t)index;
	label->next = NULL;
	return (label);
}

size_t			v_count_label_size(char *s)
{
	size_t i;

	i = 0;
	while (ft_isspace(s[i]) != 1 && s[i] != '\0'
	&& s[i] != SEPARATOR_CHAR && s[i] != LABEL_CHAR)
		i++;
	i++;
	return (i);
}
