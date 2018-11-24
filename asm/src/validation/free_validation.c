/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:48:56 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/22 15:53:43 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

void	v_free_labels(t_v_validation *valid)
{
	t_labels *cur;
	t_labels *next;

	cur = valid->labels;
	while (cur != NULL)
	{
		next = cur->next;
		ft_strdel(&cur->name);
		free(cur);
		cur = next;
	}
}

void	v_free_validation(t_v_validation *valid)
{
	if (valid->type != NULL)
		ft_strdel(&valid->type);
	if (valid->buff != NULL)
		ft_strdel(&valid->buff);
	if (valid->file_name)
		ft_strdel(&valid->file_name);
	if (valid->labels != NULL)
		v_free_labels(valid);
	free(valid);
}
