/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_get_reg_dir_ind.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:49:22 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/22 19:44:55 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/collect_info.h"

void	c_get_reg(t_public_struct *public_struct, char *buff, int i,
		int commas_counter)
{
	t_commands *tmp;

	tmp = public_struct->commands;
	while (public_struct->commands->next != 0)
		public_struct->commands = public_struct->commands->next;
	public_struct->commands->reg_num[commas_counter] =
			(char)ft_atoi(buff + i + 1);
	public_struct->commands->opt[commas_counter] = 1;
	public_struct->commands = tmp;
}

char	*get_dir_ind_name(const char *buff, int i)
{
	char	*name;
	int		k;
	int		l;
	char	*tmp;

	k = 0;
	l = i;
	while (buff[i] != ',' && buff[i] != '\0')
	{
		k++;
		i++;
	}
	name = (char *)ft_memalloc(sizeof(char) * (k + 1));
	k = 0;
	while (l < i)
	{
		name[k] = buff[l];
		l++;
		k++;
	}
	name[k] = '\0';
	tmp = ft_strtrim(name);
	free(name);
	return (tmp);
}

void	c_get_dir(t_public_struct *public_struct, const char *buff, int i,
		int commas_counter)
{
	t_commands *tmp;

	tmp = public_struct->commands;
	while (public_struct->commands->next != 0)
		public_struct->commands = public_struct->commands->next;
	if (buff[i + 1] == ':')
	{
		public_struct->commands->dir_label[commas_counter] = 1;
		public_struct->commands->dir_value[commas_counter].str_name =
				get_dir_ind_name(buff, i + 2);
	}
	else
	{
		public_struct->commands->dir_label[commas_counter] = 0;
		public_struct->commands->dir_value[commas_counter].number = (unsigned)
				ft_atoi((char *)buff + i + 1);
	}
	public_struct->commands->opt[commas_counter] = 2;
	public_struct->commands = tmp;
}

void	c_get_ind(t_public_struct *public_struct, const char *buff, int i,
		int commas_counter)
{
	t_commands *tmp;

	tmp = public_struct->commands;
	while (public_struct->commands->next != 0)
		public_struct->commands = public_struct->commands->next;
	if (buff[i] == ':')
	{
		public_struct->commands->ind_label[commas_counter] = 1;
		public_struct->commands->ind_value[commas_counter].str_name =
				get_dir_ind_name(buff, i + 1);
	}
	else
	{
		public_struct->commands->dir_label[commas_counter] = 0;
		public_struct->commands->ind_value[commas_counter].number = (unsigned)
				ft_atoi((char *)buff + i);
	}
	public_struct->commands->opt[commas_counter] = 3;
	public_struct->commands = tmp;
}
