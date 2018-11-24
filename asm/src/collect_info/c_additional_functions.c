/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_additional_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlewando <dlewando@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:46:32 by dlewando          #+#    #+#             */
/*   Updated: 2018/11/20 10:49:27 by dlewando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/collect_info.h"

int		c_is_whtsp_bf_chr(const char *str, char chr)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != chr)
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] ==
		'\f' || str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*c_get_str_before_chr(const char *str, char chr)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != chr)
		i++;
	new_str = (char *)ft_memalloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != chr)
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

char	*c_get_str_after_chr(char **str, char chr)
{
	int		i;
	int		len;
	int		k;
	char	*new_str;

	i = 0;
	len = 0;
	while ((*str)[i] != chr)
		i++;
	i++;
	k = i;
	while ((*str)[i] != '\0')
		i++ && len++;
	new_str = (char *)ft_memalloc(sizeof(char) * (len + 1));
	i = 0;
	while ((*str)[k] != '\0')
	{
		new_str[i] = (*str)[k];
		i++;
		k++;
	}
	new_str[i] = '\0';
	free(*str);
	return (new_str);
}
