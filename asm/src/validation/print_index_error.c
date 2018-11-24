/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_index_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpyrogov <tpyrogov@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:36:41 by tpyrogov          #+#    #+#             */
/*   Updated: 2018/11/23 17:37:50 by tpyrogov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/validation.h"

static int	count_symb_in_string(const char *str, char chr)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			result++;
		i++;
	}
	return (result);
}

static int	add_space(char *str, int j, int i)
{
	int k;
	int k_end;

	k = 0;
	if ((i + 1) % 4 == 0)
		k_end = 1;
	else if ((i + 1) % 4 == 2)
		k_end = 3;
	else if ((i + 1) % 4 == 1)
		k_end = 4;
	else
		k_end = 2;
	while (k < k_end)
	{
		str[j + k] = ' ';
		k++;
	}
	return (k);
}

static int	return_add_index(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
		{
			if ((i + 1) % 4 == 1)
				j += 3;
			if ((i + 1) % 4 == 2)
				j += 2;
			if ((i + 1) % 4 == 3)
				j += 1;
		}
		i++;
	}
	return (j);
}

void		v_print_index_error(char *str, int index)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	line = (char *)malloc(sizeof(char) *
		(ft_strlen(str) + 4 * count_symb_in_string(str, '\t') + 1));
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			j += add_space(line, j, i);
		else
		{
			line[j] = str[i];
			j++;
		}
		i++;
	}
	line[j] = '\0';
	ft_printf("%s\n", line);
	ft_printf("\033[%dC", index + return_add_index(str));
	ft_printf("{red}^{eoc}\n");
	free(line);
}
