/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_read_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:09:04 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/16 19:22:12 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/collect_info.h"

static int	c_first_part(t_i_collect_info **(collect_info), int *(i))
{
	while ((*collect_info)->buff[(*i)] != '\"')
		(*i)++;
	(*i)++;
	if ((*collect_info)->buff[(*i)] == '\"')
	{
		*(*collect_info)->name = '\0';
		free((*collect_info)->buff);
		return (1);
	}
	while ((*collect_info)->buff[(*i)] != '\0')
	{
		(*collect_info)->name[(*collect_info)->i++] =
				(*collect_info)->buff[(*i)++];
		if ((*collect_info)->buff[(*i)] == '\"')
		{
			(*collect_info)->name[(*collect_info)->i] = '\0';
			free((*collect_info)->buff);
			return (1);
		}
	}
	return (0);
}

void		c_read_name(t_i_collect_info *collect_info, int fd)
{
	int i;

	i = 0;
	collect_info->i = 0;
	if (c_first_part(&collect_info, &i) == 1)
		return ;
	while (1)
	{
		free(collect_info->buff);
		collect_info->name[collect_info->i++] = '\n';
		get_next_line(fd, &collect_info->buff);
		if ((ft_strchr(collect_info->buff, '"') != NULL))
			break ;
		collect_info->name = ft_strcat(collect_info->name, collect_info->buff);
		collect_info->i += ft_strlen(collect_info->buff);
	}
	i = 0;
	while (collect_info->buff[i] != '\"')
		collect_info->name[collect_info->i++] = collect_info->buff[i++];
	collect_info->name[collect_info->i] = '\0';
	free(collect_info->buff);
}
