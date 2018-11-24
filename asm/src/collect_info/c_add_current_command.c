/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_add.current_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <dlewando@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:17:53 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/20 10:20:24 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/collect_info.h"

int		c_skip_info(t_i_collect_info *collect_info, char *buff,
					int *comas_counter)
{
	while (buff[collect_info->i] != ',' && buff[collect_info->i] !=
										'\0')
		collect_info->i++;
	if (buff[collect_info->i] == '\0')
		return (1);
	collect_info->i++;
	while (ft_isspace(buff[collect_info->i]) == 1)
		collect_info->i++;
	(*comas_counter)++;
	return (0);
}

int		c_get_options(char **buff, int *comas_counter,
		t_i_collect_info *collect_info, t_public_struct *public_struct)
{
	if (*comas_counter == 3)
		return (1);
	if ((*buff)[collect_info->i] == 'r')
	{
		c_get_reg(public_struct, (*buff), collect_info->i, *comas_counter);
		if (c_skip_info(collect_info, (*buff), comas_counter) == 1)
			return (1);
		return (2);
	}
	else if ((*buff)[collect_info->i] == '%')
	{
		c_get_dir(public_struct, (*buff), collect_info->i, *comas_counter);
		if (c_skip_info(collect_info, (*buff), comas_counter) == 1)
			return (1);
		return (2);
	}
	else if ((*buff)[collect_info->i] == ':' || ft_isdigit(
			(*buff)[collect_info->i]) == 1 || (*buff)[collect_info->i] == '-')
	{
		c_get_ind(public_struct, (*buff), collect_info->i, *comas_counter);
		if (c_skip_info(collect_info, (*buff), comas_counter) == 1)
			return (1);
		return (2);
	}
	return (0);
}

void	c_add_current_command(t_public_struct *public_struct,
							char *buff, t_i_collect_info *collect_info)
{
	int comas_counter;

	comas_counter = 0;
	collect_info->i = 0;
	c_add_command(public_struct, c_command_in_string(buff,
			collect_info));
	collect_info->i = 0;
	while (ft_isspace(buff[collect_info->i]) == 0)
		collect_info->i++;
	while (ft_isspace(buff[collect_info->i]) == 1)
		collect_info->i++;
	while (buff[collect_info->i] != '\0')
	{
		if (c_get_options(&buff, &comas_counter, collect_info, public_struct)
			== 1)
			break ;
		else
			continue ;
	}
}
